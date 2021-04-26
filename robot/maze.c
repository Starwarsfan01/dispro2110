/* Ruler 1         2         3         4         5         6         7        */

/* maze.c *********************************************************************/
/*                                                                            */
/*   +----+ +----+                     A-MAZE-(ing) CHALLENGE                 */
/*   ++  ++ ++******                                                          */
/*    |  |   |**  **      This code was designed in order to teach skills     */
/*    |  |   | *  *       to conceive, design and implement algorithms by     */
/*    |  |   | *  *       using Concurrent Finite State Machines (FSM)        */
/*    |******| *  *                                                           */
/*    |**  **| *  *                                                           */
/*    ++*  ** **  *       DEVELOPED BY: Ing. Juan C. Giraldo, Ph.D.           */
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

/* --------------------- Inclusion of Standard Headers ---------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* -------------------- Inclusion of Propietary Headers --------------------- */

#include "maze.h"

/* -------------- Configuration according to Operative System --------------- */

#define LINUX        /* Delete this line if your system is a windows-based PC */



/* --------------------- Arrays to define map for Maze ---------------------- */

#define MAZE_ROWS 45                 /* Maximum number of rows in map of maze */
#define MAZE_COLS 31                 /* Maximum number of cols in map of maze */

#define CON_ROWS (MAZE_ROWS)             /* Maximum number of rows in console */
#define CON_COLS (2*MAZE_COLS+1)         /* Maximum number of cols in console */

#define SCALE 2       /* Factor scale to advance one step forward inside maze */



/* Copy these suggested initial positions for next maze ************************
Initiate_Robot( 0, robot,  2,  8, LEFT,  LEFT  );
Initiate_Robot( 1, robot,  2, 12, RIGHT, RIGHT );
Initiate_Robot( 2, robot, 18,  8, LEFT,  LEFT  );
Initiate_Robot( 3, robot, 18, 12, RIGHT, RIGHT );
*******************************************************************************/

