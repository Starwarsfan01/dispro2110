#include<stdio.h> //importa la libreria standard-input output
#include <stdlib.h>//importa la libreris STANDard
int main(int argc, char *argv[])//inicio de la funcion main con los argumentos de siempre
{
FILE *ptr_file_in, *ptr_file_out;//tipo de dato FILE con apuntadores para leer archivos
int numero; //variable de tipo entero llamada numero 

ptr_file_in = fopen( argv[1], "r");//se abre el archivo con la funcion fopen, argv[1] se refiere al primer archivo que se pone para leer, la r indica estado de 'read'
if(ptr_file_in == NULL ){ 
     fprintf( stderr,"\nError abriendo el archivo\n");//si el archivo es nulo imprima error 
	 exit(1);
}

ptr_file_out = fopen( argv[2], "w"); //el segundo archivo es al que se va a escribir (la 'w')
if( ptr_file_out == NULL){
     fprintf(stderr, "Error abriendo el archivo\n");//si el archivo es nulo imprima error
	 exit(1);
}

while( (numero= fgetc( ptr_file_in ))!= EOF)
	  fputc( numero, ptr_file_out);
fclose( ptr_file_in);
fclose( ptr_file_out);

/*
 *[while] mientras que numero guarde todos los caracteres del arch. de entrada 
 *y no llegue al End Of File.
 *[fputc] ponga los contenidos de numero en el arch. de salida.
 *[fclose ambos] cierra ambos archivos.
 * */
return 0;

}
