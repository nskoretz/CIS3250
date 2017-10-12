#include <string.h>
#include "boardGenerator.h"
#include <stdlib.h>

/**********Changes Made - Ori Talmor**********
Every variable name, function name, or
parameter that contained (and just in general,
any '_' that existed) was removed, and replaced
with camel case.

Method Documentation

File name changed to remove underscore, and
replaced with camel case

Include statement that contained file with
'_' was removed and changed to camel case
version
*********************************************/


/**Function to check if a word exists on the board. Creates an array of visited nodes on the board, then checks if a word exists
*on a board given a starting row and coloumn. Checks the entire board for the word until it is found.
*@pre gameBoard and word must exist
*@return integer whether the word was found or not on the board
*@param gameBoard pointer to a gameBoard array storing the character and position of each index in the board (2D array)
*@param word string containing the word being sought after on the board
**/
int wordChecker(struct rolledDice **gameBoard, char *word);


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
int abidesRules(int i, int j, char *word, struct rolledDice** gameBoard, int subLen, int **visited);


/**Function to grab a character off the gameboard
*@pre gameBoard must exist, i and j must be non-negative real numbers
*@post character at a given position on the board is returned
*@return char representing the character at the given position
*@param i integer representing the row in the game board
*@param j integer representing the coloumn in the game board
*@param gameBoard pointer to a gameBoard array storing the character and position of each index in the board (2D array)
**/
char getLetter(int i, int j, struct rolledDice **gameBoard);


/**Function to check if a word exists in an 2d array of characters. Creates an array of visited nodes on the board, then checks if a word exists
*on a board given a starting row and coloumn. Checks the entire board for the word until it is found.
*@pre boggle and word must exist
*@return integer whether the word was found or not on the board
*@param gameBoard pointer to a 2d character array
*@param word string containing the word being sought after on the board
**/
int testWordChecker(char **boggle, char *word);


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
int testAbidesRules(int i, int j, char *word, char **gameBoard, int subLen, int **visited);


/**Function to grab a character from a 2d character board
*@pre boggle must exist, i and j must be non-negative real numbers
*@post character at a given position on the 2d character array is returned
*@return char representing the character at the given position
*@param i integer representing the row in the 2d character array
*@param j integer representing the coloumn in the 2d character array
*@param boggle pointer to a character array storing the a character in each index on the boggle board (2D array of characters)
**/
char testGetLetter(int i, int j, char **boggle);


/**Function to check if a word exists in an 2d array of characters. Creates an array of visited nodes on the board, then checks if a word exists
*on a board given a starting row and coloumn. Checks the entire board for the word until it is found.
*@pre boggle and word must exist
*@return integer whether the word was found or not on the board
*@param gameBoard pointer to a 2d character array initialized with 4 coloumns
*@param word string containing the word being sought after on the board
**/
int hcWordChecker(char boggle[][4], char *word);


/**Function to grab a character from a 2d character board which is initialized with 4 coloumns
*@pre boggle must exist, i and j must be non-negative real numbers
*@post character at a given position on the 2d character array is returned
*@return char representing the character at the given position
*@param i integer representing the row in the 2d character array
*@param j integer representing the coloumn in the 2d character array
*@param boggle pointer to a character array initialized with 4 coloumns storing the a character in each index on the boggle board (2D array of characters)
**/
char hcGetLetter(int i, int j, char boggle[][4]);


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
int hcAbidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited);



