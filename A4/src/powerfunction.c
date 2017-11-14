/**
* @file conversions.c
* @author Stacey Scott, refactored by Chigozie Davis (0946342)
* @date last updated: October 25th 2017
* @source file that contains the function implementations of powerfunction.h
*/
#include <stdio.h>

double powerfn ( double base, int exponent ) {

    int i = 0;
    double result = 1;

    for ( i = 1; i <= exponent; i++ ) {
        result *= base;
    }

    return result;
}
