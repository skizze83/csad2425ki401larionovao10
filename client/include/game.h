#pragma once
#ifndef GAME_H
#define GAME_H

/**
 * @file game.h
 * @brief Header file for handling game logic, including player choices, game state management, and statistics.
 */

#include <string>

 /**
  * @brief Converts a player's choice number to a string.
  *
  * @param number The choice number.
  * @return Corresponding string for the choice.
  */
std::string getChoiceFromNumber(int number);

/**
 * @brief Gets the user's choice for the game.
 * @return User's choice as a string.
 */
std::string getUserChoice();

/**
 * @brief Parses the game result response.
 * @param response The game result response.
 * @param player1 Player 1's result.
 * @param player2 Player 2's result.
 * @param result Overall game result.
 */
void parseResponse(const std::string& response, std::string& player1, std::string& player2, std::string& result);

/**
 * @brief Saves the game state to a file.
 * @param player1 Player 1's name.
 * @param player2 Player 2's name.
 * @param result Game result.
 * @param gameMode Current game mode.
 * @param isLoadedGame Whether the game was loaded.
 */
void saveGameState(const std::string& player1, const std::string& player2, const std::string& result, int gameMode, bool isLoadedGame);

/**
 * @brief Loads the game state from a file.
 * @param player1 Player 1's name.
 * @param player2 Player 2's name.
 * @param result Game result.
 * @param gameMode Game mode.
 * @return true if the state was loaded, false otherwise.
 */
bool loadGameState(std::string& player1, std::string& player2, std::string& result, int& gameMode);

/**
 * @brief Gets the AI's choice from the server.
 * @return AI's choice as a string.
 */
std::string getAIChoiceFromServer();

/**
 * @brief Resets the game statistics (wins, losses, draws, total games).
 */
void resetStatistics();

/**
 * @brief Last used game mode (extern variable).
 */
extern int lastGameMode;

/**
 * @brief Number of wins for player 1 (extern variable).
 */
extern int player1Wins;

/**
 * @brief Number of wins for player 2 (extern variable).
 */
extern int player2Wins;

/**
 * @brief Number of draws (extern variable).
 */
extern int draws;

/**
 * @brief Total number of games played (extern variable).
 */
extern int totalGames;

/**
 * @brief Current game mode (extern variable).
 */
extern int currentGameMode;

#endif
