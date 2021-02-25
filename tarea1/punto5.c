/* ieee_cases.c ***************************************************************/

/********************************** Headers ***********************************/


/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdio.h>

/********************************** Macros ************************************/

#define IS_NAN(n) 0
#define IS_QNAN(n) 0
#define IS_SNAN(n) 0
#define IS_INF(n) 0
#define IS_ZERO(n) if(n==0) {1}
#define IS_SUB(n) 0
#define IS_VALID_FLT(n) 0 

/******************************** Prototypes **********************************/

unsigned atoh( char *ap );

/******************************* Main Function ********************************/

int main( int argc, char *argv[] )
{
register union { float f; unsigned i; } d = { .i = atoh( argv[1] ) };

printf( "%X (%f) is %sNaN\n", d.i, d.f, IS_NAN( d.i ) ? "" : "not " );
printf( "%X (%f) is %sqNaN\n", d.i, d.f, IS_QNAN( d.i ) ? "" : "not " );
printf( "%X (%f) is %ssNaN\n", d.i, d.f, IS_SNAN( d.i ) ? "" : "not " );
printf( "%X (%f) is %sinf\n", d.i, d.f, IS_INF( d.i ) ? "" : "not " );
printf( "%X (%f) is %szero\n", d.i, d.f, IS_ZERO( d.i ) ? "" : "not " );
printf( "%X (%f) is %ssubnormal\n", d.i, d.f, IS_SUB( d.i ) ? "" : "not " );
printf( "%X (%f) is %svalid\n", d.i, d.f, IS_VALID_FLT( d.i ) ? "" : "not " );

return 0;
} /* main */

/******************************** Definition **********************************/
/* Taken from https://github.com/barak/cbp/blob/master/libcs/atoh.c */
/******************************************************************************/

unsigned
 atoh( char *ap )
{
register char *p;
register unsigned int n;
register int digit, lcase;

p = ap;
n = 0;
while(*p == ' ' || *p == ' ')
p++;

if(*p == '0' && ((*(p+1) == 'x') || (*(p+1) == 'X')))
p+=2;

while( (digit = (*p >= '0' && *p <= '9')) ||
(lcase = (*p >= 'a' && *p <= 'f')) ||
(*p >= 'A' && *p <= 'F') ) {
n *= 16;
if (digit)
n += *p++ - '0';
else if (lcase)
n += 10 + (*p++ - 'a');
else
n += 10 + (*p++ - 'A');
}
return( n );
} /* atoh */

