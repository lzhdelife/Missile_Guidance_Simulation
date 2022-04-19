/*******************************************************************
 *** Runge-Kutta 4th order method for the solution of 
 *** 2nd order ODEs: Runge Kutta method and right-hand-side function,
 *** along with Force function.
 ***
 ***  Author: Nikos Tryfonidis, November 2015
 *** The MIT License (MIT)
 *** Copyright (c) 2015 Nikos Tryfonidis
 *** See LICENSE.txt
 *******************************************************************/
#include <stdio.h>
#include <math.h>

#include "../headers/struct.h"

/* Right-hand side function of the 2nd order ODE. 
   This version sticks to Newton's 2nd law formalism
*/
struct uv rhs(double t, struct uv uv) 
{
  double P, R, b;
  P = 10.0;
  R = 28.0;
  b = 8.0 / 3;
  struct uv res;
  res.u1 = P*(uv.u2 - uv.u1);
  res.u2 = R * uv.u1 - uv.u2 - uv.u1 * uv.u3;
  res.u3 = uv.u1 * uv.u2 - b * uv.u3;

  return res;
}

/*
  Runge - Kutta 4th order for 2nd Order ODEs.
  Returns new, calculated solutions for x and v,
  nicely packed into a structure.  
*/
struct uv RK4(double t, struct uv old, double h, 
              struct uv (*rhs)(double, struct uv))
{
  struct uv new;

  new.u1 = old.u1 + h *rhs(t, old).u1;
  new.u2 = old.u2 + h *rhs(t, old).u2;
  new.u3 = old.u3 + h *rhs(t, old).u3;

  return new;
}
