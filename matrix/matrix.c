/* Ruler 1         2         3         4         5         6         7        */

/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */

#include <stdlib.h> // Due to exit
#include <stdio.h>  // Due to fprintf

/* ------------------------ Inclusion of Own Headers ------------------------ */

#include "matrix.h"


/************************** Prototypes of Functions ***************************/

/* --------------------------- Private Functions ---------------------------- */



/************************ Definition of the Structures ************************/



/************************** Definitions of Functions **************************/

/* ---------------------------- Public Functions ---------------------------- */

/*FN****************************************************************************
*
*   int Mtx_Zero( double mtx[][COLS], int max_i, int max_j );
*
*   Return:  Number "1" for SUCCEED
*
*   Purpose:
*
*   Plan:    It is not necessary
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Spt 30/17  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Mtx_Zero(
double mtx[][COLS], /* In/Out: Matrix to be initiated */
int    max_i,       /* In:     Number of rows         */
int    max_j )      /* In:     Number of columns      */
{
register int jj;
register int ii;

for( ii = 0; ii < max_i; ii++ )
    for( jj = 0; jj < max_j; jj++ )
        mtx[ii][jj] = 0.0;

return 1;

} /* Mtx_Zero */



/*FN****************************************************************************
*
*   int Show_Mtx_Screen( double (*mtx)[COLS],
*                        int mtx_rows, int mtx_cols, char digits );
*
*   Return:    Number "1" for SUCCEED
*
*   Purpose:   This function displays the contents of a bidimensional array.
*              The desired number of significant digits must be specified.
*              This parameter can be any number between 2 and 18 inclusive,
*              otherwise it will be used by default 3 significant digits.
*
*   Versions:
*         Version 1: Output to standard file (similar to Write_Mtx_Text)
*         Version 2: Output to screen with arrows
*
*   Notes:     - The literal constant 8 specifies the lowest number of
*                characters needed, besides the number of specified digits.
*                The next number in addition to the 3 digits, needs space
*                for 7 additional characters: -1.11E+300 and an extra space.
*              - It doesn't need a file name because output goes to screen.
*              - It has been checked before that the size of input file is
*                adequate.
*              - Include "conio.h", "dos.h"
*
*   Improvement Plan:
*              - Implement functions for Cursor_On and Cursor_Off
*              - Implement HELP
*              - With "mouse" and scroll bars
*              - Output to printer properly formatted
*
*   Plan:
*           Part 1: Compute "width_value" from specified number of "digits"
*           Part 2: Output row by row according to specified "mtx_cols"
*
*   Registro of Revisiones:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Jul 01/07  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Show_Mtx_Screen(
double mtx[][COLS], /* In: Matrix to be printed */
int    mtx_rows,    /* In: Number of rows       */
int    mtx_cols,    /* In: Number of columns    */
char   digits )     /* In: Accuracy in number of significant digits */
{
register int jj,  /* Index for marching through columns */
             ii;  /* Index for marching through rows    */
char width_value; /* Width between two values */

/* Part 1: Compute "width_value" from specified number of "digits" */

if( digits<LOWER_ACCURACY || digits>UPPER_ACCURACY )
    digits = DEFAULT_ACCURACY;

width_value = digits + CHARS_PLUS_ONE;

/* Part 2: Output row by row according to specified "mtx_cols" */

for( ii = 0; ii < mtx_rows; ii++ )
    for( jj = 0; jj < mtx_cols; jj++ )
        fprintf( stdout, "%*.*E%c",
                width_value, digits, mtx[ii][jj], (jj+1)%mtx_cols?' ':'\n' );

return 1;

} /* Show_Mtx_Screen */