static char my_maze[MAZE_ROWS][MAZE_COLS] = {
    
/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 02 */ { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
/* 03 */ { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 04 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 05 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 06 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 07 */ { 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0 },
/* 08 */ { 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
/* 09 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 10 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 11 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 12 */ { 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
/* 13 */ { 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0 },
/* 14 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 15 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 16 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 17 */ { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 18 */ { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
/* 19 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};



/* Copy these suggested initial positions for next maze ************************
Initiate_Robot( 0, robot,  6,  4,   UP,   UP );
Initiate_Robot( 1, robot,  6, 16,   UP,   UP );
Initiate_Robot( 2, robot, 14,  4, DOWN, DOWN );
Initiate_Robot( 3, robot, 14, 16, DOWN, DOWN );
*******************************************************************************/

static char my_maze_1[MAZE_ROWS][MAZE_COLS] = {

/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 02 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 03 */ { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 04 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 05 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 06 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 07 */ { 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
/* 08 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 09 */ { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 10 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 11 */ { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 12 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 13 */ { 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
/* 14 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 15 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 16 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 17 */ { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 18 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 19 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};



/* Copy these suggested initial positions for next maze ************************
Initiate_Robot( 0, robot,  4, 10, DOWN,   DOWN );
Initiate_Robot( 1, robot, 10, 16, LEFT,   LEFT );
Initiate_Robot( 2, robot, 16, 10, UP,       UP );
Initiate_Robot( 3, robot, 10,  4, RIGHT, RIGHT );
*******************************************************************************/

static char my_maze_2[MAZE_ROWS][MAZE_COLS] = {

/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 02 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 03 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 04 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 05 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 06 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 07 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 08 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 09 */ { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
/* 10 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 11 */ { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
/* 12 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 13 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 14 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 15 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 16 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 17 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 18 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 19 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};



/* Copy these suggested initial positions for next maze ************************
Initiate_Robot( 0, robot,  2,  8, DOWN, DOWN );
Initiate_Robot( 1, robot,  2, 12, DOWN, DOWN );
Initiate_Robot( 2, robot, 18,  8, UP,   UP   );
Initiate_Robot( 3, robot, 18, 12, UP,   UP   );
*******************************************************************************/

static char my_maze_3[MAZE_ROWS][MAZE_COLS] = {

/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 02 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 03 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 04 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 05 */ { 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0 },
/* 06 */ { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
/* 07 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 08 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 09 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 10 */ { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
/* 11 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 12 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 13 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 14 */ { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
/* 15 */ { 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0 },
/* 16 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 17 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 18 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 19 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};



/* Copy these suggested initial positions for next maze ************************
Initiate_Robot( 0, robot,  2,  6, RIGHT, RIGHT );
Initiate_Robot( 1, robot,  2, 14, LEFT,  LEFT  );
Initiate_Robot( 2, robot, 18,  6, RIGHT, RIGHT );
Initiate_Robot( 3, robot, 18, 14, LEFT,  LEFT  );
*******************************************************************************/

static char my_maze_40[MAZE_ROWS][MAZE_COLS] = {

/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 02 */ { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
/* 03 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 04 */ { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
/* 05 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 06 */ { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
/* 07 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 08 */ { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
/* 09 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 10 */ { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
/* 11 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 12 */ { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
/* 13 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 14 */ { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
/* 15 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 16 */ { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
/* 17 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 18 */ { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
/* 19 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};



/* Copy these suggested initial positions for next maze ************************
#define MAZE_ROWS 23
#define MAZE_COLS 45
Initiate_Robot( 0, robot,  2,  6, RIGHT, RIGHT );
Initiate_Robot( 1, robot,  2, 14, LEFT,  LEFT  );
Initiate_Robot( 2, robot, 18,  6, RIGHT, RIGHT );
Initiate_Robot( 3, robot, 18, 14, LEFT,  LEFT  );
*******************************************************************************/

static char my_maze_pacman_5[MAZE_ROWS][MAZE_COLS] = {

/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 02 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 03 */ { 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
/* 04 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 05 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 06 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 07 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 08 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 09 */ { 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
/* 10 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 11 */ { 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
/* 12 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 13 */ { 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
/* 14 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 15 */ { 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
/* 16 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 17 */ { 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 18 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 19 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 21 */ { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
/* 22 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 23 */ { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
/* 24 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 25 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 26 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 27 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 28 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 29 */ { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
/* 30 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 31 */ { 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
/* 32 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
/* 33 */ { 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
/* 34 */ { 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
/* 35 */ { 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0 },
/* 36 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
/* 37 */ { 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0 },
/* 38 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 39 */ { 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 40 */ { 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
/* 41 */ { 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 42 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 43 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 44 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};



/* Copy these suggested initial positions for next maze ************************
#define MAZE_ROWS 31
#define MAZE_COLS 45
Initiate_Robot( 0, robot,  2,  6, RIGHT, RIGHT );
Initiate_Robot( 1, robot,  2, 14, LEFT,  LEFT  );
Initiate_Robot( 2, robot, 18,  6, RIGHT, RIGHT );
Initiate_Robot( 3, robot, 18, 14, LEFT,  LEFT  );
*******************************************************************************/

static char my_maze_9[MAZE_ROWS][MAZE_COLS] = {

/*        00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 */
/* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 01 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 02 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 03 */ { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 04 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 05 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 06 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 07 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 08 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 09 */ { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 10 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 11 */ { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 12 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 13 */ { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 14 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 15 */ { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 16 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 17 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 18 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 19 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 20 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 21 */ { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 22 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* 23 */ { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 24 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 25 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 26 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 27 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 28 */ { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
/* 29 */ { 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 30 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 31 */ { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 32 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
/* 33 */ { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 34 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
/* 35 */ { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
/* 36 */ { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
/* 37 */ { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0 },
/* 38 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 39 */ { 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 40 */ { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
/* 41 */ { 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
/* 42 */ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
/* 43 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
/* 44 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};


/* Buffer to display the map of maze in stdout through ASCII chars */

static char console_buf[CON_ROWS][CON_COLS];



/* --------------------- Array to define Robots status ---------------------- */

/* Declaration of enumeration type for normalized unitary vector */

typedef enum { LEFT, RIGHT, DOWN, UP } DIRECTION_T;

/* Declaration of robot status */

typedef struct {
    char ubication[2]; /* Absolute location in maze */
    char direction[2]; /* Normalized robot direction */
    char dir_sonar[2]; /* Normalized sonar direction */
} ROBOT_T;

#define MAX_ROBOTS 4

ROBOT_T robot[MAX_ROBOTS];

static int step = 0;

char motion[4] = { 45, 92, 124, 47 }; /* Sequence: -, \, |, / */

double delay = 0.2; /* Delay between movements */



/* ---------------------- Prototypes of Hiden Functions --------------------- */

/* Hiding info */

BOOLEAN Any_Obstacle( int robot_id, ROBOT_T robot[], char maze[][MAZE_COLS] );
int Step_Forward( int robot_id, ROBOT_T robot[], char maze[][MAZE_COLS] );
int Rotate_Robot( int robot_id, ROBOT_T robot[], ROTATION_T rotation );
int Rotate_Sonar( int robot_id, ROBOT_T robot[], ROTATION_T rotation );

/* Other functions */

int Initiate_Robot( int robot_id, ROBOT_T robot[], char pos_x, char pos_y,
                   DIRECTION_T platform, DIRECTION_T sonar );
int Initiate_Maze( char console_buf[][CON_COLS], char maze[][MAZE_COLS] );
int Refresh_Maze( ROBOT_T robot[], char console_buf[][CON_COLS] );
int Report_Robot( int robot_id, ROBOT_T robot[] );
int Wall_Was_Hit();



/*FN****************************************************************************
*
*   BOOLEAN Running();
*
*   Return:  Nothing
*
*   Purpose: Determine condition to stop FSM
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

BOOLEAN
Running()
{
BOOLEAN current_robot_inside, all_robots_inside = TRUE;

for( int i=0; i<MAX_ROBOTS; i++ ) {

    current_robot_inside =
    (robot[i].ubication[0] > 0 &&
     robot[i].ubication[1] > 0 &&
     robot[i].ubication[0] < (MAZE_ROWS-1) &&
     robot[i].ubication[1] < (MAZE_COLS-1));

    all_robots_inside = all_robots_inside && current_robot_inside;

    if( current_robot_inside == FALSE )
        fprintf( stdout, "ROBOT NUMBER %d COULD GET OUT OF MAZE\n", i );

}

return ( all_robots_inside );

} /* Running */



/*FN****************************************************************************
*
*   int Testing_Maze();
*
*   Return:  Nothing
*
*   Purpose: Prepare robots
*
*   Plan:
*           Part 1: Set initial values for every robot
*           Part 2: Initiate buffer of maze in text mode from a map
*           Part 3: Update maze with robots in standard output
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Testing_Maze()
{

/* Part 1: Set initial values for every robot */

/******************************************************************************/
/*     Number of Initiate_Robot() functions must match MAX_ROBOTS             */
/*     Robot ID (first parameter) must use consecutive numbers since zero     */
/*     Robot position (third and forth parameters) must be even numbers       */
/******************************************************************************/

Initiate_Robot( 0, robot,  2,  6, RIGHT, RIGHT );
Initiate_Robot( 1, robot,  2, 14, LEFT,  LEFT  );
Initiate_Robot( 2, robot, 18,  6, RIGHT, RIGHT );
Initiate_Robot( 3, robot, 18, 14, LEFT,  LEFT  );
/* Part 2: Initiate buffer of maze in text mode from a map */

Initiate_Maze( console_buf, my_maze );

/* Part 3: Update maze with robots in standard output */

Refresh_Maze( robot, console_buf );

return 1;

} /* Testing_Maze */



/* Definition of functions */

/*FN****************************************************************************
*
*   int Initiate_Robot( int robot_id, ROBOT_T robot[], char pos_x, char pos_y,
*                       DIRECTION_T platform, DIRECTION_T sonar );
*
*   Return:  Nothing
*
*   Purpose: Set initial values for a robot
*
*   Plan:
*           Part 1: Set initial location of robot in the maze
*           Part 2: Set initial direction of platform
*           Part 3: Set initial direction of sonar
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Initiate_Robot(
int         robot_id,   /* In:  ID for a robot */
ROBOT_T     robot[],    /* Out: Structure of robot status  */
char pos_x, char pos_y, /* In:  Position of robot in maze  */
DIRECTION_T platform,   /* In:  Platform unitary direction */
DIRECTION_T sonar )     /* In:  Sonar unitary direction    */
{

/* Part 1: Set initial location of robot in the maze */

robot[robot_id].ubication[0] = pos_x;
robot[robot_id].ubication[1] = pos_y;

/* Part 2: Set initial direction of platform */

if( platform == UP )
    robot[robot_id].direction[0] = -1, robot[robot_id].direction[1] =  0;
else if( platform == DOWN )
    robot[robot_id].direction[0] =  1, robot[robot_id].direction[1] =  0;
else if( platform == RIGHT )
    robot[robot_id].direction[0] =  0, robot[robot_id].direction[1] =  1;
else if( platform == LEFT )
    robot[robot_id].direction[0] =  0, robot[robot_id].direction[1] = -1;

/* Part 3: Set initial direction of sonar */

if( sonar == UP )
    robot[robot_id].dir_sonar[0] = -1, robot[robot_id].dir_sonar[1] =  0;
else if( sonar == DOWN )
    robot[robot_id].dir_sonar[0] =  1, robot[robot_id].dir_sonar[1] =  0;
else if( sonar == RIGHT )
    robot[robot_id].dir_sonar[0] =  0, robot[robot_id].dir_sonar[1] =  1;
else if( sonar == LEFT )
    robot[robot_id].dir_sonar[0] =  0, robot[robot_id].dir_sonar[1] = -1;

return 1;

} /* Initiate_Robot */



/*FN****************************************************************************
*
*   BOOLEAN Is_There_Wall( int robot_id );
*
*   Return:  Nothing
*
*   Purpose: Query for obstacle in front HIDING INFORMATION
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

BOOLEAN
Is_There_Wall(
int robot_id ) /* In: ID for a robot */
{
return( Any_Obstacle( robot_id, robot, my_maze ) );
    
} /* Is_There_Wall */



/*FN****************************************************************************
*
*   BOOLEAN
*   Any_Obstacle( int robot_id, ROBOT_T robot[], char maze[][MAZE_COLS] );
*
*   Return:  Nothing
*
*   Purpose: Query for obstacle in front
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

BOOLEAN
Any_Obstacle(
int     robot_id,           /* In: ID for a robot */
ROBOT_T robot[],            /* In: Robot status */
char    maze[][MAZE_COLS] ) /* In: Map of maze  */
{
char wall_x,  wall_y;
char robot_x, robot_y;
BOOLEAN hit_any_robot = FALSE;

wall_x  = robot[robot_id].ubication[0] + robot[robot_id].dir_sonar[0];
wall_y  = robot[robot_id].ubication[1] + robot[robot_id].dir_sonar[1];

robot_x = robot[robot_id].ubication[0] + SCALE * robot[robot_id].dir_sonar[0];
robot_y = robot[robot_id].ubication[1] + SCALE * robot[robot_id].dir_sonar[1];

for( int i=0; i<MAX_ROBOTS; i++ ) {

    hit_any_robot = hit_any_robot ||
    (robot_x == robot[i].ubication[0] && robot_y == robot[i].ubication[1]);

}

return (BOOLEAN)maze[wall_x][wall_y] || hit_any_robot;

} /* Any_Obstacle */



/*FN****************************************************************************
*
*   int Forward( int robot_id );
*
*   Return:  Nothing
*
*   Purpose: Advance one step forward in maze HIDING INFORMATION
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 07/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Forward(
int robot_id ) /* In: ID for a robot */
{
Step_Forward( robot_id, robot, my_maze );
    
return 1;

} /* Forward */



/*FN****************************************************************************
*
*   int Step_Forward( int robot_id, ROBOT_T robot[], char maze[][MAZE_COLS] );
*
*   Return:  Nothing
*
*   Purpose: Advance one step forward in maze
*
*   Plan:
*           Part 1: Dertermine position in front of platform
*           Part 2: Update new robot position if there is not wall in front
*           Part 3: Refresh maze with new view
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Step_Forward(
int     robot_id,           /* In: ID for a robot */
ROBOT_T robot[],            /* In: Robot status   */
char    maze[][MAZE_COLS] ) /* In: Map of maze    */
{
char wall_x,  wall_y;
char robot_x, robot_y;
BOOLEAN hit_any_robot = FALSE;

/* Part 1: Dertermine position in front of platform */

wall_x = robot[robot_id].ubication[0] + robot[robot_id].direction[0];
wall_y = robot[robot_id].ubication[1] + robot[robot_id].direction[1];

robot_x = robot[robot_id].ubication[0] + SCALE * robot[robot_id].direction[0];
robot_y = robot[robot_id].ubication[1] + SCALE * robot[robot_id].direction[1];

for( int i=0; i<MAX_ROBOTS; i++ ) {

    hit_any_robot = hit_any_robot ||
    (robot_x == robot[i].ubication[0] && robot_y == robot[i].ubication[1]);

}

/* Part 2: Update new robot position if there is not wall in front */

if( (BOOLEAN)maze[wall_x][wall_y] || hit_any_robot ) {
    Wall_Was_Hit();
    exit( 1 );
} else {
    robot[robot_id].ubication[0] += SCALE * robot[robot_id].direction[0];
    robot[robot_id].ubication[1] += SCALE * robot[robot_id].direction[1];
}

/* Part 3: Update maze with robots in standard output */

Refresh_Maze( robot, console_buf );

return 1;

} /* Step_Forward */



/*FN****************************************************************************
*
*   int Robot( int robot_id, ROTATION_T rotation );
*
*   Return:  Nothing
*
*   Purpose: Rotate whole robot HIDING INFORMATION
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 07/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Robot(
int        robot_id,  /* In: ID for a robot */
ROTATION_T rotation ) /* In: Unitary robot direction */
{
Rotate_Robot( robot_id, robot, rotation );

return 1;
    
} /* Robot */



/*FN****************************************************************************
*
*   int Rotate_Robot( int robot_id, ROBOT_T robot[], ROTATION_T rotation );
*
*   Return:  Nothing
*
*   Purpose: Rotate whole robot
*
*   Plan:
*           Part 1: Prepare linear transformation for robot rotation
*           Part 2: Transform unitary robot direction
*           Part 3: Update new robot direction
*           Part 4: Prepare linear transformation for sonar rotation
*           Part 5: Transform unitary sonar direction
*           Part 6: Update new sonar direction
*           Part 7: Update maze with robots in standard output
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Rotate_Robot(
int        robot_id,  /* In: ID for a robot */
ROBOT_T    robot[],   /* In: Robot status   */
ROTATION_T rotation ) /* In: Unitary robot direction */
{
char aux_0, aux_1;

/* Part 1: Prepare linear transformation for robot rotation */

if( rotation == CLOCK_WISE )
    aux_0 =  1, aux_1 = -1;
else if( rotation == COUNTER_CW )
    aux_0 = -1, aux_1 =  1;

/* Part 2: Transform unitary robot direction */

aux_0 *= robot[robot_id].direction[1];
aux_1 *= robot[robot_id].direction[0];

/* Part 3: Update new robot direction */

robot[robot_id].direction[0] = aux_0;
robot[robot_id].direction[1] = aux_1;

/* Part 4: Prepare linear transformation for sonar rotation */

if( rotation == CLOCK_WISE )
    aux_0 =  1, aux_1 = -1;
else if( rotation == COUNTER_CW )
    aux_0 = -1, aux_1 =  1;

/* Part 5: Transform unitary sonar direction */

aux_0 *= robot[robot_id].dir_sonar[1];
aux_1 *= robot[robot_id].dir_sonar[0];

/* Part 6: Update new sonar direction */

robot[robot_id].dir_sonar[0] = aux_0;
robot[robot_id].dir_sonar[1] = aux_1;

/* Part 7: Update maze with robots in standard output */

Refresh_Maze( robot, console_buf );

return 1;

} /* Rotate_Robot */



/*FN****************************************************************************
*
*   int Sonar( int robot_id, ROTATION_T rotation );
*
*   Return:  Nothing
*
*   Purpose: Rotate sonar HIDING INFORMATION
*
*   Plan:   It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 07/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Sonar(
int        robot_id,  /* In: ID for a robot */
ROTATION_T rotation ) /* In: Unitary robot direction */
{
Rotate_Sonar( robot_id, robot, rotation );

return 1;
    
} /* Sonar */



/*FN****************************************************************************
*
*   int Rotate_Sonar( int robot_id, ROBOT_T robot[], ROTATION_T rotation );
*
*   Return:  Nothing
*
*   Purpose: Rotate sonar
*
*   Plan:
*           Part 1: Prepare linear transformation for sonar rotation
*           Part 2: Transform unitary sonar direction
*           Part 3: Update new sonar direction
*           Part 4: Update maze with robots in standard output
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Rotate_Sonar(
int        robot_id,  /* In: ID for a robot */
ROBOT_T    robot[],   /* In: Robot status */
ROTATION_T rotation ) /* In: Unitary sonar direction */
{
char aux_0, aux_1;

/* Part 1: Prepare linear transformation for sonar rotation */

if( rotation == CLOCK_WISE )
    aux_0 =  1, aux_1 = -1;
else if( rotation == COUNTER_CW )
    aux_0 = -1, aux_1 =  1;

/* Part 2: Transform unitary sonar direction */

aux_0 *= robot[robot_id].dir_sonar[1];
aux_1 *= robot[robot_id].dir_sonar[0];

/* Part 3: Update new sonar direction */

robot[robot_id].dir_sonar[0] = aux_0;
robot[robot_id].dir_sonar[1] = aux_1;

/* Part 4: Update maze with robots in standard output */

Refresh_Maze( robot, console_buf );

return 1;

} /* Rotate_Sonar */



/*FN****************************************************************************
*
*   int Initiate_Maze( char console_buf[][CON_COLS], char maze[][MAZE_COLS] );
*
*   Return:  Nothing
*
*   Purpose: Initiate buffer of maze in text mode from a map
*
*   Plan:
*           Part 1: Fill de console buffer with a white space
*           Part 2: Fill de console buffer with maze in text mode
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Initiate_Maze(
char console_buf[][CON_COLS], /* Out: Buffer of maze */
char maze[][MAZE_COLS] )      /* In:  Map of maze    */
{
char i, j;

/* Part 1: Fill de console buffer with a white space */

for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        console_buf[i][j] = ' ';

/* Part 2: Fill de console buffer with maze in text mode */

for( i=0; i<MAZE_ROWS; i++ ) {
    for( j=0; j<MAZE_COLS; j++ )
        console_buf[i][2*j] = maze[i][j]?'*':' ';
    console_buf[i][CON_COLS-1] = '\n';
}

return 1;

} /* Initiate_Maze */



/*FN****************************************************************************
*
*   int Refresh_Maze( ROBOT_T robot[], char console_buf[][CON_COLS] );
*
*   Return:  Nothing
*
*   Purpose: Update maze with robots in standard output
*
*   Plan:
*           Part 1: Copy maze buffer in another temporal buffer
*           Part 2: For every robot in maze...
*           Part 2.1: Take current position of robot
*           Part 2.2: Determine alphabetic char according to platform direction
*           Part 2.3: Determine alphabetic char according to sonar direction
*           Part 2.4: Update robot position in the maze
*           Part 3: Clear, print and pause console every interval
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Refresh_Maze(
ROBOT_T robot[],                  /* In: Robot status   */
char    console_buf[][CON_COLS] ) /* In: Buffer of maze */
{
char console_buf_tmp[CON_ROWS][CON_COLS]; /* Temporal buffer */
char pos_x, pos_y, sonar, platform;       /* Aux vbles for every robot */
char i, j;

/* Part 1: Copy maze buffer in another temporal buffer */

for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        console_buf_tmp[i][j] = console_buf[i][j];

/* Part 2: For every robot in maze... */

for( i=0; i<MAX_ROBOTS; i++ ) {

/* Part 2.1: Take current position of robot */

    pos_x = robot[i].ubication[0];
    pos_y = robot[i].ubication[1];

/* Part 2.2: Determine alphabetic char according to platform direction */

    if(      robot[i].direction[0]== 0 && robot[i].direction[1]==-1 )
        platform = '<';
    else if( robot[i].direction[0]== 0 && robot[i].direction[1]== 1 )
        platform = '>';
    else if( robot[i].direction[0]== 1 && robot[i].direction[1]== 0 )
        platform = 'V';
    else
        platform = 'A';

/* Part 2.3: Determine alphabetic char according to sonar direction */

    if(      robot[i].dir_sonar[0]== 0 && robot[i].dir_sonar[1]==-1 )
        sonar = '<';
    else if( robot[i].dir_sonar[0]== 0 && robot[i].dir_sonar[1]== 1 )
        sonar = '>';
    else if( robot[i].dir_sonar[0]== 1 && robot[i].dir_sonar[1]== 0 )
        sonar = 'V';
    else
        sonar = 'A';

/* Part 2.4: Update robot position in the maze */

    console_buf_tmp[pos_x][pos_y*2]     = platform;
    console_buf_tmp[pos_x][pos_y*2 + 1] = sonar;

}

/* Part 3: Clear, print and pause console every interval */

#ifdef LINUX
system( "clear");
#else
system( "cls");
#endif

for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        fprintf( stdout, "%c", console_buf_tmp[i][j] );

//for( i=0; i<MAX_ROBOTS; i++ )
//    Report_Robot( i, robot );

/* step is global vble that MUST BE avoided */

#ifdef LINUX
fprintf( stdout, "Running: %c (ctrl-z to stop)\n", motion[step++%4] );
#else
fprintf( stdout, "Running: %c (ctrl-c to stop)\n", motion[step++%4] );
#endif

/* sleep or timeout could be parameterized */

double previous = clock() * 1.0 / CLOCKS_PER_SEC;
while( clock() * 1.0 / CLOCKS_PER_SEC - previous < delay );

/*
#ifdef LINUX
system( "sleep 1" );
#else
system( "timeout 1 >NUL" );
#endif
*/

return 1;

} /* Refresh_Maze */



/*FN****************************************************************************
*
*   int Report_Robot( int robot_id, ROBOT_T robot[] );
*
*   Return:  Nothing
*
*   Purpose: Print current state of robot
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Oct 02/16  J.C.Giraldo  Improvements to allow several robots
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Report_Robot(
int     robot_id,  /* In: ID for a robot */
ROBOT_T robot[] )  /* In: Robot status */
{
fprintf( stdout,
"Pos: [%d,%d]\t", robot[robot_id].ubication[0], robot[robot_id].ubication[1] );
fprintf( stdout,
"Dir: [%d,%d]\t", robot[robot_id].direction[0], robot[robot_id].direction[1] );
fprintf( stdout,
"Snr: [%d,%d]\n", robot[robot_id].dir_sonar[0], robot[robot_id].dir_sonar[1] );

return 1;

} /* Report_Robot */



/*FN****************************************************************************
*
*   int Wall_Was_Hit();
*
*   Return:  Nothing
*
*   Purpose: Report whenever a robot hits something
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Wall_Was_Hit()
{
fprintf( stdout, "********************************************\n" );
fprintf( stdout, "* GAME OVER because a robot hits something *\n" );
fprintf( stdout, "********************************************\n" );

return 1;

} /* Wall_Was_Hit */



/*FN****************************************************************************
*
*   int Challenge_Was_Finished();
*
*   Return:  Nothing
*
*   Purpose: Report when a robot finishes challenge
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 08/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Challenge_Was_Finished()
{
fprintf( stdout, "******************************************************\n" );
fprintf( stdout, "* ROBOT SUCCESSFULLY FINISHED A-MAZE-(ing) CHALLENGE *\n" );
fprintf( stdout, "******************************************************\n" );

return 1;

} /* Challenge_Was_Finished */
