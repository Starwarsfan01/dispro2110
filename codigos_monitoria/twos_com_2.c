/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>

int   x = 0x8000; // 0000 0000 0000 0000 1000 0000 0000 0000
short y = 0x8000; //                     1000 0000 0000 0000

/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
fprintf( stdout, "%d\n",   0 + x );
fprintf( stdout, "%d\n\n", 0 - x );

fprintf( stdout, "%d\n",   0 + y );
fprintf( stdout, "%d\n\n", 0 - y );

return 0;

} /* main */
