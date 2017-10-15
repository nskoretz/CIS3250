/**
 * @file board_generator.h
 * @author x
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
typedef struct preset_dice {
	char *configurations;
	int position;
} PresetDice;

/* The rolled dice which do not keep their values between games.*/
typedef struct rolled_dice {
	char character;
	int position;
} RolledDice;


void initialize_preset_dice(struct preset_dice* input_array_of_dice);

/**Rolls the dice to be used at the start of each game. Puts the rolled dice in
* game_dice. Does not shuffle the dice. Helper function.
@param
**/
void roll_but_not_shuffle_dice(struct rolled_dice* game_dice,
		struct preset_dice* input_array_of_dice);

void shuffle_rolled_dice_positions(struct rolled_dice* game_dice);

void print_game_board(struct rolled_dice** game_board);

void roll_dice(struct rolled_dice** game_board,
		struct preset_dice* input_array_of_dice);

void convert_to_board(char *letters, char ***board);

void print_hc_board(char boggle[][4]);

#endif /*BOARD_GEN_H*/
