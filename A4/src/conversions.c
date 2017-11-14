/*Start of Jovana*/
/**
* @file conversions.c
* @author Stacey Scott, refactored by Jovana Kusic (0955683) and Chigozie Davis (0946342)
* @date last updated: October 25th 2017
* @source file that calculates the conversion between either time or temperature.
*/
#include<stdio.h>
#include "conversions.h"

void time ( void ){
    /*Variable Initialization*/
    int from = 1;
    int to = 0;
    double time1 = 0;
    double time2 = 0;

    /*Menu options printed*/
    printf( "\n\n\n\t\tConvert from (seconds) to: " );
    printf( "\n\t\tSeconds(1)\t\tMinutes(2)\t\tHours(3)\t\tDays(4)\n\n\n\t\tWeeks(5)\t\tMonths(6)\t\tYears(7)\t\tDecades(8)\n\n\n\t\tCenturies(9)\t\tMilleniums(10)\t\tLight Years(11)\t\tGenerations(12):" );
    printf( "\n\n\n\t\tConvert to (number):" );
    scanf( "%d", &to );
 
    /*If user enters a conversion to be done between two #'s of the same time type*/
    if ( to == 1 ) {
        printf( "Enter time in seconds:" );
        scanf( "%lf", &time1 );
        printf( "The resultant value is %f", time1 );
    } else {
        /*Has the user enter the time to be converted*/
        printf( "\n\n\n\t\tEnter the time:" );
        scanf( "%lf", &time1 );
        if ( from == 1 ) {
            /*Converts # in seconds to # in minutes*/
            if ( to == 2 ) {
                time2 = time1 / 60;
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "\n\n\n\t\t%f seconds = %f minute", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "\n\n\n\t\t1 second = %f minute", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f minutes", time1, time2 );
                }  
            /*Converts # in seconds to # in hours*/
            } else if ( to == 3 ) {
                time2 = time1 / 3600;
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "\n\n\n\t\t%f seconds = %f hour", time1, time2 );
                } else if (time1==1) {
                    printf( "\n\n\n\t\t1 second = %f hour", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f hours", time1, time2 );
                }
            /*Converts # in seconds to # in days*/
            } else if ( to == 4 ) {
                time2 = time1 / ( 3600 * 24 );
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "\n\n\n\t\t%f seconds = %f day", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "\n\n\n\t\t1 second = %f ", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f days", time1, time2 );
                }
            /*Converts # in seconds to # in weeks*/
            } else if ( to == 5 ) {
                time2 = time1 / ( 3600 * 24 * 7 );
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "\n\n\n\t\t%f seconds = %f week", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "\n\n\n\t\t1 second = %f week", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f weeks", time1, time2 );
                }
            /*Converts # in seconds to # in months*/
            } else if ( to == 6 ) {
                time2 = time1 / ( 3600 * 24 * 30 );
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "\n\n\n\t\t%f seconds = %f month", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "\n\n\n\t\t1 second = %f month", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f months", time1, time2 );
                }
            /*Converts # in seconds to # in years*/
            } else if ( to == 7 ) {
                time2 = time1 / ( 3600 * 24 * 365.25);
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "\n\n\n\t\t%f seconds = %f year ", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "\n\n\n\t\t1 second = %f year", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f years", time1, time2 );
                }
            /*Converts # in seconds to # in decades*/
            } else if ( to == 8 ) {
                time2 = time1 / ( 3600 * 24 * 365.25 * 10 );
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "\n\n\n\t\t%f seconds = %f decade", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "\n\n\n\t\t1 second = %f decade", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f decades", time1, time2 );
                }
            /*Converts # in seconds to # in centuries*/
            } else if ( to == 9 ) {
                time2 = time1 / ( 3600 * 24 * 365.25 * 100 );
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "\n\n\n\t\t%f seconds = %f century", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "\n\n\n\t\t1 second = %f century", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f centuries", time1, time2 );
                }
            /*Converts # in seconds to # in milleniums*/
            } else if ( to == 10 ) {
                time2 = time1 / ( 3600 * 24 * 365.25 * 1000 );
                if ( time2 <= 1 && time2 >= 0) {
                    printf( "\n\n\n\t\t%f seconds = %f millenium", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "\n\n\n\t\t1 second = %f millenium", time2 );
                } else {
                    printf( "\n\n\n\t\t%f seconds = %f milleniums", time1, time2 );
                }
            /*Converts # in seconds to # in generations*/
            } else if ( to == 12 ) {
                time2 = time1 / ( 3600 * 24 * 365.25 * 30 );
                if ( time2 <= 1 && time2 >= 0 ) {
                    printf( "%f seconds = %f Generation", time1, time2 );
                } else if ( time1 == 1 ) {
                    printf( "1 second = %f Generation", time2 );
                } else {
                    printf( "%f seconds = %f Generations", time1, time2 );
                }
            } else {
                printf( "Incorrect menu option selected\n" );
            }
        } else {
            printf( "No calculation could be conducted\n" );
        }
    }
} /*End of Jovana*/


/*Start of Chigozie Davis*/ 
/*refactored this block of code on 24/10/17 in accordance with the team coding conventions*/
void temp( void ) {

    int from = 0;
    int to = 0;
    double t1 = 0.0;
    double t2 = 0.0;

    printf( "\n\n\n\t\t\tCelsius(1)\t\t\tFahrenheit(2)\t\t\tKelvin(3)" );
    printf( "\n\n\n\t\t\tConvert from(number):" );
    scanf( "%d", &from );
    printf( "\n\n\n\t\t\tConvert to(number):" );
    scanf( "%d", &to );
    printf( "\n\n\n\t\t\tEnter temperature:" );
    scanf( "%lf", &t1 );

    if ( from == to ) {
        printf( "\n\n\n\t\t\t The resulting temperature remains the same: %f", t1 );
    }
    if ( from == 1 && from != to ) {

        switch( to ) {
            case 2:
                t2 = t1 * ( (double)9 / (double)5 ) + 32.0;
                printf( "\n\n\n\t\t\t%fC = %fF", t1, t2 );
                break;
            case 3:
                t2 = t1 + 273.15;
                printf( "\n\n\n\t\t\t%fC = %fK", t1, t2 );
                break;
        }

    }
    if ( from == 2 && from != to ) {
        switch( to ) {
            case 1:
                t2 = ( t1 - 32.0 ) * ( (double)5 / (double)9 );
                printf( "\n\n\n\t\t\t%fF = %fC", t1, t2 );
                break;
            case 3:
                t1 = ( t1 - 32.0 ) * ( (double)5 / (double)9 );
                t2 = t1 + 273.15;
                printf( "\n\n\n\t\t\t%fF = %fK", t1, t2 );
                break;
        }

    }
    if ( from == 3 && from != to ) {
        switch( to ) {
            case 1:
                t2 = t1 - 273.15;
                printf( "\n\n\n\t\t\t%fK = %fC", t1, t2 );
                break;
            case 2:
                t2 = ( t1 - 273.15 ) * ( (double)9 / (double)5 ) + 32;
                printf( "\n\n\n\t\t\t%fK=%fF", t1, t2 );
                break;
        }

    }

} /*End of Chigozie Davis*/

