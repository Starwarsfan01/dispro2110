/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>



/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
fprintf( stdout, "%d\n",   0x05      +   0x03      );
fprintf( stdout, "%d\n",   0x05      + (~0x03 + 1) );
fprintf( stdout, "%d\n",   0x05      - (~0x03 + 1) );
fprintf( stdout, "%d\n", (~0x05 + 1) + (~0x03 + 1) );
fprintf( stdout, "%d\n", (~0x05 + 1) - (~0x03 + 1) );

return 0;

} /* main */
