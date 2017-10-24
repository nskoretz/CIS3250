/**
 * @file boardGenerator.h
 * @author Michael Vamvakas
 * @date 9 Sep 2012 update 12 Oct 2017
 * @brief File takes care of how the Boggle board is shown.
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */

#ifndef BOARD_GEN_H
#define BOARD_GEN_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/**
 * Changes Made by Michael
 * Added in Doxygen style comments
 * Changed all variable names to camel case and all struct data types to pascal case
 * Changed pointers so that when declared the star is next to the variable
 * Changed all of the tabs to spaces
 */

/** 
 * The pre-set dice which keep their values between games.
 */
typedef struct PresetDice {
    char *configurations;
    int position;
} PresetDice;

/**
 * The rolled dice which do not keep their values between games.
 */
typedef struct RolledDice {
    char character;
    int position;
} RolledDice;

/**
 * Description: Initializes the dice in the list of pre-set dice. Call once at program start.
 * @param: inputArrayOfDice, pointer to a an array of the presetDice
 */
void initializePresetDice(struct PresetDice *inputArrayOfDice);

/**
 * Description: Rolls the dice to be used at the start of each game. 
 * Puts the rolled dice in game_dice. Does not shuffle the dice. Helper function.
 * @param: gameDice, pointer to the game dice
 */
void rollButNotShuffleDice(struct RolledDice *gameDice,
        struct PresetDice* inputArrayOfDice);

/**
 * Shuffles an array of rolled dice. Helper function.
 * @param: gameDice, pointer to the game dice
 */
void shuffleRolledDicePositions(struct RolledDice *gameDice);

/**
 * Prints a visualization of the input array of rolled_dice.
 * @param: gameBoard, pointer to an array of rolledDice
 */
void printGameBoard(struct RolledDice **gameBoard);

/**
 * Rolls the dice to be used at the start of the game and shuffles them, putting 
 * the dice into the 2D array game_dice. Call once at the start of every game.
 * @param: gameBoard, pointer to an array of rolledDice
 */
void rollDice(struct RolledDice **gameBoard,
        struct PresetDice* inputArrayOfDice);

/**
 * Converts board from a string version to 2D array. Used in test mode.
 * @param: letters, string of all the letters
 * @param: board, array of all the strings on the board
 */
void convertToBoard(char *letters, char ***board);

/**
 * prints out the contents from the boggle 2D array
 * @param: boggle: 2D array of characters
 */
void printHcBoard(char boggle[][4]);

#endif /*BOARD_GEN_H*/
