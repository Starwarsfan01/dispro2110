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
typedef enum {ADELANTE, LADOS, 180NOSCPE} STATE_T;
                                                                    
                                                                                 
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
                                                                                
int jsebastian_dot_clavijoc_robot(){
   static STATE_T state=ADELANTE;


   if(TRUE)
   {
       switch(state)
       {
            case ADELANTE:
                if(Is_There_Wall(JSEBASTIAN_DOT_CLAVIJOC))
                {
                	Robot(JSEBASTIAN_DOT_CLAVIJOC,COUNTER_CW);
                    	state=LADOS;
                    
                }//if(Is_There_Wall())
                else
                {
                    Forward(JSEBASTIAN_DOT_CLAVIJOC);
                    state=ADELANTE;
                }//else=>if(Is_There_Wall())
            break;

            case LADOS:
                if(!Is_There_Wall(JSEBASTIAN_DOT_CLAVIJOC))
                {
                    Forward(JSEBASTIAN_DOT_CLAVIJOC);
                    Sonar(JSEBASTIAN_DOT_CLAVIJOC,CLOCK_WISE);
                    state=180NOSCPE;
                }
                else
                {
                    Robot(JSEBASTIAN_DOT_CLAVIJOC,COUNTER_CW);
                    state=LADOS;
                }//else=>if(Is_There_Wall())
            break;

            case 180NOSCPE:
                if(!Is_There_Wall(JSEBASTIAN_DOT_CLAVIJOC))
                {
                    Robot(JSEBASTIAN_DOT_CLAVIJOC,CLOCK_WISE);
                    Forward(JSEBASTIAN_DOT_CLAVIJOC);
                    Robot(JSEBASTIAN_DOT_CLAVIJOC,CLOCK_WISE);
                    Sonar(JSEBASTIAN_DOT_CLAVIJOC,COUNTER_CW);
                    state=LADOS;
                }
                else
                {
                    Sonar(JSEBASTIAN_DOT_CLAVIJOC,COUNTER_CW);
                    state=LADOS;
                }//else=>if(Is_There_Wall())
            break;
//RETROCEDER
       }//switch(state)
   }//while(Running())
}//main()
