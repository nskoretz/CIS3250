/**
* matrices.h
*
* This code has been refactored by Nicholas Skoretz to conform to
* Team 1 Coding Conventions Document.
*
* Last Modified: 2017-10-15
* Modified by: Nicholas Skoretz
*
* This file declares all functions related to the matrix operations of the
* calculator.
*/


//Header Guards
#ifndef MATRICES_H
#define MATRICES_H


//Functions
/**
* This function calculates and displays the sum of two matrices entered by the
* user.
*
* @return void      No return, prints to stdout.
*/
void matrix_sum ();


/**
* This function calculates and displays the product of two matrices entered
* by the user.
*
* @return void      Output to stdout.
*/
void matrix_product ();


/**
* This function transposes a matrix entered by the user. That is to say, it
* switches their row and column indexes to 'flip' the matrix.
*
* @return void      Prints to stdout.
*/
void matrix_transpose ();

#endif

/**************************************
 * End of modification Nicholas Skoretz
 **************************************/

