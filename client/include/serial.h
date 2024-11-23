#pragma once
#ifndef SERIAL_H
#define SERIAL_H

#include <windows.h>
#include <string>

/**
 * @file serial.h
 * @brief Header file for handling serial port communication.
 */

 /**
  * @brief Handle for the serial port.
  */
extern HANDLE hSerial;

/**
 * @brief Initializes the serial port with the specified port name.
 *
 * This function sets up the serial port with necessary parameters, including baud rate, byte size, stop bits,
 * parity, and timeouts. It also opens the serial port for communication.
 *
 * @param portName The name of the serial port to initialize (e.g., "COM1", "COM3").
 */
void initSerialPort(const std::string& portName);

/**
 * @brief Sends a message to the connected serial device.
 *
 * This function writes the provided message to the serial port.
 *
 * @param message The message to be sent to the serial device.
 */
void sendMessage(const char* message);

/**
 * @brief Receives a message from the connected serial device.
 *
 * This function reads data from the serial port and returns the received message.
 *
 * @return The received message as a string.
 */
std::string receiveMessage();

/**
 * @brief Closes the serial port and releases resources.
 *
 * This function closes the serial port handle and releases any resources associated with it.
 */
void closeSerialPort();

#endif
