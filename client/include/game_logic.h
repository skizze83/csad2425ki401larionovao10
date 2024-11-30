#pragma once
#include <string>

/**
 * @file game_modes.h
 * @brief Header file for handling different game modes and displaying results.
 */

 /**
  * @brief Starts a Man vs AI game.
  *
  * @param player1 Player 1's name.
  * @param player2 Player 2's name (AI).
  * @param result The result of the game (Win/Loss/Draw).
  */
void playManVsAI(std::string& player1, std::string& player2, std::string& result);

/**
 * @brief Starts a Man vs Man game.
 *
 * @param player1 Player 1's name.
 * @param player2 Player 2's name.
 * @param result The result of the game (Win/Loss/Draw).
 */
void playManVsMan(std::string& player1, std::string& player2, std::string& result);

/**
 * @brief Starts an AI vs AI game with random moves.
 *
 * @param player1 AI Player 1 (used for display).
 * @param player2 AI Player 2 (used for display).
 * @param result The result of the game (Win/Loss/Draw).
 */
void playAIVsAIRandom(std::string& player1, std::string& player2, std::string& result);

/**
 * @brief Starts an AI vs AI game with a winning strategy.
 *
 * @param player1 AI Player 1 (used for display).
 * @param player2 AI Player 2 (used for display).
 * @param result The result of the game (Win/Loss/Draw).
 */
void playAIVsAIWinStrategy(std::string& player1, std::string& player2, std::string& result);

/**
 * @brief Displays the result of the game.
 *
 * @param player1 Player 1's name.
 * @param player2 Player 2's name.
 * @param result The result of the game (Win/Loss/Draw).
 */
void displayResult(const std::string& player1, const std::string& player2, const std::string& result);
