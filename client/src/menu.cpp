/**
 * @file menu.cpp
 * @brief Contains functions for displaying the game menu and validating user input.
 */

#include <iostream>
#include "menu.h"

using namespace std;

/**
 * @brief Displays the game menu with options for the player.
 *
 * This function prints a list of game modes to the console, allowing the user to choose
 * a game mode to start. The options include different modes for playing against AI or another player.
 */
void menu() {
    cout << "\n============= Game Menu =============" << endl;
    cout << "1. Man vs AI" << endl;
    cout << "2. Man vs Man" << endl;
    cout << "3. AI vs AI (Random Move)" << endl;
    cout << "4. AI vs AI (Win Strategy)" << endl;
    cout << "5. Exit" << endl;
    cout << "=====================================" << endl;
}

/**
 * @brief Prompts the user for a valid choice within a specified range.
 *
 * This function repeatedly asks the user to input a number and validates that the choice
 * is within the specified range (min to max). If the input is invalid, the user will be
 * prompted again.
 *
 * @param min The minimum valid value for the choice.
 * @param max The maximum valid value for the choice.
 *
 * @return int The validated choice entered by the user.
 */
int getValidatedChoice(int min, int max) {
    int choice;
    while (true) {
        cout << "Enter choice: ";
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(10000, '\n');  ///< Clears the input buffer.
            return choice;
        }
        else {
            cout << "[error] Invalid input. Please enter a number between " << min << " and " << max << "." << endl;
            cin.clear();  ///< Clears the error flag on the input stream.
            cin.ignore(10000, '\n');  ///< Clears the input buffer.
        }
    }
}
