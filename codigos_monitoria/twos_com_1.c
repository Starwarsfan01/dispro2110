/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*                                                                            */
/*    TO COMPILE...                                                           */
/*    in console use: gcc twos_com.c -o twos_com                              */
/*                                                                            */
/*    TO RUN...                                                               */
/*    in MAC or linux use: ./twos_com                                         */
/*    in Windows use:        twos_com                                         */
/*                                                                            */
/******************************************************************************/

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>



/******************************* Static Data **********************************/

static char byte[256];



/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
int i;

for( i=0; i<256; i++ )
	byte[i] = i;

for( i=255; i>=0; i-- )
	fprintf( stdout, "byte[%d]: %d\n", i, byte[i] );

return 0;

} /* main */
