/*
 * =====================================================================================
 *
 *       Filename:  punto2.c
 *
 *    Description:  punto 2 de la tarea 1 de DISPRO 
 *
 *        Version:  1.0
 *        Created:  02/22/2021 07:50:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Juan Sebastian Clavijo (), jclavijomartinez@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


/* b8_test.c ******************************************************************/
#include <stdio.h>
#define B8(d7,d6,d5,d4,d3,d2,d1,d0) scanf
int main( int argc, char *argv[] )
{
unsigned char byte = B8(1,1,0,0,1,0,1,0);
fprintf( stderr, "Your number in octal base is 0%O\n", byte );
fprintf( stderr, "Your number in decimal base is %d\n", byte );
fprintf( stderr, "Your number in hexadecimal is 0x%X\n", byte );
return 0;
} /* main */
