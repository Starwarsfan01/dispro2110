/* name.c *********************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                     Tarea2-Dispro                          */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      DEVELOPED BY: Ing. Juan Sebastian Clavijo Martinez  */
/*    │  │   │ ║  ║                     jsebastian.calvijoc@javeriana.edu.co  */
/*    │  │   │ ║  ║                                                           */
/*    │╔═╧══╗│ ║  ║       Bogota, D.C., March 3rd, 2021.                      */
/*    │╚╗  ╔╝┘ ║  ║                                                           */
/*    └┐║  ╚╗ ╔╝  ║       Copyright (C) Electronics Engineering Program       */
/*     └╚╗  ╚═╝  ╔╝                     School of Engineering                 */
/*      └╚╗     ╔╝                      Pontificia Universidad Javeriana      */
/*        ╚═════╝                       Bogota - Colombia - South America     */
/*                                                                            */
/******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	double real; /* Real part of type complex number      */
	double imag; /* Imaginary part of type complex number */
} COMPLEX_T;


int Solve_Quadratic_Equation(
double     a,
double     b,
double     c,
COMPLEX_T sol[2])
{
	double disc = (b*b)-4*a*c; 
	disc>0 ? fprintf( stdout, "valor1:  %f %f\n",sol[0]->(*root1->real)) :0;return 0;	
} /* Solve_Quadratic_Equation */

int
main( int argc, char *argv[] )
{
double a = atof( argv[1] );
double b = atof( argv[2] );
double c = atof( argv[3] );

COMPLEX_T sol[2]={*root1,*root2};
 
Solve_Quadratic_Equation( a, b, c,sol[2]);

fprintf( stdout, "Solucion 1: %f %f\n", root_1.real, root_1.imag );
fprintf( stdout, "Solucion 2: %f %f\n", root_2.real, root_2.imag );

return 0;
} /* main */
