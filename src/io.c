/*******************************************************************
 *** Runge-Kutta 4th order method for the solution of 
 *** 2nd order ODEs: Input and Output functions.

 *******************************************************************/
#include <stdio.h>
#include <stdlib.h>


/* Writes output to file 
   1st Column: x (independent variable)
   2nd Column: y (dependent variable)
*/
void writeFileOutput (double *t, double *x, double *y, double *z, 
                        int size, char *filename_output) 
{
    int i, j;
    FILE *outputFile;

    /* Open Output File */
    outputFile = fopen(filename_output, "w");

    /* Write Output */
    for(i=0; i<size; i++) {
        /* Apply desired number of digits for output here: */
        fprintf(outputFile, "%f\t%.10f\t%.10f\t%.10f\t\n", t[i], x[i], y[i], z[i]);
    }

    /* Close Output File */
    fclose(outputFile);
}
