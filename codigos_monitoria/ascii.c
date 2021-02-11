/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>



/******************************** Static String *******************************/

char string_1[] = "Dispro";
char string_2[] = { 'd', 'i', 's', 'p', 'r', 'o', '\0' };
char string_3[] = { 'd' - 0x20, 'i', 's', 'p', 'r', 'o', '\0' };
char string_4[] = { 68, 0x69, 0163, 'P' + 32, 'r', 'o' - ('a' - 'A'), '\0' };
char string_5[] = { 68, 105, 115, 112, 114, 111 };




/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
fprintf( stdout, "Test 1: %s\n", "Dispro" );
fprintf( stdout, "Test 2: %d\n", 'D' + 'i' + 's' + 'p' + 'r' + 'o' );
fprintf( stdout, "Test 3: %s\n", string_1 );
fprintf( stdout, "Test 4: %s\n", string_2 );
fprintf( stdout, "Test 5: %s\n", string_3 );
fprintf( stdout, "Test 6: %s\n", string_4 );
fprintf( stdout, "Test 7: %c%c%c%c%c%c\n",
			string_5[0], string_5[1], string_5[2],
			string_5[3], string_5[4], string_5[5] );
fprintf( stdout, "Test 8: %s\n", string_5 );

string_2[6] = '+';
fprintf( stdout, "Test 9: %s\n", string_2 );

return 0;

} /* main */
