#include <stdio.h>
#include <string.h>
#include "wordChecker.h"
#include <ctype.h>


/**********Changes Made - Ori Talmor**********
Every variable name, function name, or
parameter that contained (and just in general,
any '_' that existed) was removed, and replaced
with camel case.

Method and Inline Documentation

File name changed to remove underscore, and
replaced with camel case.

Include statement that contained file with
'_' was removed and changed to camel case
version
*********************************************/


/**Function to grab a character off the gameboard
*@pre gameBoard must exist, i and j must be non-negative real numbers
*@post character at a given position on the board is returned
*@return char representing the character at the given position
*@param i integer representing the row in the game board
*@param j integer representing the coloumn in the game board
*@param gameBoard pointer to a gameBoard array storing the character and position of each index in the board (2D array)
**/
char getLetter(int i, int j, RolledDice **gameBoard){
    return gameBoard[i][j].character;
}


/**Function to recursively check every adjacent piece on a board and see if it is the next character needed by the word being sought after.
*If it is, move onto the next piece to be found and recursively call this function until all characters are found (or not found)
*@pre gameBoard and visited must exist, i, j, and subLen must be non-negative real numbers,
*@return integer whether the word was found or not on the board
*@param i integer representing the row in the game board
*@param j integer representing the coloumn in the game board
*@param word string containing the word being sought after on the board
*@param gameBoard pointer to a gameBoard array storing the character and position of each index in the board (2D array)
*@param subLen integer representing the last index from a string whose character has been found on the game board
*@param visited pointer to an array of characters that have already been found
**/
int abidesRules(int i, int j, char *word, RolledDice **gameBoard, int subLen, int **visited){

    /* use subLen as index to see what letter to find */
	int adjCell;

	if(subLen == (strlen(word)-1)) {
		return 1;
	}

/*FIXED INDENTATIONS FROM HERE:*/
	/* right, digUpRight, up, digUpLeft, left, digDownLeft, down, digDownRight */
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int newX;
    int newY;


    /* Grab the next letter that needs to be found */
    char findLetter;
    findLetter = word[subLen + 1];

    /* Check every character on the board surrounding the character that has already been found, to see if its the next character in the word to be found */
    int result = 0;
    for(adjCell = 0; adjCell < 8; adjCell++) {
		
        newX = i + allX[adjCell];
		newY = j + allY[adjCell];
		
		if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == getLetter(newX, newY, gameBoard) && !visited[newX][newY]){
            visited[newX][newY] = 1;
            ++subLen;
            result = abidesRules(newX, newY, word, gameBoard, subLen, visited); /* Recursively call function to find the next character in the word on the board */
            if(result){
                return 1;
            } else{
                --subLen; /* Go down a character and try to find it on a next adjacent piece on the board */
            }
        }
    }

    return 0;
/*UNTIL HERE*/
}


/**Function to check if a word exists on the board. Creates an array of visited nodes on the board, then checks if a word exists
*on a board given a starting row and coloumn. Checks the entire board for the word until it is found.
*@pre gameBoard and word must exist
*@return integer whether the word was found or not on the board
*@param gameBoard pointer to a gameBoard array storing the character and position of each index in the board (2D array)
*@param word string containing the word being sought after on the board
**/
int wordChecker(RolledDice **gameBoard, char *word){

    /* Initialize local variables */
	int row, col, m, n;
	int **visited;
	visited = malloc(sizeof(int * ) * 4);

	/* Allocate memory for each index in the 2d visited array */
	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	/* Set the first index (0,0) in the 2d visited array to 1, the rest of the indicies to 0 */
	for (m = 0; m < 4; m++){
		for (n = 0; n < 4; n++){
			if (m == 0 && n == 0){
				visited[m][n] = 1;
			} else {
                visited[m][n] = 0;
			}
		}
	}

/*FIXED INTENDENTATION*/
	/* Go through every node on the board cheching if the word can be found starting from that node */
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            if (abidesRules(row, col, word, gameBoard, 0, visited)){ /* Check if the word is found, starting at a specific coloumn and row */
                free(visited[0]);
                free(visited[1]);
                free(visited[2]);
                free(visited[3]);
                return 1;
            }
        }
    }

    /* Word wasn't found! */
	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;

}


