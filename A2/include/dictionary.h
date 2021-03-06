/**
 * @file scoreboard.h
 * @author Jacob Vink
 * @date October 23 2017
 * @version CIS*3250 Refactoring Lab Assignment
 *
 * @brief Holds function headers
 **/
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>
#define BIG_HASH_SIZE 20000
#define SMALL_HASH_SIZE 100

/**
  * node structure
 **/
typedef struct DNode {
	char *key;
    struct DNode *next;
}DNode;

/** Function to make a copy of char * s
 *@return pointer to a copy of *s
 *@param pointer to the copy of *s
 **/
char *copyStr (const char *);

/**form hash value for string s
 *this produces a starting value in the dictionary array
 *@return unsigned hash value
 *@param pointer to a string to be used to create a hash value
 **/
unsigned hash(const char *s);

/**Function that uses a key to search for a word in the hash table
 *@return pointer to found node, or null if the node is not found.
 *@param pointer to the dictionary table
 *@param integer value of the table size
 *@param pointer to the key to be used to match nodes
 **/
DNode *lookUp (DNode **dictionary, int hashSize, const char *key);

/**Inserts a new node into the dictionary
 *@return pointer to inserted node
 *@param pointer to the dictionary table
 *@param integer value of the table size
 *@param pointer to the key value
 **/
DNode *insert (DNode **dictionary, int hashSize, const char *key);

/**Frees memory inside the dictionary table
 *@param pointer to the dictionary table
 *@param integer value of the table size
 **/
void freeDictionary (DNode **dictionary, int hashSize);

#endif
