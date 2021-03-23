/* Ruler 1         2         3         4         5         6         7        */

/**********************************  select.c  ********************************/
/*                                                                            */
/*   Purpose: Demonstration of "selector constructs" with math functions      */
/*                                                                            */
/*   Origin:  Documentation written by Juan C. Giraldo, August 21th, 2015     */
/*            Code inside every function written by ------------              */
/*                                                                            */
/*   Notes:   None                                                            */
/*                                                                            */
/******************************************************************************/

#include <math.h>

/**********************  Declarations of Private Functions  *******************/

/*****************************  Public Functions  *****************************/

/*FN****************************************************************************
*
*   double Selection_Binary( int n, double value )
*
*   Return:          Result of evaluating a selected math function at a value
*
*   Purpose:         This function evaluates a value according to an integer
*                    that identifies it. This function is implemented using
*                    proposition with if with nested else.
*
*   Plan:            It is not necessary
*
*   Algorithm at:    "---_Selection.pdf"
*
*   Time to Develope: -- minutes
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Aug 21/15  -----------  Initial implementation
*
*******************************************************************************/

double
Selection_Binary(
int n,         /* In: Integer to select 1 out of 16 math functions */
double value ) /* In: Operand to be applied to selected math function */
{
double result;

if( n<8 )
    if( n<4 )
        if( n<2 )
            if( n<1 )                                  /* n==0 */
                result = acos( value );
            else                                       /* n==1 */
                result = asin( value );
        else
            if( n<3 )                                  /* n==2 */
                result = atan( value );
            else                                       /* n==3 */
                result = ceil( value );
    else
        if( n<6 )
            if( n<5 )                                  /* n==4 */
                result = cos( value );
            else                                       /* n==5 */
                result = cosh( value );
        else
            if( n<7 )                                  /* n==6 */
                result = exp( value );
            else                                       /* n==7 */
                result = fabs( value );
else
    if( n<12 )
        if( n<10 )
            if( n<9 )                                 /* n==8 */
                result = floor( value );

            else                                      /* n==9 */
                result = log( value );
        else
            if( n<11 )                                /* n==10 */
                result = log10( value );
            else                                      /* n==11 */
                result = sin( value );
    else
        if( n<14 )
            if( n<13 )                                 /* n==12 */
                result = sinh( value );
            else                                       /* n==13 */
                result = sqrt( value );
        else
            if( n<15 )                                 /* n==14 */
                result = tan( value );
            else                                       /* n==15 */
                result = tanh( value );
    
return( result );
    
} /* Selection_Binary */



/*FN****************************************************************************
*
*   double Selection_Prioritized( int n, double value )
*
*   Return:          Result of evaluating a selected math function at a value
*
*   Purpose:         This function evaluates a value according to an integer
*                    that identifies it. This function is implemented using
*                    proposition with if with nested else.
*
*   Plan:            It is not necessary
*
*   Algorithm at:    "---_Selection.pdf"
*
*   Time to Develope: -- minutes
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Aug 21/15  -----------  Initial implementation
*
*******************************************************************************/

double
Selection_Prioritized(
int n,         /* In: Integer to select 1 out of 16 math functions */
double value ) /* In: Operand to be applied to selected math function */{
double result;

if( n==0 )
    result = acos( value );
else if( n==1 )
    result = asin( value );
else if( n==2 )
    result = atan( value );
else if( n==3 )
    result = ceil( value );
else if( n==4 )
    result = cos( value );
else if( n==5 )
    result = cosh( value );
else if( n==6 )
    result = exp( value );
else if( n==7 )
    result = fabs( value );
else if( n==8 )
    result = floor( value );
else if( n==9 )
    result = log( value );
else if( n==10 )
    result = log10( value );
else if( n==11 )
    result = sin( value );
else if( n==12 )
    result = sinh( value );
else if( n==13 )
    result = sqrt( value );
else if( n==14 )
    result = tan( value );
else
    result = tanh( value );

return( result );

} /* Selection_Prioritized */



/*FN****************************************************************************
*
*   double Selection_Bypassed( int n, double value )
*
*   Return:          Result of evaluating a selected math function at a value
*
*   Purpose:         This function evaluates a value according to an integer
*                    that identifies it. This function is implemented using
*                    proposition with if without else.
*
*   Plan:            It is not necessary
*
*   Algorithm at:    "---_Selection.pdf"
*
*   Time to Develope: -- minutes
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Aug 21/15  -----------  Initial implementation
*
*******************************************************************************/

