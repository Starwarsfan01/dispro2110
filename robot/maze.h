/* Ruler 1         2         3         4         5         6         7        */

/* maze.h *********************************************************************/
/*                                                                            */
/*   +----+ +----+                     A-MAZE-(ing) CHALLENGE                 */
/*   ++  ++ ++******                                                          */
/*    |  |   |**  **      This code was designed in order to teach skills     */
/*    |  |   | *  *       to conceive, design and implement algorithms by     */
/*    |  |   | *  *       using Concurrent Finite State Machines (FSM)        */
/*    |******| *  *                                                           */
/*    |**  **| *  *                                                           */
/*    ++*  ** **  *       DEVELOPED BY: Ing. Juan C. Giraldo M.Sc             */
/*     +**  ***  **                     jcgiraldo@javeriana.edu.co            */
/*      +**     **                                                            */
/*        *******         Bogota, D.C., October 30th, 2020.                   */
/*                                                                            */
/*          Copyright (C) Departament de Electronics                          */
/*                        School of Engineering                               */
/*                        Pontificia Universidad Javeriana                    */
/*                        Bogota - Colombia - South America                   */
/*                                                                            */
/******************************************************************************/

#ifndef MAZE_H
#define MAZE_H

/* ------------- Declaration of BOOLEAN type in case of needing ------------- */

typedef enum { FALSE, TRUE } BOOLEAN;

/* --------- Following type specifies rotation of ROBOT and/or SONAR -------- */

typedef enum { COUNTER_CW, CLOCK_WISE } ROTATION_T;

/* --------- Functions to command concurrent robots inside the maze ---------- */

BOOLEAN Is_There_Wall( int robot_id );
int Forward( int robot_id );
int Robot( int robot_id, ROTATION_T rotation );
int Sonar( int robot_id, ROTATION_T rotation );

/* -------------- Functions to be used when you code your FSM --------------- */

BOOLEAN Running();
int Testing_Maze();
int Challenge_Was_Finished();

#endif /* MAZE_H */
