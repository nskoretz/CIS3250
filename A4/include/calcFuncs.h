#ifndef CALC_FUNCS_H
#define CALC_FUNCS_H

#define PI 3.1415926535897932384626433832795
/**
* Function to receive user input
*
* @param char * variable "inName" (string prompt to print for user)
* @return float value of "key" variable from user
*/
float input ( char *inName );


/**
* Function to get array input from user.
*
* @param char * variable "inName" (string prompt to print for user)
* @param int variable "num" (for fibonacci sequence)
* @return float value of "key" variable from user
*/
float inputAry ( char *inName, int num );


/**
* Function to add 2 float values.
*
* @param float variable "adder" to be added with "addIn"
* @param float variable "addIn" to be added with "adder"
* @return float value result of addition
*/
float plus ( float adder, float addIn );


/**
* Function to subtract 2 float values.
*
* @param float variable "miner" to subtract "minIn" from
* @param float variable "minIn" to subtract from "miner"
* @return float value result of subtraction
*/
float minus ( float miner, float minIn );


/**
* Function to multiply 2 float values.
*
* @param float variable "multer" to multiply with "multIn"
* @param float variable "multIn" to multiply with "multer"
* @return float value result of multiplication
*/
float mult ( float multer, float multin );


/**
* Function to divide 2 float values.
*
* @param float variable "divider" to divided by with "dividIn"
* @param float variable "dividIn" to divide "divider" by
* @return float value result of division
*/
float divind ( float divider, float dividIn );


/**
* Function to calculate factorial
*
* @param integer "term" to calculate factorial of
* @return integer factorial result (once finished recursively calling function) 
*/
int factorial ( int term );


/**
* Function to calculate fibonacci sequence
*
* @param integer "term" to calculate fibonacci sequence of
* @return integer fibonacci sequence result (once finished recursively calling function) 
*/
int fib ( int term );


/**
* Function to calculate the nth power of a given number
*
* @param float value base (base of exponent calculation)
* @param integer value pow (power to raise base to)
* @return float base to the nth power
*/
float power ( float base, int pow );


/**
* Function to calculate sine value of given float
*
* @param float radius to calculate sine of
* @return float calculated sine value of given radius
*/
float sine ( float radius );


/**
* Function to calculate cosine value of given float
*
* @param float radius to calculate cosine of
* @return float calculated cosine value of given radius
*/ 
float cosine ( float radius );


/**
* Function to print formatted output of caluculations where input/result are integers
*
* @param char * screen :: to print before result given
* @param char * sym :: calculation symbol to print
* @param int ini :: initial value being calculated
* @param int res :: value of result of calculation
* @return integer zero
*/
int spprint ( char *message, char *operator, int ini, int res );


/**
* Function to print formatted output of caluculations where input/result are floats
*
* @param char * screen :: to print before result given
* @param char * sym :: calculation symbol to print
* @param float ini :: initial value being calculated
* @param float res :: value of result of calculation
* @return float zero
*/
float spprintf ( char *message, char *operator, float ini, float res );


/**
* Function to print formatted output of regular calculator menu calculations
*
* @param char * screen :: to print before result given
* @param char * sym :: calculation symbol to print
* @param float ini :: initial value being calculated
* @param float ini :: initial upt being calculated
* @param float res :: value of result of calculation
* @return float zero
*/
float print ( char *message, char *operator, float ini, float upt, float res);


/**
* Function to print formatted output of accounting calculator menu calculations
*
* @param char * screen :: to print before result given
* @param float ans :: value of answer of the calculation
* @return float zero
*/
float aryPrint ( char *message, float ans );

/****** Kevin's Section *******/

/**
 * Prints a message surrounded by '=' as a banner header
 * @param header The message to be printed
 */
void printMenuHeader ( char *header );


/**
 * Function to get user input and updates argument pointers with the value
 * @param firstOp The first operand to get input for
 * @param secondOp The second operand to get input for
 */
void getUserInput ( float *firstOp, float *secondOp );


/**
 * Function to get two operands from the user, perform a specified operation, and return the result
 * @param symbol The symbol of the operation being performed
 * @param calcFP Function pointer to the operation function being performed
 * @return Float value corresponding to the result
 */
float runTwoOpCalc ( char symbol, float ( *calcFP ) ( float, float ) );

/**
 * Runs the regular calculator menu and branches based on user input
 */
void runRegCalc ();


/*
 * Sub menu for matrix operations
 */
void matrixMenu ();

/**
 * Sub menu for conversion operations
 */
void conversionMenu ();


/**
 * Runs the Scientific calculator menu and branches based on user input
 */
void runSciCalc ();

#endif
/******* End of Kevin's Section *******/