double
Selection_Bypassed(
int n,         /* In: Integer to select 1 out of 16 math functions */
double value ) /* In: Operand to be applied to selected math function */
{
double result;

if( n==0 )
    result = acos( value );
if( n==1 )
    result = asin( value );
if( n==2 )
    result = atan( value );
if( n==3 )
    result = ceil( value );
if( n==4 )
    result = cos( value );
if( n==5 )
    result = cosh( value );
if( n==6 )
    result = exp( value );
if( n==7 )
    result = fabs( value );
if( n==8 )
    result = floor( value );
if( n==9 )
    result = log( value );
if( n==10 )
    result = log10( value );
if( n==11 )
    result = sin( value );
if( n==12 )
    result = sinh( value );
if( n==13 )
    result = sqrt( value );
if( n==14 )
    result = tan( value );
if( n==15 )
    result = tanh( value );

return( result );

} /* Selection_Bypassed */



/*FN****************************************************************************
*
*   double Selection_Jump( int n, double value )
*
*   Return:          Result of evaluating a selected math function at a value
*
*   Purpose:         This function evaluates a value according to an integer
*                    that identifies it. This function is implemented using
*                    proposition with switch-case.
*
*   Plan:            It is not necessary
*
*   Algorithm at:    "---_Selection.pdf"
*
*   Time to Develope: -- minutes
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Aug 21/15  -----------  Initial implementation
*
*******************************************************************************/

double
Selection_Jump(
int n,         /* In: Integer to select 1 out of 16 math functions */
double value ) /* In: Operand to be applied to selected math function */
{
double result;

switch( n ) {

    case 0:
        result = acos( value );
        break;

    case 1:
        result = asin( value );
        break;

    case 2:
        result = atan( value );
        break;

    case 3:
        result = ceil( value );
        break;

    case 4:
        result = cos( value );
        break;

    case 5:
        result = cosh( value );
        break;

    case 6:
        result = exp( value );
        break;

    case 7:
        result = fabs( value );
        break;

    case 8:
        result = floor( value );
        break;

    case 9:
        result = log( value );
        break;

    case 10:
        result = log10( value );
        break;

    case 11:
        result = sin( value );
        break;

    case 12:
        result = sinh( value );
        break;

    case 13:
        result = sqrt( value );
        break;
            
    case 14:
        result = tan( value );
        break;
            
    case 15:
        result = tanh( value );
        break;

}

return( result );

} /* Selection_Jump */



/*FN****************************************************************************
*
*   double Selection_Goto( int n, double value )
*
*   Return:          Result of evaluating a selected math function at a value
*
*   Purpose:         This function evaluates a value according to an integer
*                    that identifies it. This function is implemented using
*                    goto proposition.
*
*   Plan:            It is not necessary
*
*   Algorithm at:    "---_Selection.pdf"
*
*   Time to Develope: -- minutes
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Aug 21/15  -----------  Initial implementation
*
*******************************************************************************/

double
Selection_Goto(
int n,         /* In: Integer to select 1 out of 16 math functions */
double value ) /* In: Operand to be applied to selected math function */
{
double result;

if( n==0 ) {
    result = acos( value );
    goto end;
}

if( n==1 ) {
    result = asin( value );
    goto end;
}

if( n==2 ) {
    result = atan( value );
    goto end;
}

if( n==3 ) {
    result = ceil( value );
    goto end;
}

if( n==4 ) {
    result = cos( value );
    goto end;
}

if( n==5 ) {
    result = cosh( value );
    goto end;
}

if( n==6 ) {
    result = exp( value );
    goto end;
}

if( n==7 ) {
    result = fabs( value );
    goto end;
}

if( n==8 ) {
    result = floor( value );
    goto end;
}

if( n==9 ) {
    result = log( value );
    goto end;
}

if( n==10 ) {
    result = log10( value );
    goto end;
}

if( n==11 ) {
    result = sin( value );
    goto end;
}

if( n==12 ) {
    result = sinh( value );
    goto end;
}

if( n==13 ) {
    result = sqrt( value );
    goto end;
}

if( n==14 ) {
    result = tan( value );
    goto end;
}

if( n==15 )
    result = tanh( value );

end:
return( result );

} /* Selection_Goto */



/*FN****************************************************************************
*
*   double Selection_Index( int n, double value )
*
*   Return:          Value of function number n
*
*   Purpose:         This function evaluates a value according to an integer
*                    that identifies it. This function is implemented using
*                    complex declarations.
*
*   Plan:            It is not necessary
*
*   Time to Develope: 3 minutes
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 06/14  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

double
Selection_Index( int n, double value )
{
static double (*function[])() = {
    acos, asin, atan, ceil, cos, cosh, exp, fabs,
    floor, log, log10, sin, sinh, sqrt, tan, tanh
};
    
return (*function[n])( value );

} /* Selection_Index */



/*****************************  Private Functions  ****************************/
