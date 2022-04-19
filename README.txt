			RK4_2

			i. Description
			ii. Dependencies
			iii. Instructions
			iv. Output

--------------------------------------------------------------------
i. DESCRIPTION:

  The code in the current repository constitutes 
  a simple 2nd order ODE solver written in C with 
  additional plotting done with Python (NumPy + matplotlib).

  The program essentially solves equations of the following form:

     		  (d^2)y/(dx)^2 = f(t, x, v)

  The numerical method used is Runge - Kutta 4th order, one of 
  the most well-known methods for the numerical solution of such 
  differential equations.

  Newton's 2nd law formalism has been kept; the right-hand function
  is of the form force(t, x, v)/mass.

--------------------------------------------------------------------
ii. DEPENDENCIES:

   The program is written in C and is expected to compile and run 
   with no problems in any (linux) system.

   Plotting is done numpy and matplotlib, two fundamental packages 
   for numerical Python. 

   Installing is straightforward for linux systems, 
   for example in Ubuntu:

   sudo apt-get install python-numpy python-matplotlib

--------------------------------------------------------------------
iii. INSTRUCTIONS:

1. Enter the desired force function f(t, x, v) into the 
   F function, inside the src/RK4.c source file.

2. Enter the desired initial conditions for t, x and v at the beginning
   of the program, in main (right after the memory allocations).

3. Compile, using the provided makefile. Simply type "make" in the 
   main directory, where the makefile is also located.

# Windows下用 "mingw32-make"

4. Run the program from the command line in the following format:
   
	$ ./RK4_2 <timestep> <total time> <output interval>

   For example, running the following:

	$ ./RK4_2 0.1 100 10

   will use a time step of 0.1, up to 100 time units and produce 
   output every 10 timesteps (i.e. every 10*0.1 = 1 time units).

---------------------------------------------------------------------
iv. OUTPUT:

   The program outputs the independent variable t and the numerical 
   solutions x and v as columns in the file "output/out.txt".

   It also plots the solution using matplotlib, producing the 
   following plots:

   1. (t, x(t)) and (t, v(t)) as separate plots in a single figure.

   2. (x(t), v(t)) (a.k.a. phase-space plot).

   To do the above, enter the "analysis" directory and run:
   
   $ python plot1D.py


