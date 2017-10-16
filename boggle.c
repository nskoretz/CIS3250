/**
 * @file boggle.c
 *
 * @date October 15th 2017
 *
 * @brief This program models the Boggle board game
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#include "boardGenerator.h"
#include "wordChecker.h"
#include "scoreboard.h"

#define MAX_LINE 100

/**
 - set up board,
 - set up dictionary,
 **/

/**
 * Converts every character in the character array to upper case
 *
 * @param upper The address of a character array containing the string to be converted
 * @return A pointer to the converted character array
 */
char *convertToUpper( char **upper ) {
    char *upperDeref = *upper;
    int i;

    for(i = 0; upperDeref[i]; i++){
        upperDeref[i] = toupper( upperDeref[i] );
    }
    return upperDeref;
}

/**
 * Converts the characters in the character array into upper case
 *
 * @param upper A pointer to the character array to be converted
 * @return The character array containing converte characters
 */
char *convertToUpper2( char (*upper)[] ) {
    char *upperDeref = *upper;
    int i;

    for(i = 0; upperDeref[i]; i++){
        upperDeref[i] = toupper( upperDeref[i] );
    }
    return upperDeref;
}

/**
 * Frees the memory allocated to the game board and resets it with new dice values
 *
 * @param gameBoard The game board to be freed and resets
 * @param inputArrayOfDice The standard dice that keep their values between games
 */
void freeAndResetBoard( struct rolled_dice **gameBoard,
    struct preset_dice *inputArrayOfDice ) {

    int i;
    for (i = 0; i < 4; i++) {
      free(gameBoard[i]);
    }
    rollDice(gameBoard, inputArrayOfDice);
    return;
}

/**
 * Displays length of word passed to the screen, then calculates the score increment
 * based on the word length.
 *
 * @param userScore Pointer to the user's score
 * @param word Pointer to the word the user made
 */
void incrementTotalScore( int *userScore, char *word ) {

    int wordLength = strlen( word );
    fprintf( stdout, "wordLength: %d\n", wordLength );
    if (wordLength == 3 || wordLength == 4) {
        *userScore += 1;
    } else if (wordLength == 5) {
        *userScore += 2;
    } else if (wordLength == 6) {
        *userScore += 3;
    } else if (wordLength == 7) {
        *userScore += 5;
    } else if (wordLength >= 8) {
        *userScore += 11;
    }
}

