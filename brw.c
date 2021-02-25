/******************************************************************************/
/*                                                                            */
/* For testing purposes you may execute program as it is shown next:          */
/*                                                                            */
/* A CONTINUACION USARE ESPANOL POR CLARIDAD:                                 */
/*                                                                            */
/* ENTRADA REDIRECCIONADA DE FLUJO PROVENIENTE DE PROGRAMA Y SALIDA STANDARD: */
/* (Se usa "pipe" para conectar salida de un programa con entrada a otro)     */
/* type file_in | brw <ENTER>                                                 */
/*                                                                            */
/* ENTRADA CON REDIRECCION DE FLUJO PROVENIENTE DE ARCHIVO Y SALIDA STANDARD: */
/* (Aqui se usa conector "<" de redireccion de entrada)                       */
/* brw <file_in <ENTER>                                                       */
/* brw <file_in >file_out <ENTER>                                             */
/*                                                                            */
/* ENTRADA DEFINIDA POR USUARIO Y SALIDA STANDARD (por defecto a pantalla):   */
/* brw  file_in <ENTER>                                                       */
/*                                                                            */
/* ENTRADA DEFINIDA POR USUARIO Y SALIDA CONECTADA A UN ARCHIVO:              */
/* brw  file_in >file_out <ENTER>                                             */
/*                                                                            */
/* ENTRADA Y SALIDA DEFINIDAS POR USUARIO (No aplica flujo standard):         */
/* brw  file_in  file_out <ENTER>                                             */
/*                                                                            */
/******************************************************************************/

/********************************** Headers ***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**************************** Symbolic  Constants *****************************/

#define MAX_STRING     256
#define BYTES_PER_LINE  16

/************************** Definition of Data Type ***************************/

typedef unsigned char BYTE_T;



int
main( int argc, char *argv[] )
{
FILE *ifp, *ofp;
void Hexdump( FILE *ifp, FILE *ofp );

if( argc == 1 )
    Hexdump( stdin, stdout );
else if( argc == 2 ) {
    if( ( ifp = fopen( argv[1], "rb" ) ) == NULL ) {
        fprintf( stderr, "can't open %s\n", argv[1] );
        return 1;
    }
    Hexdump( ifp, stdout );
    fclose( ifp );
}
else if( argc == 3 ) {
    if( ( ifp = fopen( argv[1], "rb" ) ) == NULL ) {
        fprintf( stderr, "can't open %s\n", argv[1] );
        return 1;
    }
    if( ( ofp = fopen( argv[2], "w" ) ) == NULL ) {
        fprintf( stderr, "can't open %s\n", argv[2] );
        return 1;
    }
    Hexdump( ifp, ofp );
    fclose( ifp );
    fclose( ofp );
}
else
    fprintf( stderr, "Usage: %s [ file_in [ file_out ] ]\n", argv[0] );

return 0;

} /* main */



/*FN****************************************************************************
*
*   void Hexdump( FILE *ifp, FILE *ofp )
*
*   Return:  Nothing
*
*   Purpose: Read binary or text file from ifp and send output to ofp
*            in three (3) sections:
*            (1) It is shown the address of first byte per line
*            (2) Every byte in shown in hexa
*            (3) If every byte is a printed ASCII code, it is displayed,
*                otherwise a period is printed
*
*   Plan:
*           For every number of bytes read specified in BYTES_PER_LINE:
*           Part 1.0: Print counter
*           Part 2.1: Print bytes in hexa
*           Part 2.2: Print spaces (in case of reaching last bytes of stdin)
*           Part 3.0: Print bytes in ASCII
*           Part 4.0: Increment counter
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 01/14  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

void
Hexdump( FILE *ifp, FILE *ofp )
{
BYTE_T   buffer[MAX_STRING];
int      bytes_read;
int      i;
long int bytes_counter = 0;

do {
    bytes_read = fread( buffer, sizeof(BYTE_T), BYTES_PER_LINE, ifp );

/* Part 1.0: Print counter */

    fprintf( ofp, "%06lX: ", bytes_counter );

/* Part 2.1: Print bytes in hexa */

    for( i=0; i < bytes_read; i++ )
        fprintf( ofp, "%02X ", buffer[i] );

/* Part 2.2: Print spaces (in case of reaching last bytes of stdin) */

    for( i=0; i < BYTES_PER_LINE-bytes_read; i++ )
        fprintf( ofp, "   " );

/* Part 3.0: Print bytes in ASCII */

    for( i=0; i < bytes_read; i++ )
        fprintf( ofp, "%c", isprint(buffer[i]) ? buffer[i] : '.' );
    fprintf( ofp, "\n" );

/* Part 4.0: Increment counter */

    bytes_counter += BYTES_PER_LINE;

} while( bytes_read == BYTES_PER_LINE );

} /* Hexdump */
