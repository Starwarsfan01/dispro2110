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
                                                                                 
/********************************** HEADERS ***********************************/                            
/* ------------------------ Inclusion of Std Headers ------------------------ */
#include <stdlib.h>
#include <stdio.h>   
#include "maze.h"   
/* ------------------------ Inclusion of Own Headers ------------------------ */
                                                                                                        
/****************************** SYMBOLIC CONSTANTS ****************************/
                                                                                                                      
/****************************** NEW TYPE DEFINITIONS **************************/
typedef enum {FW_check, RW_check, BW_check, LW_check, FORWARD, R_TURN, L_TURN } STATE_T;                                                                                 
                                                                                 
                                                                                 
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
                                                                                
int main( int argc, char** argv )                                                   
{                            
int FW =0;
int LW =0;
int RW =0;
int BW =0;
                                                   
STATE_T state;

Testing_Maze();                                                                          
               
state = FW_check;

                                                                 
while (Running() ) {
	switch(state){
		case FW_check:
			if(Is_There_Wall()){
				Robot(CLOCK_WISE);
				FW++;
				state=RW_check;
				}
			else{
				state=Forward();
				}
		break;
		case RW_check:
			if(Is_There_Wall()){
				Robot(CLOCK_WISE);
				RW++;
				state=BW_check;
				}
			else{
				state=Forward();
			}
		break;
		case BW_check:
			if(Is_There_Wall()){
				Robot(CLOCK_WISE);
				BW++;
				state=LW_check;
				}
			else{
				state=Forward();
			}
		break;
		case LW_check:
			if(Is_There_Wall()){
				Robot(CLOCK_WISE);
				LW++;
				state=FORWARD;
				}
		break;
		case FORWARD:
			if(FW==0){
				Forward();
				state=R_TURN;}
			else{
				LW=0;
				RW=0;
				BW=0;
				FW=0;
				state=FW_check;
		}
		break;
		case R_TURN:
			if(FW==1){
				Robot(COUNTER_CW);
				Forward();
				state=L_TURN;}
			else{                                                   
                                 LW=0;                                           
                                 RW=0;                                           
                                 BW=0;                                           
                                 FW=0;                                           
                                 state=FW_check;                                 
                 }
		break;
		case L_TURN:
			if(FW==1&&LW==1){
				Robot(CLOCK_WISE);
				Forward();
				state=FW_check;
				}
			else {
				LW=0;
				RW=0;
				BW=0;
				FW=0;
				state=FW_check;
			}		
		break; 
	}
}
Challenge_Was_Finished();
} /* main */

