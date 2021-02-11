#include <stdio.h>

int main( void )

{

double x = 3.1415, y = 2.7182;

int

Exchange_by_Value(

double value_1,

double value_2 )

{

double temporal;

 

if( value_1 != value_2 ) {

    temporal = value_1;

    value_1  = value_2;

    value_2  = temporal;

}

 

return 1;

 

} /* Exchange_by_Value */



fprintf( stdout, "x=%f, y=%f\n", x, y );

Exchange_by_Value( x, y );

fprintf( stdout, "x=%f, y=%f\n", x, y );



return 0;



} /* main */
