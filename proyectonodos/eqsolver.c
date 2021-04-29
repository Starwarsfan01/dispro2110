/* Ruler 1         2         3         4         5         6         7        */
/******************************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                    [ titulo ]                              */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      DEVELOPED BY: Juan Sebastian Clavijo Martinez       */
/*    │  │   │ ║  ║             EMAIL : jsebastian.clavijoc@javeriana.edu.co  */
/*    │  │   │ ║  ║                                                           */
/*    │╔═╧══╗│ ║  ║       Bogota, D.C., 04/27/2021 08:37:11 PM                */
/*    │╚╗  ╔╝┘ ║  ║                                                           */
/*    └┐║  ╚╗ ╔╝  ║       Copyright (C) Electronic Engineering degree         */
/*     └╚╗  ╚═╝  ╔╝                     Faculty of Engineering                */
/*      └╚╗     ╔╝                      Pontifical Xaverian University        */
/*        ╚═════╝                       Bogota - Colombia                     */
/*                                                                            */
/******************************************************************************/
                                                                                 
/********************************** HEADERS ***********************************/                            
/* ------------------------ Inclusion of Std Headers ------------------------ */
#include <stdlib.h>
#include <stdio.h>      
/* ------------------------ Inclusion of Own Headers ------------------------ */
                                                                                                        
/****************************** SYMBOLIC CONSTANTS ****************************/
                                                                                                                      
/****************************** NEW TYPE DEFINITIONS **************************/
                                                                                 
                                                                                 
                                                                                 
/*************************** GLOBAL DATA DEFINITIONS **************************/
                                                                                 
/* ---------------------- Global Data in main program ----------------------- */
                                                                                
/****************************** FUNCTION PROTOTYPES ***************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
                                                                                
/* --------------------------- Public Functions 1 --------------------------- */

/******************************* Main Function ********************************/
/*   int main( int argc, char *argv[] )                                       */
/*                                                                            */
/*   Return:  Number "0" for succeed                                          */
/*                                                                            */
/*   Purpose:                                                                 */
/*                                                                            */
/*                                                                            */
/*   Plan: not necesary                                                       */
/*                                                                            */
/*   DATE          SUPERVISOR COMMENT                                         */
/*   ----------------------------------------------------------------------   */
/*   04/27/2021    J.Clavijo                                                  */
/*                                                                            */
/******************************************************************************/

static int  filas=3;
static int cols=3;
void RecolectarDatos(int *Dim , float[filas][cols],int filas,int cols);            
void ResuelveGauss(int Dim, float[filas][cols]);


int main(void)
{
    int C,Dimension=3;
    float Sistema[filas][cols];
    RecolectarDatos(&Dimension,Sistema,filas,cols);
    ResuelveGauss(Dimension,Sistema);
    printf("\n\n\nLas soluciones son:\n");
    for(C=1;C<=Dimension;C++) printf("\n X%d=%f\n",C,Sistema[C][Dimension+1]);
    return(0);
}

void RecolectarDatos(int *Dim, float Sist[filas][cols],int filas,int cols)
{
	for(int f=1;f<=filas;f++)
	{
		for(int c=1;c<=cols;c++)
		{
			printf("ingrese el elemento %d,%d: ",f,c);
			scanf("%f",&Sist[f][c]);
			printf("\n");
		}
	}
	printf("\n\n\n VECTOR B:\n");
    	for(int A=1;A<=*Dim;A++){
        printf("\n Termino B(%d):",A);scanf("%f",&Sist[A][*Dim+1]);}
}



void ResuelveGauss(int Dim, float Sist[][cols])
{
    int NoCero,Col,C1,C2,A;
    float Pivote,V1;
   
    for(Col=1;Col<=Dim;Col++){
        NoCero=0;A=Col;
        while(NoCero==0){
           if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001))){
                NoCero=1;}
            else A++;}
        Pivote=Sist[A][Col];
        for(C1=1;C1<=(Dim+1);C1++){
            V1=Sist[A][C1];
            Sist[A][C1]=Sist[Col][C1];
            Sist[Col][C1]=V1/Pivote;}
        for(C2=Col+1;C2<=Dim;C2++){
            V1=Sist[C2][Col];
            for(C1=Col;C1<=(Dim+1);C1++){
                Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];}
    }}
   
    for(Col=Dim;Col>=1;Col--) for(C1=(Col-1);C1>=1;C1--){
        Sist[C1][Dim+1]=Sist[C1][Dim+1]-Sist[C1][Col]*Sist[Col][Dim+1];
        Sist[C1][Col]=0;
    }
}