int main( int argc, char **argv ) {
    int i, points, testPoints, invalidSize;
    int currentScore, turnCount;
    char inputWord[100];
    char originalInputWord[100];
    char line [MAX_LINE];
    char readLine[MAX_LINE];
    char *fileName;
    const char * dictionaryName = "EnglishWords.txt";
    FILE *inputFilePtr;
    FILE *outputFilePtr;
    DNode* checkEnglish;
    DNode* checkSubmitted;
    static DNode* englishDictionary[BIG_HASH_SIZE];
    static DNode* guessedWords[SMALL_HASH_SIZE];
    User* head = NULL;
    PresetDice globalDice[16];
    RolledDice *gameBoard[4];

    currentScore = turnCount = 0;
    points = testPoints = invalidSize = 0;
    head = (User*)malloc( sizeof( User ) );

    if (!(inputFilePtr = fopen( dictionaryName , "r" ))) {
        fprintf( stderr, "Could not open file \"%s\" for reading dictionary words\n",
            dictionaryName );
        return 1;
    }

    while (fgets( line, MAX_LINE, inputFilePtr ) != NULL) {
        line[strcspn( line, "\r\n" )] = '\0';  //trim new line characters
        insert( englishDictionary, BIG_HASH_SIZE, convertToUpper2( &line ) );
    }
    fclose( inputFilePtr );

    if (argc == 1) {
        fprintf( stdout, "playing in normal mode\n\n" );
        system( "clear" );
        initializePresetDice( globalDice );
        rollDice( gameBoard, globalDice );

        while (turnCount >= 0) {
            char inputName[100];
            strcpy( originalInputWord, inputWord );
            convertToUpper2( &inputWord );
            User *thisUser;

            /* "q" is the input, print scoreboard and exit game */
            if (strcmp( originalInputWord, "q" ) == 0) {
                printScoreboard( head );
                break;
            }

            /* "n" is the input, adds user to/changes user in linked list and
             * resets game
             */
            if (strcmp( originalInputWord, "n" ) == 0) {
                printScoreboard( head );
                fprintf( stdout, "Your current score: %d \n", currentScore );
                fprintf( stdout, "What is your name? \n" );
                scanf( "%s", inputName );

                if (userIsInList( head, inputName ) == 0) {
                    addNode( head, inputName, currentScore );
                } else {
                    updateNodeWithName( head, inputName, currentScore );
                }

                currentScore = 0;
                strcpy( inputWord, "" );
                freeAndResetBoard( gameBoard, globalDice );
                turnCount = 0;
                system( "clear" );
                continue;
            }
            printGameBoard( gameBoard );
            checkEnglish = lookup( englishDictionary, BIG_HASH_SIZE, inputWord );

            if (checkEnglish != NULL) {
                checkSubmitted = lookup( guessedWords, SMALL_HASH_SIZE, inputWord );

                if (checkSubmitted == NULL) {
                    if (strlen( inputWord ) > 2) {
                        if  (wordChecker( gameBoard, inputWord )) {
                            insert( guessedWords, SMALL_HASH_SIZE, inputWord );
                            incrementTotalScore( &currentScore, inputWord );
                            fprintf( stdout, "Correct! You current score is now: %d \n", currentScore );
                        } else {
                            fprintf( stderr, "The submitted word: \'%s\'' does not abide game rules. Try again!\n", originalInputWord );
                        }
                    } else {
                        fprintf( stderr, "The submitted word: \'%s\'' must be at least 3 letters long. Try again!\n", originalInputWord );
                    }
                } else {
                    fprintf( stderr, "You have already submitted the word: \'%s\'' Try again!\n", originalInputWord );
                }
            } else if (turnCount > 0) {
                fprintf( stderr, "Incorrect word: \'%s\' is not in the English Dictionary. Try again!\n", originalInputWord );
            }
            fprintf( stdout, "Submit a word you found:\n" );
         	  scanf( "%s", inputWord );
            turnCount++;
            system( "clear" );
        }
        for (i = 0; i < 4; i++) {
            free( gameBoard[i] );
        }
        freeAll( head );
    } else if (argc == 2) {
        fileName = argv[1];
        fprintf( stdout, "playing in test mode with file: %s\n", fileName );
        FILE *testFilePtr;
        char testLine[MAX_LINE];
        char *testWords;
        char **testBoards;
        int fileLineCounter;
        int i, j, begin;
        DNode* testResult;

        begin = 0;
        fileLineCounter = 1;

        /* (1) read first line which is the board */
        if (!(testFilePtr = fopen( fileName , "r" ))) {
            fprintf( stderr, "Could not open test file \'%s\' for reading\n", fileName );
            return 1;
        } else if (!(outputFilePtr = fopen( "result.txt", "w" ))) {
            fprintf( stderr, "Could not open result file \'%s\' for writing\n", "result.txt" );
            return 1;
        }

        while (fgets( testLine, MAX_LINE, testFilePtr ) != NULL) {
            testLine[strcspn( testLine, "\r\n" )] = '\0';  //trim new line characters

            if (fileLineCounter == 1) {
                convertToBoard( testLine, &testBoards );

                /* this can be removed, its just for testing purposes */
                for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++) {
                        if (j != 3) {
                            fprintf( stdout, "%c \t", testBoards[i][j] );
                        } else {
                            fprintf( stdout, "%c \n", testBoards[i][j] );
                        }
                    }
                }
            } else if (fileLineCounter >= 2) {
                for (char *p = strtok( testLine, "," ); p != NULL; p = strtok( NULL, "," )) {
                    checkEnglish = lookup( englishDictionary, BIG_HASH_SIZE, convertToUpper( &p ) );

                    if (checkEnglish != NULL) {
                        checkSubmitted = lookup( guessedWords, SMALL_HASH_SIZE, p );

                        if (checkSubmitted == NULL) {
                            if (testWordChecker( testBoards, p )) {
                                insert( guessedWords, SMALL_HASH_SIZE, p );
                                incrementTotalScore( &testPoints, p );
                                fprintf( stdout,"Correct! Your total score is now: %d \n",testPoints );
                            } else {
                                if (begin == 0) {
                                    fprintf( outputFilePtr, "%s", p );
                                    begin++;
                                } else {
                                    fprintf( outputFilePtr, ",%s", p );
                                }
                                fprintf( stderr, "The submitted word: \'%s\'' does not abide game rules. Try again!\n", p );
                            }
                        } else {
                            if (begin == 0) {
                                fprintf( outputFilePtr, "%s", p );
                                begin++;
                            } else {
                                fprintf( outputFilePtr, ",%s", p );
                            }
                            fprintf( stderr,"You have already submitted the word: \'%s\'' Try again!\n", p );
                        }
                    } else {
                        if (begin == 0) {
                            fprintf( outputFilePtr, "%s", p );
                            begin++;
                        } else {
                            fprintf( outputFilePtr, ",%s", p );
                        }
                        fprintf( stderr,"Incorrect word: \'%s\'' is not in the English Dictionary. Try again!\n", p );
                    }
                }
            }
            fileLineCounter++;
        }
        fprintf( outputFilePtr, "\n" );
        fprintf( outputFilePtr, "%d\n", testPoints );

        fclose( testFilePtr );

        for (int i = 0; i < 4; i++) {
            free( testBoards[i] );
        }
        free( testBoards );
        fclose( outputFilePtr );
    }

    freeDictionary( englishDictionary, BIG_HASH_SIZE );
    freeDictionary( guessedWords, SMALL_HASH_SIZE );

    return 0;
}
