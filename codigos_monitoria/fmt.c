/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*                                                                            */
/*    TO COMPILE...                                                           */
/*    in console use: gcc fmt.c -o fmt                                        */
/*                                                                            */
/*    TO RUN...                                                               */
/*    in MAC or linux use: ./fmt format parameter                             */
/*    in Windows use:        fmt format parameter                            */
/*                                                                            */
/******************************************************************************/

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>



/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
if( argc != 3 )
   fprintf( stderr, "Usage: %s format parameter\n", argv[0] );
else {
   fprintf( stdout, argv[1], argv[2] );
   fprintf( stdout, "\n" );
}

return 0;

} /* main */
