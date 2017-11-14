/**
* 
* MADDIE'S CHANGES BEGIN
*
*/

/**
* File: cis3250-legacy-calculator.c
* 
* Main file of legacy calculator.
*
* Team: Lab 1 Section 1
* Last Edited: October 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "matrices.h"
#include "powerfunction.h"
#include "conversions.h"
#include "calcFuncs.h"


FILE *help;

/* NB: Changes moved to calcFuncs.c */

/**
* 
* MADDIE'S CHANGES END
*
*/

/*Kevin's Section */
/* 
 NB:  Most code here was moved to calcFuncs.h and calcFuncs.c
 That's why this refactored lines in this file seem low for me -
 it was the same amount as everyone else
*/

/**
 * Main function - menu loop for the calculator application
 * @param argc Count of command line arguments supplied by the user
 * @param argv Array of strings of supplied user arguments
 * @return Integer value corresponding to program success - 0 on success
 */
 int main ( int argc, char *argv[] ) {
    int menu = 0;

    do {
        printMenuHeader( "Menu" );
        printf( "1.Regular Calculator\n" );
        printf( "2.Scientific Calculator\n" );
        printf( "3.Acountant Calculator\n" );
        printf( "4.Read Help and Notice\n" );
        printf( "0.Exit\n" );
        menu = input( "Select Menu: " );
        system( "clear" );

        if ( menu == 1 ) {
            runRegCalc();
        } else if ( menu == 2 ) {
            runSciCalc();
        }   
/******** End of Kevin's section ***********/


// START OF REFACTORING PART ANDREW BARSOUM 0951037

    if(menu==3){

        warp:

        //system("clear");
        printf("\n===========================\n");
        printf("Accountant Calculator Menu\n");
        printf("===========================\n");
        printf("Please set value first\n");
        printf("\n");

        int n = 0;
        int i = 0;
        int j = 0;
        int amenu = 0;

        float rest = 0.00;
        float max = 0.00;
        float min = 0.00;
        float x_bar = 0;
        float sum=0;
    // END OF REFACTORING ANDREW BARSOUM 0951037
						float med = 0.00;
						//float mod = 0.00;
						//float count = 0.00;
						int temp = 0;

						n=input("Enter number of term: ");

						float set[n];
						int numtemp[n];
						for(i=0;i<n;i++){
								set[i]=inputAry("Enter value terms",i);
						}

						for(i=0;i<n;i++){
								for(j=0;j<=i;j++){
										if(set[j]>set[i]){
												rest=set[j];
												set[j]=set[i];
												set[i]=rest;
										} else{
												printf("Operation Failed.\n");
										}
								}
						}

						min = set[0];
						max = set[n-1];

						for(i=0;i<n;i++){
								sum+=set[i];
						}
						x_bar=(sum/n);

						if((n%2)!=0){
								med=set[((n+1)/2)-1];
						} else{
								med=(set[((n+1)/2)]+set[((n+1)/2)-1])/2;
						}

						for(i=0;i<n;i++){
								numtemp[i]=0;
						}

						for(i=0;i<n;i++){
								temp=set[i];
								for(j=i;j<n;j++){
										if(set[j]==temp){
												numtemp[i]++;
										} else {
												printf("Operation failed.\n");
										}
								}
						}

						temp=numtemp[0];

						for(i=1;i<n;i++){
								if(numtemp[i]>temp){
										temp = numtemp[i];
								}
						}

						if(i==999){//Always False If

								warp1://Warp form menu
								j=0;

								for(i=0;i<n;i++){
										if(numtemp[i]==temp){
												j++;
										}
								}

								if(j==1){
										for(i=0;i<n;i++){
												if(numtemp[i]==temp){
														printf("%.4f\n",set[i]);
												}
										}
								}else{
										printf("Not have mode value\n");
								}

						}

						do{
								printf("\n===========================\n");
								printf("Accountant Calculator Menu\n");
								printf("===========================\n");
								printf("1.Show max\n");
								printf("2.Show min\n");
								printf("3.Show x-bar\n");
								printf("4.Show range\n");
								printf("5.Show Med\n");
								printf("6.Show Mode\n");
								printf("7.Show value(sort)\n");
								printf("8.Set new value\n");
								printf("0.Back\n");
								amenu = input("Select Menu: ");//input acountant  menu
								system("clear");

								if(amenu==1){
										printf("\n");
										aryPrint("Max is",max);
								}

								if(amenu==2){
										printf("\n");
										aryPrint("Min is",min);
								}

								if(amenu==3){
										printf("\n");
										aryPrint("X-bar is",x_bar);
								}

								if(amenu==4){
										printf("\n");
										aryPrint("Range is",max-min);
								}

								if(amenu==5){
										printf("\n");
										aryPrint("Med is",med);
								}

								if(amenu==6){
										printf("\n");
										printf("Mode is: ");
										goto warp1;
								}

								if(amenu==7){
										printf("\n");
										printf("Set of number is(sort): ");
										for(i=0;i<n;i++){
												printf("%.3f ",set[i]);
										}
								}

								if(amenu==8){
										goto warp;
								}

						}while(amenu!=0);
				}

				if(menu==4){
						char text;

						help = fopen("User_helping.txt","r");

						while((text=fgetc(help))!=EOF){
								fprintf(stdout,"%c",text);
						}

						fclose(help);
						}
				}while(menu!=0);

		return 0;
		}

