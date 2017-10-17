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
 * @
 *
 * Detailed explanation.
 */

/* The pre-set dice which keep their values between games.*/
typedef struct PresetDice {
	char *configurations;
	int position;
} PresetDice;

/* The rolled dice which do not keep their values between games.*/
typedef struct RolledDice {
	char character;
	int position;
} RolledDice;

/*
Initializes the dice in the list of pre-set dice. Call once at program start.
*/
void initializePresetDice(struct presetDice* inputArrayOfDice);

/*
Description: Rolls the dice to be used at the start of each game. 
Puts the rolled dice in game_dice. Does not shuffle the dice. Helper function.
*/
void rollButNotShuffleDice(struct rolledDice* gameDice,
		struct presetDice* inputArrayOfDice);

/*
Shuffles an array of rolled dice. Helper function.
*/
void shuffleRolledDicePositions(struct rolledDice* gameDice);

/*
Prints a visualization of the input array of rolled_dice.
*/
void printGameBoard(struct rolledDice** gameBoard);

/*
Rolls the dice to be used at the start of the game and shuffles them, putting 
the dice into the 2D array game_dice. Call once at the start of every game.
*/
void rollDice(struct rolledDice** gameBoard,
		struct presetDice* inputArrayOfDice);

/*
Converts board from a string version to 2D array. Used in test mode.
*/
void convertToBoard(char *letters, char ***board);

/*
prints out the contents from the boggle 2D array
*/
void printHcBoard(char boggle[][4]);

#endif /*BOARD_GEN_H*/
