/* Ruler 1         2         3         4         5         6         7        */

/* maze.c *********************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                     A-MAZE-(ing) CHALLENGE                 */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      This code was designed in order to teach skills     */
/*    │  │   │ ║  ║       to conceive, design and implement algorithms by     */
/*    │  │   │ ║  ║       using Concurrent Finite State Machines (FSM)        */
/*    │╔═╧══╗│ ║  ║                                                           */
/*    │╚╗  ╔╝┘ ║  ║                                                           */
/*    └┐║  ╚╗ ╔╝  ║       DEVELOPED BY: Ing. Juan C. Giraldo M.Sc             */
/*     └╚╗  ╚═╝  ╔╝                     jcgiraldo@javeriana.edu.co            */
/*      └╚╗     ╔╝                                                            */
/*        ╚═════╝         Bogota, D.C., September 5th, 2015.                  */
/*                                                                            */
/*          Copyright (C) Department de Electronics                           */
/*                        School of Engineering                               */
/*                        Pontificia Universidad Javeriana                    */
/*                        Bogota - Colombia - South America                   */
/*                                                                            */
/******************************************************************************/

#ifndef MAZE_H
#define MAZE_H

/* Following enumeration type specifies rotation of ROBOT and/or SONAR */

typedef enum { COUNTER_CW, CLOCK_WISE } ROTATION_T;

/* You can use following functions in your FSM source code as you wish */

int Is_There_Wall();
int Forward();
int Robot( ROTATION_T rotation );
int Sonar( ROTATION_T rotation );

/* Try not to remove or change following functions in your source code */

int Testing_Maze();
int Running();
int Challenge_Was_Finished();

#endif /* MAZE_H */
