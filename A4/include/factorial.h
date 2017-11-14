#ifndef FACT_H
#define FACT_H

#include <stdio.h>
#include <stdint.h>

    unsigned long long int fact(int n){/*Factorial function inefficient for values after 20*/
    unsigned long long int factor;
    int i;
    factor=1;

    for(i=n;i>0;i--){
        factor*=i;
    }
    return factor;
    }
#endif

