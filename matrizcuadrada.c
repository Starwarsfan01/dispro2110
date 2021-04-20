/* Ruler 1         2         3         4         5         6         7        */
/******************************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                   matrizcuadrada                          */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      DEVELOPED BY: Juan Sebastian Clavijo Martinez       */
/*    │  │   │ ║  ║             EMAIL : jsebastian.clavijoc@javeriana.edu.co  */
/*    │  │   │ ║  ║                                                           */
/*    │╔═╧══╗│ ║  ║       Bogota, D.C., 03/23/2021 09:11:53 AM                */
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
#define ROWS 100
#define COLS 100                                                                                 
/* ---------------------- Global Data in main program ----------------------- */
double matriz[ROWS][COLS];   
                                                                            
/****************************** FUNCTION PROTOTYPES ***************************/
int llenarmatriz(int maxrows,int maxcols,double mtx[ROWS][COLS]);                                                           
/*                                                                            */
/*                                                                            */
/******************************************************************************/
                                                                                
/* --------------------------- Public Functions 1 --------------------------- */

/*FN****************************************************************************
 *                                                                               
 *   prototype void llenarmatriz ()                               
 *                                                                               
 *   Return:                                                                     
 *                                                                               
 *   Purpose:                                                                    
 *                                                                               
 *   Plan:                                                                       
 *                                                                               
 *   Register of Revisions:                                                      
 *                                                                               
 *   DATE       SUPERVISOR   COMMENT                                             
 *   -----------------------------------------------------------------------     
 *   03/23/2021     J.Clavijo    Initial implementation                              
 *                                                                               
 ******************************************************************************/
int  llenarmatriz ( int maxrows,int maxcols,double mtx[ROWS][COLS])
{
	for (int i=0;i<maxrows;i++){
		for (int j=0;j<maxcols;j++){
			mtx[i][j]=0.0;
		}
}
	}
}
	return 1;
}/* -----  end of llenarmatriz  ----- */

/* ************************************************************************** */
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
/*   03/23/2021    J.Clavijo                                                  */
/*                                                                            */
/******************************************************************************/
                                                                                
int main( int argc, char** argv )                                                   
{                                                                                  
llenarmatriz();
} /* main */

