/**
 * @file    calcFuncs.c
 * @author  Kevin Glover-Netherton, Maddie Gabriel
 * @date    2017-10-20
 *
 * @desc    This file was created during the refactoring of 'cis3250-legacy-calculator.c' to
 *          remove the code from the original .c file. Now, 'calcFuncs.h' will be a
 *          proper header file and will declare the functions that are
 *          implemented here.
 *
 *          The functions in this file implement the functions declared in
 *          'calcFuncs.h'.
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calcFuncs.h"
#include "matrices.h"
#include "powerfunction.h"
#include "conversions.h"
#include "factorial.h"

float input ( char *inName ) {
    
     float numIn = 0.0;
     char temp[9999];
 
     do {
 
     printf( "%s", inName );
 
         if( !scanf( "%f", &numIn ) ) {
             scanf( "%s", temp ); //recieve temp
             printf( "Please try again!\n" );
         } else {
             return numIn;
         }
 
     } while( 1 );	
 
 }
 
 
 float inputAry ( char *inName, int num ) {
 
     float numIn = 0.0;
     char temp[9999];
 
     do {
 
         printf( "%s[%d]: ", inName, num + 1 );
 
         if( !scanf( "%f", &numIn ) ) {
             scanf( "%s", temp );
             printf( "Please try again!\n" );
         } else {
             return numIn;
         }
 
     } while( 1 );	
 
 }
 
 
 float plus ( float adder, float addIn ) {
 
     float result = 0.0;
     result = adder + addIn;
     return result;
 
 }
 
 
 float minus ( float miner, float minIn ) {
 
     float result = 0.0;
     result = miner - minIn;
     return result;
 
 }
 
 
 float mult ( float multer, float multin ) {
 
     float result = 0.0;
     result = multer * multin;
     return result;
 
 }
 
 
 float divind (float divider, float dividIn ) {
 
     float result = 0.0;
     result = divider / dividIn;
     return result;
 
 }
 
 
 int factorial ( int term ) {
 
     if( term == 0 ) {
         return 1;
     }
 
     return term * factorial( term-1 );
 
 }
 
 
 int fib ( int term ) {
     
     if( term == 1 ) {
         return 0;
     }
 
     if( term == 2 ) {
         return 1;
     }
 
     return fib( term-1 ) + fib( term-2 );
 
 }
 
 
 float power ( float base, int pow ) {
 
     int i = 0;
     float mem = 1.0;
 
     for( i=0; i<pow; i++ ) {
         mem *= base;
     }
 
     return mem;
 
 }
 
 
 float sine ( float radius ) {
     
     float val = 0.0;
     float sin = 0.0;
     
     val = radius * ( PI / 180 );
     sin = val - (power( val, 3 ) / factorial(3)) + (power( val, 5 ) / factorial(5)) - (power( val, 7 ) / factorial(7));
     
     return sin;
 
 }
 
 
 float cosine ( float radius ) {
     
     float val = 0.0;
     float cos = 0.0;
 
     val = radius * (PI/180);
     cos = 1 - (power( val, 2 ) / factorial(2)) + (power( val, 4 ) / factorial(4)) - (power( val, 6 ) / factorial(6));
     
     return cos;
 
 }
 
 
 int spprint ( char *message, char *operator, int ini, int res ) {
     
     printf( "%s %d%s = %d\n", message, ini, operator, res );
     return 0;
 
 }
 
 
 float spprintf ( char *message, char *operator, float ini, float res ) {
     
     printf( "%s %.4f%s = %.4f\n", message, ini, operator, res );
     return 0;
 
 }
 
 
 float print ( char *message, char *operator, float ini, float upt, float res) {
 
     printf( "%s %.4f %s %.4f = %.4f\n", message, ini, operator, upt, res );
     return 0;
 
 }
 
 
 float aryPrint ( char *message, float ans ) {
 
     printf( "%s : %.4f\n", message, ans );
     return 0;
     
 }
 

void printMenuHeader ( char *header ) {
    int messageLen = 0;
    int i = 0;

    messageLen = strlen( header ) + 2;

    printf( "\n" );
    for ( i = 0; i < messageLen; i++ ) {
        printf( "=" );
    }
    printf( "\n %s \n", header );
    for ( i = 0; i < messageLen; i++ ) {
        printf( "=" );
    }
    printf( "\n" );
}


void getUserInput ( float *firstOp, float *secondOp ) {
    *firstOp = input( "Enter value of 1st operand: " );
    *secondOp = input( "Enter value of 2nd operand: " );
}


float runTwoOpCalc ( char symbol, float (*calcFP) (float, float) ) {
    float firstOp = 0;
    float secondOp = 0;
    float result = 0;

    getUserInput( &firstOp, &secondOp );
    result = calcFP( firstOp, secondOp );

    printf( "\nResult of %.2f %c %.2f = %.2f", firstOp, symbol, secondOp, result );
    return result;
}


void runRegCalc () {
    int choice = 0;

    do {
        printMenuHeader( "Regular Calculator Menu" );
        printf( "1.PLUS\n" );
        printf( "2.MINUS\n" );
        printf( "3.MULTIPLY\n" );
        printf( "4.DIVIDE\n" );
        printf( "0.BACK\n" );

        choice = input( "Select Menu: " );
        
        system( "clear" );

        if ( choice == 1 ) {                // Addition
            runTwoOpCalc( '+', plus );
        } else if ( choice == 2 ) {         // Subtraction
            runTwoOpCalc( '-', minus );
        } else if ( choice == 3 ) {         // Multiplication
            runTwoOpCalc( '*', mult );
        } else if ( choice == 4 ) {         // Division
            runTwoOpCalc( '/', divind );
        }  else {
            continue;
        }
    } while ( choice != 0 );
}


void matrixMenu () {
    int choice = 0;

    printMenuHeader( "Matrix Operations" );
    printf( "1.Sum of Matrices\n" );
    printf( "2.Transpose\n" );
    printf( "3.Product of Matrices\n" );
    choice = input( "Enter an operation command: " );

    switch ( choice ) {
        case 1: 
            matrix_sum();
            break;
        case 2: 
            matrix_transpose();
            break;
        case 3: 
            matrix_product();
            break;
        default:
            break;
    }

}


void conversionMenu () {
    int choice = 0;

    printMenuHeader( "Conversion Menu" );
    printf( "1.Temperature(1)\n" );
    printf( "2.Time\n" );
    choice = input( "Please choose an operation number:" );

    switch ( choice ) {
        case 1: 
            temp();
            break;
        case 2: 
            time();
            break;
        default:
            break;
    }

}


void runSciCalc () {
    float choice = 0;
    float firstOp = 0;
    float secondOp = 0;
    float result = 0;

    do {
        printMenuHeader( "Scientific Calculator Menu" );
        printf( "1.Power function (x^y)\n" );
        printf( "2.Factorial Series (x!)\n" );
        printf( "3.Fibonacci Series \n" );
        printf( "4.Sine (Sin x)\n" );
        printf( "5.Cosine (cos x)\n" );
        printf( "6.Tangent (Tan x)\n" );
        printf( "7.Cosec (cosec x)\n" );
        printf( "8.Sec (sec x)\n" );
        printf( "9.Cot (cot x)\n" );
        printf( "10.Matrix functions\n" );
        printf( "11.Conversion functions\n" );
        printf( "0.Back\n" );
        choice = input("Select Menu: ");
        system( "clear" );

        if ( choice == 1 ) {
            firstOp = input( "Enter base(x): " );
            secondOp = input( "Enter power(y): " );
            result = powerfn( firstOp, secondOp );
            print( "\nResult of", "^" , firstOp, secondOp, result);
        } else if ( choice == 2 ) {
            firstOp = input( "Enter numbers of term: " );
            result = fact( firstOp );
            spprint( "\nFactorial of", "!" , firstOp, result );
        } else if ( choice == 3 ) {
            firstOp = input( "Enter numbers of term: " );
            result = fib(firstOp);
            spprint( "\nFibonacci of", " ", firstOp, result );
        } else if ( choice == 4 ) {
            firstOp = input( "Enter your value: " );
            result = sine( firstOp );
            spprintf( "\nSine of", " ", firstOp, result );
        } else if ( choice == 5 ) {
            firstOp = input( "Enter your value: " );
            result = cosine( firstOp );
            spprintf( "\nCosine of", " ", firstOp, result );
        } else if ( choice == 6 ) {
            firstOp = input( "Enter your value: ");
            secondOp = sine( firstOp );
            result = cosine( firstOp );
            result = secondOp / result;
            spprintf( "\nTangent of", " ", firstOp, result );
        } else if ( choice == 7 ) {
            firstOp = input( "Enter your value: " );
            result = sine( firstOp );
            spprintf( "Cosec of", " ", firstOp, (1/result) );
        } else if ( choice == 8 ) {
            firstOp = input( "Enter your value: " );
            result = cosine( firstOp );
            spprintf( "\nSec of", " ", firstOp, (1/result) );
        } else if ( choice == 9 ) {
            firstOp = input( "Enter your value: " );
            secondOp = sine( firstOp );
            result = cosine( firstOp );
            result = secondOp / result;
            spprintf( "\nCot of", " ", firstOp, (1/result) );
        } else if ( choice == 10 ) {
            matrixMenu();
        } else if ( choice == 11 ) {
            conversionMenu();
        } else {
            continue;
        }
    } while ( choice != 0 );
}
