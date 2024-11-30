/**
 * @file serial.cpp
 * @brief Contains functions for initializing and managing serial port communication.
 */

#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include "serial.h"

using namespace std;

HANDLE hSerial;  ///< Handle to the serial port.
DCB dcbSerialParams = { 0 };  ///< Serial port parameters (DCB structure).
COMMTIMEOUTS timeouts = { 0 };  ///< Timeout settings for serial port communication.

/**
 * @brief Converts a std::string to a std::wstring.
 *
 * This helper function converts a narrow character string (std::string) to a wide character
 * string (std::wstring), which is needed for working with the Windows API.
 *
 * @param str The std::string to be converted.
 *
 * @return std::wstring The converted wide character string.
 */
std::wstring stringToWString(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

/**
 * @brief Initializes the serial port with specified settings.
 *
 * This function configures the serial port with the standard settings: 9600 baud rate, 8 data bits,
 * 1 stop bit, and no parity. It also sets timeouts for read and write operations.
 *
 * @param portName The name of the serial port (e.g., "COM3").
 *
 * @throws exit(1) If the port cannot be opened.
 */
void initSerialPort(const std::string& portName) {
    // Convert std::string to std::wstring
    std::wstring widePortName = stringToWString(portName);

    // Use CreateFileW for wide strings
    hSerial = CreateFileW(widePortName.c_str(),
        GENERIC_READ | GENERIC_WRITE,
        0,
        0,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        0);

    if (hSerial == INVALID_HANDLE_VALUE) {
        cerr << "Failed to open port!" << endl;
        exit(1);  ///< Exit the program if the port cannot be opened.
    }

    // Configure the serial port
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    GetCommState(hSerial, &dcbSerialParams);
    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    SetCommState(hSerial, &dcbSerialParams);

    // Set timeouts
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    SetCommTimeouts(hSerial, &timeouts);

    cout << "Serial port configured." << endl;
}

/**
 * @brief Sends a message to the serial port.
 *
 * This function sends a null-terminated string (message) to the serial port.
 *
 * @param message The message to send.
 */
void sendMessage(const char* message) {
    DWORD bytesWritten;
    WriteFile(hSerial, message, strlen(message), &bytesWritten, NULL);
    cout << "Sent by PC: " << message << endl;
}

/**
 * @brief Receives a message from the serial port.
 *
 * This function reads a message from the serial port into a buffer. It returns
 * the received message as a std::string. If no message is received, an empty string is returned.
 *
 * @return std::string The message received from the serial port.
 */
std::string receiveMessage() {
    char buffer[1024] = { 0 };
    DWORD bytesRead;
    bool readSuccess = ReadFile(hSerial, buffer, sizeof(buffer), &bytesRead, NULL);

    if (readSuccess && bytesRead > 0) {
        return string(buffer);
    }
    else {
        return "";
    }
}

/**
 * @brief Closes the serial port.
 *
 * This function closes the serial port and prints a confirmation message.
 */
void closeSerialPort() {
    CloseHandle(hSerial);
    cout << "Serial port closed." << endl;
}
