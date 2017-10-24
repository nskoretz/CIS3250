#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "scoreboard.h"

/**
* @file scoreboard.c
* @date October 23rd, 2017
* @author Pedro
* @brief This file contains functions to operate the scoreboard
*
**/

/**
 * Finds and returns a pointer to the User in the linked list beginning with
 * head which has the name nameToFind. If such a User is not in the Linked
 * List, it will return NULL. Helper function to incrementScore.
 * @param head of user list, address of character array to search for
 * @return User with name specified, or NULL if not found
 **/
User *findUserWithName(User *head, char *nameToFind) {
	if (head == NULL) {
		return head;
	}
	User *current = head ;
	while (current != NULL) {
		if (strcmp(current->name, nameToFind) == 0) {
			return current;
		}
		current = (current)->next;
	}
	return NULL;
}

/**
* frees every element of the linked list
* @param head of user list
* @return None
*/
void freeAll(User *head) {
	if (head -> next == NULL) {
		free(head);
	} else {
		User *current = head->next;
		User *previous = head;
		while (current != NULL) {
			free(previous);
			previous = current;
			current = (current)->next;
		}
	}
}

/**
* Gets user from specified index
* @param Head of user list, index
* @return Pointer to user with index, or NULL
*//
User *getUserAtIndex(User *head, int index) {
	if (head == NULL) {
		return NULL;
	}

	User *current = head;
	int count = 0;
	while (current != NULL) {
		if (count == index + 1) {
			return current;
		}
		current = (current)->next;
		count++;
	}
	return NULL;
}

/**
* Finds User with specified name and returns their index
* @param Head of user list, pointer to character array to search for
* @return Index of user, or -1 if not found
**/
int getIndexOfUserWithName(User *head, char *nameToFind) {
	if (head == NULL && head->name != nameToFind) {
		return -1;
	}
	User *current = head;
	int count = 0;
	while (current != NULL) {
		if (strcmp(current->name, nameToFind)) {
			return count;
		}
		current = (current)->next;
		count++;
	}
	return -1;
}

/**
 * Finds whether or not a an existing user is already in the list. Of they are,
 * returns 1. If not, returns 0.
 * @param Head of user list, pointer to character array to search
 * @return 1 if user is in list, or 0 if not
 **/
int userIsInList(User *head, char *nameToFind) {
	User *current = head;
	while (current != NULL) {
		if (strcmp(current->name, nameToFind) == 0) {
			return 1;
		}
		current = (current)->next;
	}
	return 0;
}

/**
* Returns length of the list
* @param Head of list
* @return Int length of list
*/
int getLength(User *head) {
	if (head == NULL) {
		return 0;
	}

	User *current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		current = (current)->next;
	}
	return count;
}

/**
 * Helper function. Finds the last node in the linked list and returns it.
 * Returns NULL if called with an empty head, although such a case is not used
 * in the main function addNode.
 * @param Head of user list
 * @return Pointer to last user in list
 **/
User *getLastNode(User *head) {
	if (head == NULL) {
		return head;
	}
	User *current = head;
	while (current != NULL) {
		if (current->next == NULL) {
			return current;
		}
		current = (current)->next;
	}
	return NULL;
}

/**
* Prints the scoreboard
* @param Head of user list
* @return None
**/
void printScoreboard(User *head) {
        printf("\n---- SCORE BOARD ---- \n");
	if (head -> next != NULL) {
		User *current = head -> next;
		while (current != NULL) {
			printf("\nPlayer name: %s \n", current->name);
			printf("High score: %d \n", current->maxScore);
			printf("Games played: %d \n", current->totalGames);
			printf("Total score: %d \n", current->totalScore);
			printf("\n--------------------- \n");

			current = (current)->next;
		}
	}
}

/**
* Adds a new user to the user list
* @param Head of user list, pointer to char array for name, maxScore
* @return None
**/
void addNode(User *head, char *name, int maxScore) {
	User *userPtr;
	if (head != NULL) {
		 userPtr = malloc(sizeof(struct user));
	}
	strcpy(userPtr->name, name);
	userPtr->  = maxScore;
	userPtr->totalGames = 1;
	userPtr->totalScore = maxScore;
	userPtr->next = NULL;

	if (head == NULL) {
		head = userPtr;
	}
	else {
		getLastNode(head)->next = userPtr;
	}
}

/**
* Updates the score of the node with the name specified
* @param Head of user list, pointer to char of name, currentScore
* @return None
**/
void updateNodeWithName(User *head, char *name, int currentScore) {
	if (userIsInList(head, name)) {
		User *userPtr = findUserWithName(head, name);
		if (currentScore > (userPtr->maxScore)) {
			userPtr->maxScore = currentScore;
		}
		userPtr->totalGames++;
		userPtr->totalScore += currentScore;
	}
}
