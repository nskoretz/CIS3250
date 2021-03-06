/**
 * @file scoreboard.h
 * @author Jacob Vink
 * @date October 23 2017
 * @version CIS*3250 Refactoring Lab Assignment
 *
 * @brief code for functions
 **/

/*********Changes made Jacob Vink******************
-changed all variable names with _ to camel case
-added { } braces to all for-loops and if statements
-added header comments to all functions
-changed all tabs to 4 spaces
***************************************************/

#include <string.h>
#include "dictionary.h"
#include <stdio.h>

/**form hash value for string s
 *this produces a starting value in the dictionary array
 *@return unsigned hash value
 *@param pointer to a string to be used to create a hash value
 **/
unsigned hash(const char *s) {
    unsigned hashVal;

    /*loops through each char hashing it to an int*/
    for (hashVal = 0; *s != '\0'; s++) {
        hashVal = *s + 31 * hashVal;
    }
    return hashVal;
}

/**Function that uses a key to search for a word in the hash table
 *@return pointer to found node, or null if the node is not found.
 *@param pointer to the dictionary table
 *@param integer value of the table size
 *@param pointer to the key to be used to match nodes
 **/
DNode *lookUp (DNode **dictionary, int hashSize, const char *key) {
    DNode *np;
    unsigned int hashVal = hash(key);

    /*loops through each node and compares the value to key */
    for (np = dictionary [hashVal % hashSize]; np != NULL; np = np->next) {
        if (strcmp (key, np->key) == 0) {
            return np;
        }
    }
    return NULL; //not found
}

/**Inserts a new node into the dictionairy
 *@return pointer to inserted node
 *@param pointer to the dictionary table
 *@param integer value of the table size
 *@param pointer to the key value
 **/
DNode *insert (DNode **dictionary, int hashSize,  const char *key) {
    unsigned int hashVal;
    DNode *np;

    if ((lookUp(dictionary, hashSize, key)) == NULL) {
        np = (DNode *)malloc(sizeof (*np));

        if (np == NULL || (np->key = copyStr (key)) == NULL) {
            return NULL;
        }
        hashVal = hash (key) % hashSize;

        np->next = dictionary [hashVal];
        dictionary [hashVal] = np;
    }
    return np;
}

/**Frees memory inside the dictionary table
 *@param pointer to the dictionary table
 *@param integer value of the table size
 **/
void freeDictionary (DNode **dictionary, int hashSize) {
    int i;

    for (i=0; i<hashSize; i++) {
        if (dictionary [i] != NULL) { /*if there is an entry at position i */
            DNode *head = dictionary[i];
            DNode *current = head;

            /* goes through the list freeing each node */
            while (current != NULL) {
                DNode * temp = current;
                current = current->next;
                free (temp);
            }
            dictionary[i] = NULL;  //BUG fix
        }
    }
}

/** Function to make a copy of char * s
 *@return pointer to a copy of *s
 *@param pointer to the copy of *s
 **/
char *copyStr(const char *s) { /* make a duplicate of s */
    char *p;
    int len = strlen(s);

    p = (char *) malloc(len+1); /* +1 for ?\0? */
    if (p != NULL) {
        strncpy(p, s, len);
    }
    p[len] = '\0';

    return p;
}
