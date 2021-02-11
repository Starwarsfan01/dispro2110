/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*                                                                            */
/*    TO COMPILE...                                                           */
/*    in console use: gcc f2hexa.c -o f2hexa                                  */
/*                                                                            */
/*    TO RUN...                                                               */
/*    in MAC or linux use: ./f2hexa flt_point_number                          */
/*    in Windows use:        f2hexa flt_point_number                          */
/*                                                                            */
/******************************************************************************/

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>
#include <stdlib.h>



/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
if( argc != 2 )
   fprintf( stderr, "Usage: %s flt_point_number\n", argv[0] );
else {
   int p;
   register union { float f; int i; } d = { .f = atof( argv[1] ) };
   fprintf( stdout, "%X\n", d.i );
   for( p=31; p>=0; p-- ) fprintf( stdout, "%c", d.i & 1 << p ? '1' : '0' );
   fprintf( stdout, "\n" );
}

return 0;

} /* main */
