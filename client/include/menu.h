#pragma once

/**
 * @file menu.h
 * @brief Header file for displaying the game menu and getting user input.
 */

 /**
  * @brief Displays the game menu with available modes.
  */
void menu();

/**
 * @brief Prompts the user for a valid choice between the specified minimum and maximum values.
 *
 * This function ensures that the input is within the specified range and returns the user's valid choice.
 *
 * @param min The minimum valid choice.
 * @param max The maximum valid choice.
 * @return The user's valid choice.
 */
int getValidatedChoice(int min, int max);
