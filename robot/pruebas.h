/* Ruler 1         2         3         4         5         6         7        */
/******************************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                   A-maze-ing challenge                     */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      DEVELOPED BY: Juan Sebastian Clavijo Martinez       */
/*    │  │   │ ║  ║             EMAIL : jsebastian.clavijoc@javeriana.edu.co  */
/*    │  │   │ ║  ║                                                           */
/*    │╔═╧══╗│ ║  ║       Bogota, D.C., 04/15/2021 09:09:51 AM                */
/*    │╚╗  ╔╝┘ ║  ║                                                           */
/*    └┐║  ╚╗ ╔╝  ║       Copyright (C) Electronic Engineering degree         */
/*     └╚╗  ╚═╝  ╔╝                     Faculty of Engineering                */
/*      └╚╗     ╔╝                      Pontifical Xaverian University        */
/*        ╚═════╝                       Bogota - Colombia                     */
/*                                                                            */
/******************************************************************************/
                                                                                 
/**********************************HEADERS***********************************/                            
/* ------------------------ Inclusion of Std Headers ------------------------ */
#include <stdlib.h>
#include <stdio.h>   
#include "maze.h"   
/* ------------------------ Inclusion of Own Headers ------------------------ */
                                                                                                        
/****************************** SYMBOLIC CONSTANTS ****************************/
                                                                                                                      
/****************************** NEW TYPE DEFINITIONS **************************/
typedef enum {forward} STATE_A;                                                                                 
                                                                                 
                                                                                 
/**************************  GLOBAL DATA DEFINITIONS **************************/
                                                                                 
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
/*   04/15/2021    J.Clavijo                                                  */
/*                                                                            */
/******************************************************************************/
                                                                                
int pruebas_robot()                                                   
{                            
static int FW =0;
static int LW =0;
static int RW =0;
                                                   
static STATE_A state= forward;
                                                      
           

                                                                 
if (TRUE) {
	switch(state){
	case forward:
		if(Is_There_Wall(PRUEBAS))
		{
			Forward(PRUEBAS);
		}
		break;
	}
}
} /* main */

