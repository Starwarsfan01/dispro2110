/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>



/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
fprintf( stdout, "The color: %s\n", "blue" );
fprintf( stdout, "First number: %d\n", 12345 );
fprintf( stdout, "Second number: %04d\n", 25 );
fprintf( stdout, "Third number: %i\n", 1234 );
fprintf( stdout, "Float number: %3.2f\n", 3.14159 );
fprintf( stdout, "Hexadecimal: %X\n", 255 );
fprintf( stdout, "Octal: %o\n", 255 );
fprintf( stdout, "Unsigned value: %u\n", 150 );
fprintf( stdout, "Just print the percentage sign %%\n", 10 );

return 0;

} /* main */
