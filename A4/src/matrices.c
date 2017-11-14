/**
 * @file    matrices.c
 * @author  Nicholas Skoretz (0927127)
 * @date    2017-10-15
 *
 * @desc    This file was created during the refactoring of 'matrices.h' to
 *          remove the code from the .h file. Now, 'matrices.h' will be a
 *          proper header file and will declare the functions that are
 *          implemented here.
 *
 *          The functions in this file implement the functions declared in
 *          'matrices.h'.
**/


//Standard Libraries
#include <stdio.h>


//User Libraries
#include "matrices.h"


//Functions
void matrix_sum ( void ) {

    //Declarations & Initializations
    int i = 0;
    int j = 0;
    int matrix1Rows = 0;
    int matrix1Cols = 0;
    int matrix2Rows = 0;
    int matrix2Cols = 0;

    //Body
    printf( "Enter the number of rows of matrix 1:" );
    scanf( "%d", &matrix1Rows );
    printf( "Enter the number of columns of matrix :" );
    scanf( "%d", &matrix1Cols );
    printf( "Enter the number of rows of matrix 2:" );
    scanf( "%d", &matrix2Rows );
    printf( "Enter the number of columns of matrix 2:" );
    scanf( "%d", &matrix2Cols );

    if ( ( matrix1Rows == matrix2Rows ) && ( matrix1Cols == matrix2Cols ) ) {
        float matrix1[matrix1Rows][matrix1Cols];
        float matrix2[matrix2Rows][matrix2Cols];
        float sumMatrix[matrix1Rows][matrix1Cols];

        for ( i = 0; i < matrix1Rows; i++ ) {
            printf( "Enter the members of matrix 1 row %d :", i+1 );
            for ( j = 0; j < matrix1Cols; j++ ) {
                scanf( "%f", &matrix1[i][j] );
            }
        }

        for ( i = 0; i < matrix2Rows; i++ ) {
            printf( "Enter the members of matrix 2 row %d :", i + 1 );
            for ( j = 0; j < matrix2Cols; j++ ) {
                scanf( "%f", &matrix2[i][j] );
            }
        }

        for ( i = 0; i < matrix1Rows; i++ ) {
            for ( j = 0; j < matrix1Cols; j++ ) {
                sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        printf( "The sum of both matrices is\n:" );
        for ( j = 0; j < matrix1Cols; j++ ) {
            for ( i = 0; i < matrix1Rows; i++ ) {
                printf( "\t\t %.0f", sumMatrix[i][j] );
            }
            printf( "\n" );
        }
    }
    else {
        printf( "\n\tThe matrices are incompatible" );
    }
}


void matrix_product ( void ) {

    //Declarations & Initializations
    int i = 0;
    int j = 0;
    int matrix1Rows = 0;
    int matrix1Cols = 0;
    int matrix2Rows = 0;
    int matrix2Cols = 0;

    //Body
    printf( "Enter the number of rows of matrix 1:" );
    scanf( "%d", &matrix1Rows );
    printf( "Enter the number of columns of matrix :" );
    scanf( "%d", &matrix1Cols );
    printf( "Enter the number of rows of matrix 2:" );
    scanf( "%d", &matrix2Rows );
    printf( "Enter the number of columns of matrix 2: ");
    scanf( "%d", &matrix2Cols );

    float matrix1[matrix1Rows][matrix1Cols];
    float matrix2[matrix2Rows][matrix2Cols];
    float productMatrix[matrix1Rows][matrix1Cols];

    for ( i = 0; i < matrix1Rows; i++ ) {
        printf( "Enter the members of matrix 1 row %d :", i + 1 );
        for ( j = 0; j < matrix1Cols; j++ ) {
            scanf( "%f", &matrix1[i][j] );
        }
    }

    for ( i = 0; i < matrix2Rows; i++ ) {
        printf( "Enter the members of matrix 2 row %d :", i + 1 );
        for ( j = 0; j < matrix2Cols; j++ ) {
            scanf( "%f", &matrix2[i][j] );
        }
    }

    productMatrix[i][j] = 1;
    for ( i = 0; i < matrix1Rows; i++ ) {
        for ( j = 0; j < matrix2Cols; j++ ) {
            productMatrix[i][j] = 0;
            productMatrix[i][j] += ( matrix1[i][j] * matrix2[i][j] );
        }
    }

    printf( "The product of the matrix is\n:" );
    for ( j = 0; j < matrix1Cols; j++ ) {
        for ( i = 0; i < matrix2Rows; i++ ) {
            printf( "\t\t %.0f", matrix1[i][j] );
        }
        printf( "\n" );
    }
}


void matrix_transpose () {

    //Declarations & Initializations
    int i = 0;
    int j = 0;
    int numOfRows = 0;
    int numOfCols = 0;

    printf( "Enter the number of rows:" );
    scanf( "%d", &numOfRows );
    printf( "Enter the number of columns:" );
    scanf( "%d", &numOfCols );

    float transposeMatrix[numOfRows][numOfCols];

    for ( i = 0; i < numOfRows; i++ ) {
        printf( "Enter the members of row %d :", i + 1 );
        for ( j = 0; j < numOfCols; j++ ) {
            scanf( "%f", &transposeMatrix[i][j] );
        }
    }

    printf( "The transpose of the matrix is\n:" );
    for ( j = 0; j < numOfCols; j++ ) {
        for ( i = 0; i < numOfRows; i++ ) {
            printf( "\t\t %.0f", transposeMatrix[i][j] );
        }
        printf( "\n" );
    }
}

/**************************************
 * End of modification Nicholas Skoretz
 **************************************/