/**Function to grab a character from a 2d character board
*@pre boggle must exist, i and j must be non-negative real numbers
*@post character at a given position on the 2d character array is returned
*@return char representing the character at the given position
*@param i integer representing the row in the 2d character array
*@param j integer representing the coloumn in the 2d character array
*@param boggle pointer to a character array storing the a character in each index on the boggle board (2D array of characters)
**/
char testGetLetter(int i, int j, char **boggle){
	return boggle[i][j];
}

/**Function to recursively check every adjacent piece on a board and see if it is the next character needed by the word being sought after.
*If it is, move onto the next piece to be found and recursively call this function until all characters are found (or not found)
*@pre gameBoard and visited must exist, i, j, and subLen must be non-negative real numbers,
*@return integer whether the word was found or not on the board
*@param i integer representing the row in the game board
*@param j integer representing the coloumn in the game board
*@param word string containing the word being sought after on the board
*@param gameBoard pointer to a 2d character array
*@param subLen integer representing the last index from a string whose character has been found on the game board
*@param visited pointer to an array of characters that have already been found
**/

int testAbidesRules(int i, int j, char *word, char **gameBoard, int subLen, int **visited){

    /*SAME CHANGES MADE HERE AS AS IN ABIDERULES FUNCTION*/
	/* use subLen as index to see what letter to find */
	int adjCell;
	char currentLetter = word[subLen];

	if(subLen == (strlen(word) - 1)){
		return 1;
	}

	/* right, digUpRight, up, digUpLeft, left, digDownLeft, down, digDownRight */
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int newX;
    int newY;

     /* Grab the next letter that needs to be found: if the current character that has already been found is a 'q'
        and 2 characters from 'q' in the word that is beight sought after is a character at the current position being looked at,
        then set findLetter to a letter after the the one in the word  that is 2 characters from 'q'
        and set the index of the current found letter (subLen) to the letter being sought after */
    char findLetter;
    if (toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == testGetLetter(i,j,gameBoard)){
        findLetter = word[subLen + 3];
        subLen++;
        subLen++;
        currentLetter = word[subLen];
    } else { /* Normal case, set the findLetter to the character after the one already found */
        findLetter = word[subLen + 1];
    }

    /* Check every character on the board surrounding the character that has already been found, to see if its the next character in the word to be found */
    int result = 0;
    for (adjCell = 0; adjCell < 8; adjCell++) {
		
        newX = i + allX[adjCell];
        newY = j + allY[adjCell];
		
        if ((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == testGetLetter(newX, newY, gameBoard) && !visited[newX][newY]){
            visited[newX][newY] = 1;
            ++subLen;
            result = testAbidesRules(newX, newY, word, gameBoard, subLen, visited);
            if (result){ /* word has been found  */
                return 1;
            } else { /* word not found go back a letter and try again in a different adjacent cell */
                --subLen;
            }
        }
    }
    return 0;
}


/**Function to check if a word exists in an 2d array of characters. Creates an array of visited nodes on the board, then checks if a word exists
*on a board given a starting row and coloumn. Checks the entire board for the word until it is found.
*@pre boggle and word must exist
*@return integer whether the word was found or not on the board
*@param gameBoard pointer to a 2d character array
*@param word string containing the word being sought after on the board
**/
int testWordChecker (char **boggle, char *word) {

    /*SAME CHANGES MADE HERE AS AS IN WORDCHECKER FUNCTION*/
    /* Initialize local variables */
	int row, col, m, n;
	int **visited;
	visited = malloc(sizeof(int * ) * 4);

	/* Allocate memory for each index in the 2d visited array */
	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	/* Set the first index (0,0) in the 2d visited array to 1, the rest of the indicies to 0 */
	for (m = 0; m < 4; m++){
		for (n = 0; n < 4; n++){
			if (m == 0 && n == 0){
				visited[m][n] = 1;
			} else {
                visited[m][n] = 0;
			}
		}
	}

	/* Go through every node on the board cheching if the word can be found starting from that node  */
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            if (testAbidesRules(row, col, word, boggle, 0, visited)) { /* Check if the word is found, starting at a specific coloumn and row */
                free(visited[0]);
                free(visited[1]);
                free(visited[2]);
                free(visited[3]);
                return 1;
            }
        }
    }

    /* Word wasn't found! */
	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;
}

