/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*                                                                            */
/*    TO COMPILE...                                                           */
/*    in console use: gcc sizeof.c -o sizeof                                  */
/*                                                                            */
/*    TO RUN...                                                               */
/*    in MAC or linux use: ./sizeof                                           */
/*    in Windows use:        sizeof                                           */
/*                                                                            */
/******************************************************************************/

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>



/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
fprintf( stdout, "Size of data type in this machine:\n" );

fprintf( stdout, "\nINTEGER:\n" );
fprintf( stdout, "Size of char: %lu\n",        sizeof( char ) );
fprintf( stdout, "Size of short: %lu\n",       sizeof( short ) );
fprintf( stdout, "Size of int:  %lu\n",        sizeof( int ) );
fprintf( stdout, "Size of long: %lu\n",        sizeof( long ) );
fprintf( stdout, "Size of long long: %lu\n",   sizeof( long long ) );

fprintf( stdout, "\nFLOATING POINT:\n" );
fprintf( stdout, "Size of float: %lu\n",       sizeof( float ) );
fprintf( stdout, "Size of double: %lu\n",      sizeof( double ) );
fprintf( stdout, "Size of long double: %lu\n", sizeof( long double ) );

fprintf( stdout, "\nOTHERS:\n" );
fprintf( stdout, "Size of array: %lu\n", sizeof( long double[1000][1000] ) );

return 0;

} /* main */
