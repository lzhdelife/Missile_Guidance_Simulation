/*******************************************************************
 *** Runge-Kutta 4th order method for the solution of 
 *** 2nd order ODEs: Memory Allocation.
 *** 
 *** Author: Nikos Tryfonidis, November 2015
 *** The MIT License (MIT)
 *** Copyright (c) 2015 Nikos Tryfonidis
 *** See LICENSE.txt
 *******************************************************************/
#include <stdio.h>
#include <stdlib.h>

double *allocateDoubleArray1D(int size)
{
    double *array = (double *)malloc(size * sizeof(double));
    if(array == NULL) {
        printf("\n*** Array Allocation Failed! ***\n");
        printf("\nExiting...\n");
        exit(-1);
    }

    return array;
}
