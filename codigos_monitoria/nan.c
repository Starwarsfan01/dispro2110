/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*                                                                            */
/*    TO COMPILE...                                                           */
/*    in console use: gcc nan.c -o nan                                        */
/*                                                                            */
/*    TO RUN...                                                               */
/*    in MAC or linux use: ./nan                                              */
/*    in Windows use:        nan                                              */
/*                                                                            */
/******************************************************************************/

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>



/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
float f =  1.0/0.0;
float g = -1.0/0.0;
float h =  0.0/0.0;

fprintf( stdout, "f =  1.0/0.0 yields %f\n", f );
fprintf( stdout, "g = -1.0/0.0 yields %f\n", g );
fprintf( stdout, "h =  0.0/0.0 yields %f\n", h );
fprintf( stdout, "f + g yields %f\n", f + g );

return 0;

} /* main */
