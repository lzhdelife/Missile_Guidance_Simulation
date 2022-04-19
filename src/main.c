/*******************************************************************
 *** Runge-Kutta 4th order method for the solution of 
 *** 2nd order ODEs: main source file.
 *** 
 *** As usual, the 2nd order ODE is split into two coupled 1st order ODEs,
 *** which are solved with the Runge-Kutta function:
 ***
 *******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Headers ("headers" directory): */
#include "../headers/struct.h"
#include "../headers/RK4.h"
#include "../headers/io.h"
#include "../headers/memory.h"

int main(int argc, char * argv[])
{
  int i, j, totalSteps, nOutput, interval;
  double h, length;
  double *t, *x, *y, *z;
  struct uv old;

  h = 0.01;
  length = 100.0;
  interval = 20;

  /* 
    Calculate total timesteps 
    这几个参数的含义：
    h：步长
    length：计算的总长度
    interval：不是每一步都输出，interval = 10 的含义就是每10个点输出一次
    nOutput：总共输出几个点
  */
  totalSteps = length/h;
  printf("Total steps: %d\n", totalSteps);
  nOutput = totalSteps/interval+1;
  printf("Output size: %d points\n", nOutput);
  
  /* Allocate dependent and independent variable arrays */
  t = allocateDoubleArray1D(nOutput);

  x = allocateDoubleArray1D(nOutput);
  y = allocateDoubleArray1D(nOutput);
  z = allocateDoubleArray1D(nOutput);
  
  
  /*********************************/
  /*** ODE Solution              ***/
  /*********************************/
  
  /* Set Initial conditions here!  */
  // 角度是弧度制（rad）
  t[0] = 0; 

  x[0] = -16.0;  
  y[0] = -21.0; 
  z[0] = 33.0;  
  
  double t_old;
  t_old = t[0];

  old.u1 = x[0];
  old.u2 = y[0];
  old.u3 = z[0];
  
  /* Write solution every [interval] steps */
  for (i=1; i<nOutput; i++) {
    for(j=0; j<interval; j++) {
      t_old += h;
      old = RK4(t_old, old, h, rhs);
    }
    t[i] = t_old;

    x[i] = old.u1;
    y[i] = old.u2;
    z[i] = old.u3;
  }
  
    /* Write File Output */
    writeFileOutput(t, x, y, z, nOutput, "output/out.txt");

    /* Free Memory */
    free(t);

    free(x);
    free(y);
    free(z);

    system("python .\\analysis\\plot1D.py");

    return 0;
}