/**Function to check if a word exists in an 2d array of characters. Creates an array of visited nodes on the board, then checks if a word exists
*on a board given a starting row and coloumn. Checks the entire board for the word until it is found.
*@pre boggle and word must exist
*@return integer whether the word was found or not on the board
*@param gameBoard pointer to a 2d character array initialized with 4 coloumns
*@param word string containing the word being sought after on the board
**/
int hcWordChecker(char boggle[][4], char *word) {

    /*SAME CHANGES MADE HERE AS AS IN WORDCHECKER FUNCTION*/
    /* Initialize local variables */
	int row, col, m, n;
	int **visited;
	visited = malloc(sizeof(int * ) * 4);

    /* Allocate memory for each index in the 2d visited array */
	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	/* Set the first index (0,0) in the 2d visited array to 1, the rest of the indicies to 0 */
	for (m = 0; m < 4; m++) {
		for (n = 0; n < 4; n++) {
			if (m == 0 && n == 0) {
				visited[m][n] = 1;
			} else{
                visited[m][n] = 0;
			}
		}
	}

	/* Go through every node on the board cheching if the word can be found starting from that node */
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            if (hcAbidesRules(row, col, word, boggle, 0, visited)) { /* Check if the word is found, starting at a specific coloumn and row */
                free(visited[0]);
                free(visited[1]);
                free(visited[2]);
                free(visited[3]);
                return 1;

            }
        }
    }

    /* Word wasn't found! */
	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;
}


/**Function to recursively check every adjacent piece on a board and see if it is the next character needed by the word being sought after.
*If it is, move onto the next piece to be found and recursively call this function until all characters are found (or not found)
*@pre gameBoard and visited must exist, i, j, and subLen must be non-negative real numbers,
*@return integer whether the word was found or not on the board
*@param i integer representing the row in the game board
*@param j integer representing the coloumn in the game board
*@param word string containing the word being sought after on the board
*@param gameBoard pointer to a 2d character array
*@param subLen integer representing the last index from a string whose character has been found on the game board
*@param visited pointer to an array of characters that have already been found
**/
int hcAbidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited){

    /*SAME CHANGES MADE HERE AS AS IN ABIDERULES FUNCTION*/
	/* use subLen as index to see what letter to find */
	int adjCell;
	char currentLetter = word[subLen];
	if (subLen == (strlen(word) - 1)){
		return 1;
	}

	/* right, digUpRight, up, digUpLeft, left, digDownLeft, down, digDownRight */
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int newX;
    int newY;

     /* Grab the next letter that needs to be found: if the current character that has already been found is a 'q'
        and 2 characters from 'q' in the word that is beight sought after is a character at the current position being looked at,
        then set findLetter to a letter after the the one in the word  that is 2 characters from 'q'
        and set the index of the current found letter (subLen) to the letter being sought after */
	char findLetter;
    if (toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == hcGetLetter(i,j,boggle)) {
        findLetter = word[subLen + 3];
        subLen++;
        subLen++;
        currentLetter = word[subLen];
    } else { /* Normal case, set the findLetter to the character after the one already found */
        findLetter = word[subLen + 1];
    }

    int result = 0;
    for (adjCell = 0; adjCell < 8; adjCell++) {
		
        newX = i + allX[adjCell];
        newY = j + allY[adjCell];

        if ((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == hcGetLetter(newX, newY, boggle) && !visited[newX][newY]) {
            visited[newX][newY] = 1;
            ++subLen;
            result = hcAbidesRules(newX, newY, word, boggle, subLen, visited);

            if (result) { /* Word has been found */
                return 1;
            } else { /* word not found go back a letter and try again in a different adjacent cell */
                --subLen;
            }
        }
    }

    return 0;
}


/**Function to grab a character from a 2d character board which is initialized with 4 coloumns
*@pre boggle must exist, i and j must be non-negative real numbers
*@post character at a given position on the 2d character array is returned
*@return char representing the character at the given position
*@param i integer representing the row in the 2d character array
*@param j integer representing the coloumn in the 2d character array
*@param boggle pointer to a character array initialized with 4 coloumns storing the a character in each index on the boggle board (2D array of characters)
**/
char hcGetLetter(int i, int j, char boggle[][4]){
	return boggle[i][j];
}
