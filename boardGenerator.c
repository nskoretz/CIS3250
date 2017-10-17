#include "boardGenerator.h"

/** Converts board from a string version to 2D array. Used in test mode
*
*All the variable names are now replaced with camelCase equivalents.
*Additionally all variables are initialized and
*defined at the top. And all the comments are now are also made compatible to
<<<<<<< HEAD
*older c versions. The functions are also sorted by alphabetical order.
=======
*older c versions. - Reformatting of the boardGenerator.c is done by Andrew Cheung
>>>>>>> 931190cc7c28967839689fe26371c31d11054e71
*
**/
void convertToBoard(char *letters, char ***board){

	/*allocate space for boggle board on heap in order to access it in main.*/
	char *word;
	int i, j, t;

	i = 0;
	j = 0;
	t = 0;

	*board = malloc(sizeof(char *) * 4);
	char **boardDeref = *board;

	boardDeref[0] = malloc(sizeof(char) * 4);
	boardDeref[1] = malloc(sizeof(char) * 4);
	boardDeref[2] = malloc(sizeof(char) * 4);
	boardDeref[3] = malloc(sizeof(char) * 4);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j != 3) {
				boardDeref[i][j] = letters[t];
				t++;

			}
			else {
				boardDeref[i][j] = letters[t];
				t++;
			}
		}
	}
}

/**Prints a visualization of the input array of RolledDice.
*
*All the variable names are now replaced with camelCase equivalents and struct
*types are in PascalCase. Additionally all variables are initialized and
*defined at the top. And all the comments are now are also made compatible to
*older c versions.
*
**/
void printGameBoard(struct RolledDice **gameBoard) {

	int i, j;

	i = 0;
	j = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j != 3) {
				printf("%c \t", gameBoard[i][j].character);
			}
			else {
				printf("%c \n", gameBoard[i][j].character);
			}
		}
	}
}

/** Prints a visualization of the hurrent board.
*
*All the variable names are now replaced with camelCase equivalents.
*Additionally all variables are initialized and
*defined at the top. All the comments are now are also made compatible to
*older c versions. There was an indent fix as well.
*
**/
void printHcBoard(char boggle[][4]) {

	int i, j;

	i = 0;
	j = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j != 3) {
				printf("%c \t", boggle[i][j]);
			}
			else {
				printf("%c \n", boggle[i][j]);
			}
		}
	}
}

/**Initializes the dice in the list of pre-set dice. Call once at program start.
*
*All the variable names are now replaced with camelCase equivalents and struct
*types are in PascalCase. Additionally all variables are initialized and
*defined at the top. And all the comments are now are also made compatible to
*older c versions.
*
**/
void initializePresetDice(struct PresetDice *inputArrayOfDice) {

	int i;

	i = 0;

	for (i = 0; i < 16; i++) {
		inputArrayOfDice[i].position = 0;
	}

	/*initializes individual potential chars for each dice*/
	inputArrayOfDice[0].configurations = "RIFOBX";
	inputArrayOfDice[2].configurations = "DENOWS";
	inputArrayOfDice[1].configurations = "IFEHEY";
	inputArrayOfDice[3].configurations = "UTOKND";
	inputArrayOfDice[4].configurations = "HMSRAO";
	inputArrayOfDice[5].configurations = "LUPETS";
	inputArrayOfDice[6].configurations = "ACITOA";
	inputArrayOfDice[7].configurations = "YLGKUE";
	inputArrayOfDice[8].configurations = "QBMJOA";
	inputArrayOfDice[9].configurations = "EHISPN";
	inputArrayOfDice[10].configurations = "VETIGN";
	inputArrayOfDice[11].configurations = "BALIYT";
	inputArrayOfDice[12].configurations = "EZAVND";
	inputArrayOfDice[13].configurations = "RALESC";
	inputArrayOfDice[14].configurations = "UWILRG";
	inputArrayOfDice[15].configurations = "PACEMD";
}

/**Shuffles an array of rolled dice. But doesn't move the positions.
*
*All the variable names are now replaced with camelCase equivalents and struct
*types are in PascalCase. Additionally all variables are initialized and
*defined at the top. And all the comments are now are also made compatible to
*older c versions. Indenting for the parameters have been fixed.
*
**/
void rollButNotShuffleDice(struct RolledDice *gameDice,
	struct PresetDice *inputArrayOfDice) {

	int i;

	i = 0;

	srand(time(NULL));
	for (i = 0; i < 16; i++) {
		int r = rand() % 6;
		gameDice[i].character = inputArrayOfDice[i].configurations[r];
	}
}

/**Rolls the dice to be used at the start of the game and shuffles them, putting
*the dice into the 2D array gameDice. Call once at the start of every game.
*
*All the variable names are now replaced with camelCase equivalents and struct
*types are in PascalCase. Additionally all variables are initialized and
*defined at the top. And all the comments are now are also made compatible to
*older c versions. Indenting for the parameters have been fixed.
*
**/
void rollDice(struct RolledDice **gameBoard,
	struct PresetDice *inputArrayOfDice){

	int i, j;

	i = 0;
	j = 0;

	gameBoard[0] = malloc(sizeof(struct RolledDice) * 4);
	gameBoard[1] = malloc(sizeof(struct RolledDice) * 4);
	gameBoard[2] = malloc(sizeof(struct RolledDice) * 4);
	gameBoard[3] = malloc(sizeof(struct RolledDice) * 4);

	/*temporary array of structs to contain adjusted 1D array of dice.*/
	struct RolledDice adjustedDiceArray[16];

	rollButNotShuffleDice(adjustedDiceArray, inputArrayOfDice);
	shuffleRolledDicePositions(adjustedDiceArray);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			gameBoard[i][j] = adjustedDiceArray[i * 4 + j];
		}
	}
}

/**Shuffles an array of rolled dice. Helper function.
*
*All the variable names are now replaced with camelCase equivalents and struct
*types are in PascalCase. Additionally all variables are initialized and
*defined at the top. And all the comments are now are also made compatible to
*older c versions.
*
**/
void shuffleRolledDicePositions(struct RolledDice *gameDice) {

	int i, r;

	i = 0;
	r = 0;

	struct RolledDice newGameDice[16];

	for (i = 0; i < 16; i++) {
		srand(time(NULL));
		/*this is somewhat inefficient. Using it for now.*/
		while (gameDice[r].position == -1) {
			r = (int) (rand() % 16);
		}
		newGameDice[i] = gameDice[r];
		gameDice[r].position = -1;
	}

	for (i = 0; i < 16; i++) {
		gameDice[i] = newGameDice[i];
		gameDice[i].position = i + 1;
	}
}
