/**
 * @file scoreboard.h
 * @date October 17 2017
 * @version CIS*3250 Refactoring Lab Assignment
 * @Mitchell + Team Members but mostly Jackson
 * @brief Holds function headers
 */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdlib.h>

typedef struct User {
    char name[100];
    int maxScore;
    int totalGames;
    int totalScore;
    struct User *next;
} User;

/**
 * Function to find user in the list with the specified name.
 *
 * @param head Pointer to first user in list
 * @param nameToFind Pointer to specified name
 * @return Pointer to the user with the specified name, if any
 */
User *findUserWithName( User *head, char *nameToFind );

/**
 * Function to find user at specified index in the list
 *
 * @param head Pointer to first user in list
 * @param index Int to specify user searching for
 * @return user pointer to user at specified index, if any
 */
User *getUserAtIndex( User *head, int index );

/**
 * Function to get index of user with specified name
 *
 * @param head Pointer to first user in list
 * @param nameToFind Pointer to name to search for
 * @return int of index of user with specified name
 */
int getIndexOfUserWithName( User *head, char *nameToFind );

/**
 * Function to get length of user list
 *
 * @param head Pointer to first user in list
 * @return int of length of user list
 */
int getLength( User *head );

/**
 * Function to get last node of user list
 *
 * @param head Pointer to first user in list
 * @return pointer to last node in the list
 */
User *getLastNode( User *head );

/**
 * Function to print scoreboard
 *
 * @param head Pointer to first user in list
 */
void printScoreboard( User *head );

/**
 * Function to free all allocated memory
 *
 * @param head Pointer to first user in list
 */
void freeAll(User *head);

/**
 * Function to add node
 *
 * @param head Pointer to first user in list
 * @param name Pointer to name of user
 * @param maxScore Int for max score
 */
void addNode( User *head, char *name, int maxScore );

/**
 * Function to see if user is in list
 *
 * @param head Pointer to first user in list
 * @param nameToFind Pointer to name searched for
 * @return int indicating if user is in list
 */
int userIsInList( User *head, char *nameToFind );

/**
 * Function to update node with name
 *
 * @param head Pointer to first user in list
 * @param name Pointer to name to update
 * @param currentScore Int of current score
 */
void updateNodeWithName( User *head, char *name, int currentScore );

#endif
