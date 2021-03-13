/* Ruler 1         2         3         4         5         6         7        */
/* punto1.c *******************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                     Tarea2-Dispro                          */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      DEVELOPED BY: Eng. Juan Sebastian Clavijo Martinez  */
/*    │  │   │ ║  ║                     jsebastian.calvijoc@javeriana.edu.co  */
/*    │  │   │ ║  ║                                                           */
/*    │╔═╧══╗│ ║  ║       Bogota, D.C., March 3rd, 2021.                      */
/*    │╚╗  ╔╝┘ ║  ║                                                           */
/*    └┐║  ╚╗ ╔╝  ║       Copyright (C) Electronics Engineering Program       */
/*     └╚╗  ╚═╝  ╔╝                     Faculty of Engineering                */
/*      └╚╗     ╔╝                      Pontifical Xaverian University        */
/*        ╚═════╝                       Bogota - Colombia                     */
/*                                                                            */
/******************************************************************************/

/******************************* Headers **************************************/

/* -------------------------------- Inclusion of Std Headers ---------------- */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/****************************** TYPE DEFINITIONS ******************************/
typedef struct {
	double real; /* Real part of type complex number      */
	double imag; /* Imaginary part of type complex number */
} COMPLEX_T;

/****************************** FUNCTION PROTOTYPES ***************************/
/* int Solve_Quadratic_Equation(double a,double b,double c,                   */
/* COMPLEX_T *root_1,COMPLEX_T *root2);                                       */
/*                                                                            */
/* int main( int argc,char*argv[] )                                           */

/* --------------------------- Public Functions 1 --------------------------- */

/*FN***************************************************************************/
/*   int Solve_Quadratic_Equation(double a,double b,double c,                 */  
/*   COMPLEX_T *root_1,COMPLEX_T *root2);                                     */
/*                                                                            */
/*   Return:  Number "0" for succeed                                          */
/*                                                                            */
/*   Purpose: Calculating the solutions to a second deg. equation, through the*/
/*            cuadratic formula                                               */
/*                                                                            */
/*   Plan: not necesary                                                       */
/*                                                                            */
/*   DATE          SUPERVISOR COMMENT                                         */
/*   ----------------------------------------------------------------------   */
/*   08/03/21      J.CLAVIJO  THE GRADE IS A LIE.THEGRADEISALIE.THE GRADE IS A*/
/*                                                                            */
/******************************************************************************/

int Solve_Quadratic_Equation(
double     a, /*PRIMER COEFICIENTE*/
double     b, /*SEGUNDO COEFICIENTE */
double     c, /*TERCER COEFICIENTE */
COMPLEX_T *root_1, /*apuntador de tipo Complex_t, primera soluci[on de la ec. cuadratica*/
COMPLEX_T *root_2 /*apuntador de tipo Complex_t, primera soluci[on de la ec. cuadratica*/)
{
	double disc =(b*b)-4*a*c;
	if (disc>0){
		root_1->real = ((-b+(sqrt(disc))))/(2*a));
		root_2->real = ((-b-(sqrt(disc)))/(2*a));
		root_1->imag= 0.0;
		root_2->imag = 0.0;


}
	else{
		if(disc==0){
			root_1->real = (-b/(2*a));
			root_2->real = (-b/(2*a));
			root_1->imag = 0.0;
}
		else{
			root_1->real = (-b/(2*a));
			root_1->imag= ((sqrt(disc))/(2*a));
			root_2->real = (-b/(2*a));
			root_2->imag = (-(sqrt(disc))/(2*a));
			
}
}
return 0;
		
} /* Solve_Quadratic_Equation */

/******************************* Main Function ********************************/

/*FN***************************************************************************/
/*   int main( int argc, char *argv[] )                                       */
/*                                                                            */
/*   Return:  Number "0" for succeed                                          */
/*                                                                            */
/*   Purpose: the main function of my code, recalls Solve_Quadratic_Equation  */
/*   with command line arguments.                                             */
/*                                                                            */
/*   Plan: not necesary                                                       */
/*                                                                            */
/*   DATE          SUPERVISOR COMMENT                                         */
/*   ----------------------------------------------------------------------   */
/*   08/03/21      J.Clavijo  THE GRADE IS A LIE.THEGRADEISALIE.THE GRADE IS A*/
/*                                                                            */
/******************************************************************************/

int main( int argc, char *argv[] )
{
double a = atof( argv[1] );
double b = atof( argv[2] );
double c = atof( argv[3] );

COMPLEX_T root_1, root_2;

Solve_Quadratic_Equation( a, b, c, &root_1, &root_2 );

fprintf( stdout, "Solucion 1: %f %f i\n", root_1.real, root_1.imag );
fprintf( stdout, "Solucion 2: %f %f i\n", root_2.real, root_2.imag );

return 0;
} /* main */
