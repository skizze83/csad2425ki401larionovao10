/**
* @file game_logic.cpp
* @brief Implements the game logic for different game modes.
*/

#include <iostream>
#include <string>
#include <regex>
#include "game_logic.h"
#include "game.h"
#include "serial.h"

using namespace std;

/**
 * @brief Plays the game between the user (Player 1) and the AI.
 *
 * This function gets the player's choice, sends it to the Arduino, and then receives and parses the AI's response.
 *
 * @param player1 The string to store Player 1's choice.
 * @param player2 The string to store Player 2's choice (AI).
 * @param result The string to store the game result ("Player 1 wins", "Player 2 wins", or "draw").
 */
void playManVsAI(string& player1, string& player2, string& result) {
    player1 = getUserChoice();
    cout << "[info] Sending move to Arduino: " << player1 << endl;
    sendMessage(player1.c_str());
    Sleep(1000);

    cout << "[info] Receiving response from Arduino..." << endl;
    string response = receiveMessage();
    parseResponse(response, player1, player2, result);
}

/**
 * @brief Plays the game between two human players.
 *
 * This function allows Player 1 and Player 2 to input their choices, sends them to the Arduino, and then
 * receives and parses the game result.
 *
 * @param player1 The string to store Player 1's choice.
 * @param player2 The string to store Player 2's choice.
 * @param result The string to store the game result ("Player 1 wins", "Player 2 wins", or "draw").
 */
void playManVsMan(string& player1, string& player2, string& result) {
    player1 = getUserChoice();
    sendMessage(("Player1:" + player1).c_str());
    Sleep(1000);

    system("CLS");

    player2 = getUserChoice();
    sendMessage(("Player2:" + player2).c_str());
    Sleep(1000);

    string response = receiveMessage();
    parseResponse(response, player1, player2, result);
}

/**
 * @brief Plays an AI vs AI game with random strategies.
 *
 * This function sends the "AI_vs_AI_random" command to the Arduino, then receives and parses the result of
 * the game between the two AIs.
 *
 * @param player1 The string to store Player 1's choice (AI).
 * @param player2 The string to store Player 2's choice (AI).
 * @param result The string to store the game result ("Player 1 wins", "Player 2 wins", or "draw").
 */
void playAIVsAIRandom(string& player1, string& player2, string& result) {
    sendMessage("AI_vs_AI_random");
    Sleep(1000);

    cout << "[info] Receiving response from Arduino..." << endl;
    string response = receiveMessage();
    parseResponse(response, player1, player2, result);
}

/**
 * @brief Plays an AI vs AI game with a win-strategy.
 *
 * This function sends the "AI_vs_AI_win_strategy" command to the Arduino, then receives and parses the result
 * of the game between the two AIs using the win strategy.
 *
 * @param player1 The string to store Player 1's choice (AI).
 * @param player2 The string to store Player 2's choice (AI).
 * @param result The string to store the game result ("Player 1 wins", "Player 2 wins", or "draw").
 */
void playAIVsAIWinStrategy(string& player1, string& player2, string& result) {
    sendMessage("AI_vs_AI_win_strategy");
    Sleep(1000);

    cout << "[info] Receiving response from Arduino..." << endl;
    string response = receiveMessage();
    parseResponse(response, player1, player2, result);
}

/**
 * @brief Displays the result of the game, including players' choices and the winner.
 *
 * This function prints the choices made by Player 1 and Player 2, and highlights the winner in green or red.
 * The result (win, draw) is also displayed.
 *
 * @param player1 The choice made by Player 1.
 * @param player2 The choice made by Player 2.
 * @param result The result of the game ("Player 1 wins", "Player 2 wins", or "draw").
 */
void displayResult(const string& player1, const string& player2, const string& result) {
    const string GREEN = "\033[32m";  ///< ANSI escape code for green text
    const string RED = "\033[31m";    ///< ANSI escape code for red text
    const string RESET = "\033[0m";   ///< ANSI escape code to reset text color

    cout << "\n========== Game Result ==========" << endl;
    if (result == "Player 1 wins") {
        cout << "Player 1 chose: " << GREEN << player1 << RESET << endl;
        cout << "Player 2 chose: " << RED << player2 << RESET << endl;
    }
    else if (result == "Player 2 wins") {
        cout << "Player 1 chose: " << RED << player1 << RESET << endl;
        cout << "Player 2 chose: " << GREEN << player2 << RESET << endl;
    }
    else {
        cout << "Player 1 chose: " << player1 << endl;
        cout << "Player 2 chose: " << player2 << endl;
    }
    cout << "Result: " << result << endl;
    cout << "=================================" << endl;
}
