#include <stdio.h>
#include <ctype.h>

#define SPACE      32 /* ASCII of space  */
#define DELIMITER 124 /* ASCII of pipe "|" Use 179 in case of extended */
#define FRAME     124 /* ASCII of pipe "|" Use 186 in case of extended */

char *no_graph[] = {
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS ", "HT ", "LF ", "VT ", "FF ", "CR ", "SO ", "SI ",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM ", "SUB", "ESC", "FS ", "GS ", "RS ", "US ",
    "SP "
};


/*FN****************************************************************************
 
   main()
 
   Return:   void
 
   Purpose:  Print an ASCII table indicating the use of some functions/macros

   Register of Revisions:

   DATE       RESPONSIBLE  COMMENT
   -----------------------------------------------------------------------
   Oct 12/14  J.C.Giraldo  Header and documentation
   Jul 01/07  J.C.Giraldo  Initial implementation

*******************************************************************************/

int
main()
{
unsigned int i;

/* Print the header of table */
    
printf( "\t\t\t*---*---*---*---*---*---*---*---*---*---*---*---*\n" );
printf( "\t\t\t|   |   |   |   |   |   |   |   |   |   |   | i |\n" );
printf( "\t\t\t| i | i | i | i | i | i | i | i | i | i | i | s |\n" );
printf( "\t\t\t| s | s | s | s | s | s | s | s | s | s | s | x |\n" );
printf( "\t\t\t| a | a | a | c | d | g | l | p | p | s | u | d |\n" );
printf( "\t\t\t| l | l | s | n | i | r | o | r | u | p | p | i |\n" );
printf( "\t\t\t| n | p | c | t | g | a | w | i | n | a | p | g |\n" );
printf( "\t\t\t| u | h | i | r | i | p | e | n | c | c | e | i |\n" );
printf( "\t\t\t| m | a | i | l | t | h | r | t | t | e | r | t |\n" );
printf( "\t\t\t*---*---*---*---*---*---*---*---*---*---*---*---*\n" );

/* Print ASCII table indicating with "x" if ASCII code matches upper macro */

for( i=0; i<=127; i++ ) {

/* Print left part of table, taking into account if code is non-printable */
    
    if( i==127 )
        printf("%d\t%X\t%s\t%c", i, i, "DEL", FRAME );
    else if( isgraph(i) )
        printf("%d\t%X\t%c\t%c", i, i, i, FRAME );
    else
        printf("%d\t%X\t%s\t%c", i, i, no_graph[i], FRAME );

/* Print right part of table for every single ASCII code from 0 to 127 */

    if( isalnum(i)) printf( " X %c", DELIMITER );
        else printf( "   %c", DELIMITER );
    if( isalpha(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( isascii(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( iscntrl(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( isdigit(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( isgraph(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( islower(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( isprint(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( ispunct(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( isspace(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( isupper(i)) printf( " X %c", DELIMITER );
		else printf( "   %c", DELIMITER );
    if( isxdigit(i)) printf( " X %c\n", FRAME );
		else printf( "   %c\n", FRAME );
}

/* Print tail of table */

printf( "\t\t\t*---*---*---*---*---*---*---*---*---*---*---*---*\n" );

return( 0 );

} /* main */
