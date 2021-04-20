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
/*          Copyright (C) Departament de Electronics                          */
/*                        School of Engineering                               */
/*                        Pontificia Universidad Javeriana                    */
/*                        Bogota - Colombia - South America                   */
/*                                                                            */
/******************************************************************************/

/* --------------------- Inclusion of Standard Headers ---------------------- */

#include <stdio.h>
#include <stdlib.h>

#define LINUX       /* Delete this line if your system is a windows-based PC */

#define MAZE_ROWS 11             /* Maximum number of rows in map of maze */
#define MAZE_COLS 11             /* Maximum number of cols in map of maze */

#define CON_ROWS (MAZE_ROWS)     /* Maximum number of rows in console */
#define CON_COLS (2*MAZE_COLS+1) /* Maximum number of cols in console */

#define SCALE 2 /* Factor scale to advance one step forward inside maze */

static char my_maze[MAZE_ROWS][MAZE_COLS] = {
    
    /*        00 01 02 03 04 05 06 07 08 09 10 */
    /* 00 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    /* 01 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    /* 02 */ { 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
    /* 03 */ { 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0 },
    /* 04 */ { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
    /* 05 */ { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
    /* 06 */ { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
    /* 07 */ { 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0 },
    /* 08 */ { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
    /* 09 */ { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    /* 10 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

/* Buffer to display the map of maze in stdout through ASCII chars */

static char console_buf[CON_ROWS][CON_COLS];

/* Declaration of enumeration type for normalized unitary vector */

typedef enum { LEFT, RIGHT, DOWN, UP } DIRECTION_T;

/* Declaration of enumeration type for normalized unitary vector */

typedef enum { COUNTER_CW, CLOCK_WISE } ROTATION_T;

/* Declaration of robot status */

typedef struct {
    char ubication[2]; /* Absolute ubication in maze */
    char direction[2]; /* Normalized robot direction */
    char dir_sonar[2]; /* Normalized sonar direction */
} ROBOT_T;

ROBOT_T my_robot;

static int step = 0;


/* Hiding info */

int Running();
int Testing_Maze();
int Is_There_Wall();
int Forward();
int Robot( ROTATION_T rotation );
int Sonar( ROTATION_T rotation );

/* Main functions */

int Is_There_Obstacle( ROBOT_T *robot_ptr, char maze[][MAZE_COLS] );
int Step_Forward( ROBOT_T *robot_ptr, char maze[][MAZE_COLS] );
int Rotate_Robot( ROBOT_T *robot_ptr, ROTATION_T rotation );
int Rotate_Sonar( ROBOT_T *robot_ptr, ROTATION_T rotation );

/* Other functions */

int Initiate_Robot( ROBOT_T *robot, char pos_x, char pos_y,
                                    DIRECTION_T platform, DIRECTION_T sonar );
int Initiate_Maze_in_Text_Mode( char console_buf[][CON_COLS],
                                char maze[][MAZE_COLS] );
int Refresh_Maze_in_Text_Mode( ROBOT_T *robot, char console_buf[][CON_COLS] );
int Report_Robot( ROBOT_T *robot );
int Wall_Was_Hit();
int Challenge_Was_Finished();



/*FN****************************************************************************
*
*   int Running();
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
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Running()
{
return ( my_robot.ubication[0] != 0 &&
         my_robot.ubication[1] != 0 &&
         my_robot.ubication[0] != (MAZE_ROWS-1) &&
         my_robot.ubication[1] != (MAZE_COLS-1) );

} /* Running */



/*FN****************************************************************************
*
*   int Testing_Maze();
*
*   Return:  Nothing
*
*   Purpose: Provide multiple tests for FSM algorithms
*
*   Plan:
*           Part 1:
*           Part 2:
*           Part 3:
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Testing_Maze()
{
Initiate_Robot( &my_robot, 8, 2, RIGHT, RIGHT );
Initiate_Maze_in_Text_Mode( console_buf, my_maze );
Refresh_Maze_in_Text_Mode( &my_robot, console_buf );

return 1;

} /* Testing_Maze */



/* Definition of functions */

/*FN****************************************************************************
*
*   int Initiate_Robot( ROBOT_T *robot_ptr, char pos_x, char pos_y,
*                       DIRECTION_T platform, DIRECTION_T sonar );
*
*   Return:  Nothing
*
*   Purpose: Set initial values for a robot
*
*   Plan:
*           Part 1: Set initial ubication of robot in the maze
*           Part 2: Set initial direction of platform
*           Part 3: Set initial direction of sonar
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Initiate_Robot(
ROBOT_T *robot_ptr,     /* Out: Structure of robot status  */
char pos_x, char pos_y, /* In:  Position of robot in maze  */
DIRECTION_T platform,   /* In:  Platform unitary direction */
DIRECTION_T sonar )     /* In:  Sonar unitary direction    */
{

/* Part 1: Set initial ubication of robot in the maze */

robot_ptr->ubication[0] = pos_x;
robot_ptr->ubication[1] = pos_y;

/* Part 2: Set initial direction of platform */

if( platform == UP )
    robot_ptr->direction[0] = -1, robot_ptr->direction[1] =  0;
else if( platform == DOWN )
    robot_ptr->direction[0] =  1, robot_ptr->direction[1] =  0;
else if( platform == RIGHT )
    robot_ptr->direction[0] =  0, robot_ptr->direction[1] =  1;
else if( platform == LEFT )
    robot_ptr->direction[0] =  0, robot_ptr->direction[1] = -1;

/* Part 3: Set initial direction of sonar */

if( sonar == UP )
    robot_ptr->dir_sonar[0] = -1, robot_ptr->dir_sonar[1] =  0;
else if( sonar == DOWN )
    robot_ptr->dir_sonar[0] =  1, robot_ptr->dir_sonar[1] =  0;
else if( sonar == RIGHT )
    robot_ptr->dir_sonar[0] =  0, robot_ptr->dir_sonar[1] =  1;
else if( sonar == LEFT )
    robot_ptr->dir_sonar[0] =  0, robot_ptr->dir_sonar[1] = -1;

return 1;

} /* Initiate_Robot */



/*FN****************************************************************************
*
*   int Is_There_Wall();
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
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Is_There_Wall()
{
return( Is_There_Obstacle( &my_robot, my_maze ) );
    
} /* Is_There_Wall */



/*FN****************************************************************************
*
*   int Is_There_Obstacle( ROBOT_T *robot_ptr, char maze[][MAZE_COLS] );
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
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Is_There_Obstacle(
ROBOT_T *robot_ptr,      /* In: Robot status */
char maze[][MAZE_COLS] ) /* In: Map of maze  */
{
char next_x, next_y;

next_x = robot_ptr->ubication[0] + robot_ptr->dir_sonar[0];
next_y = robot_ptr->ubication[1] + robot_ptr->dir_sonar[1];

return maze[next_x][next_y];

} /* Is_There_Obstacle */



/*FN****************************************************************************
*
*   int Forward();
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
*   Sep 07/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Forward()
{
Step_Forward( &my_robot, my_maze );
    
return 1;

} /* Forward */



/*FN****************************************************************************
*
*   int Step_Forward( ROBOT_T *robot_ptr, char maze[][MAZE_COLS] );
*
*   Return:  Nothing
*
*   Purpose: Command in order to advance one step forward in maze
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
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Step_Forward(
ROBOT_T *robot_ptr,      /* In: Robot status */
char maze[][MAZE_COLS] ) /* In: Map of maze  */
{
char next_x, next_y;

/* Part 1: Dertermine position in front of platform */

next_x = robot_ptr->ubication[0] + robot_ptr->direction[0];
next_y = robot_ptr->ubication[1] + robot_ptr->direction[1];

/* Part 2: Update new robot position if there is not wall in front */

if( maze[next_x][next_y] ) {
    Wall_Was_Hit();
    exit( 1 );
} else {
    robot_ptr->ubication[0] += SCALE * robot_ptr->direction[0];
    robot_ptr->ubication[1] += SCALE * robot_ptr->direction[1];
}

/* Part 3: Refresh maze with new view */

Refresh_Maze_in_Text_Mode( robot_ptr, console_buf );

return 1;

} /* Step_Forward */



/*FN****************************************************************************
*
*   int Robot( ROTATION_T rotation );
*
*   Return:  Nothing
*
*   Purpose: Command to rotate whole robot HIDING INFORMATION
*
*   Plan:    It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 07/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Robot( ROTATION_T rotation )
{
Rotate_Robot( &my_robot, rotation );

return 1;
    
} /* Robot */



/*FN****************************************************************************
*
*   int Rotate_Robot( ROBOT_T *robot_ptr, DIRECTION_T rotation );
*
*   Return:  Nothing
*
*   Purpose: Command to rotate whole robot
*
*   Plan:
*           Part 1: Prepare linear transformation for robot rotation
*           Part 2: Transform unitary robot direction
*           Part 3: Update new robot direction
*           Part 4: Prepare linear transformation for sonar rotation
*           Part 5: Transform unitary sonar direction
*           Part 6: Update new sonar direction
*           Part 7: Refresh maze with new view
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Rotate_Robot(
ROBOT_T *robot_ptr,   /* In: Robot status */
ROTATION_T rotation ) /* In: Unitary robot direction */
{
char aux_0, aux_1;

/* Part 1: Prepare linear transformation for robot rotation */

if( rotation == CLOCK_WISE )
    aux_0 =  1, aux_1 = -1;
else if( rotation == COUNTER_CW )
    aux_0 = -1, aux_1 =  1;

/* Part 2: Transform unitary robot direction */

aux_0 *= robot_ptr->direction[1];
aux_1 *= robot_ptr->direction[0];

/* Part 3: Update new robot direction */

robot_ptr->direction[0] = aux_0;
robot_ptr->direction[1] = aux_1;

/* Part 4: Prepare linear transformation for sonar rotation */

if( rotation == CLOCK_WISE )
    aux_0 =  1, aux_1 = -1;
else if( rotation == COUNTER_CW )
    aux_0 = -1, aux_1 =  1;

/* Part 5: Transform unitary sonar direction */

aux_0 *= robot_ptr->dir_sonar[1];
aux_1 *= robot_ptr->dir_sonar[0];

/* Part 6: Update new sonar direction */

robot_ptr->dir_sonar[0] = aux_0;
robot_ptr->dir_sonar[1] = aux_1;

/* Part 7: Refresh maze with new view */

Refresh_Maze_in_Text_Mode( robot_ptr, console_buf );

return 1;

} /* Rotate_Robot */



/*FN****************************************************************************
*
*   int Sonar( ROTATION_T rotation );
*
*   Return:  Nothing
*
*   Purpose: Command to rotate sonar HIDING INFORMATION
*
*   Plan:   It is not necessary
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 07/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Sonar( ROTATION_T rotation )
{
Rotate_Sonar( &my_robot, rotation );

return 1;
    
} /* Sonar */



/*FN****************************************************************************
*
*   int Rotate_Sonar( ROBOT_T *robot_ptr, DIRECTION_T rotation );
*
*   Return:  Nothing
*
*   Purpose: Command to rotate sonar
*
*   Plan:
*           Part 1: Prepare linear transformation for sonar rotation
*           Part 2: Transform unitary sonar direction
*           Part 3: Update new sonar direction
*           Part 4: Refresh maze with new view
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Rotate_Sonar(
ROBOT_T *robot_ptr,   /* In: Robot status */
ROTATION_T rotation ) /* In: Unitary sonar direction */
{
char aux_0, aux_1;

/* Part 1: Prepare linear transformation for sonar rotation */

if( rotation == CLOCK_WISE )
    aux_0 =  1, aux_1 = -1;
else if( rotation == COUNTER_CW )
    aux_0 = -1, aux_1 =  1;

/* Part 2: Transform unitary sonar direction */

aux_0 *= robot_ptr->dir_sonar[1];
aux_1 *= robot_ptr->dir_sonar[0];

/* Part 3: Update new sonar direction */

robot_ptr->dir_sonar[0] = aux_0;
robot_ptr->dir_sonar[1] = aux_1;

/* Part 4: Refresh maze with new view */

Refresh_Maze_in_Text_Mode( robot_ptr, console_buf );

return 1;

} /* Rotate_Sonar */




/*****************************  Private Functions  ****************************/

/*FN****************************************************************************
*
*   int Initiate_Maze_in_Text_Mode( char console_buf[][CON_COLS],
*                                                   char maze[][MAZE_COLS] );
*
*   Return:  Nothing
*
*   Purpose: Command to initiate buffer of maze in text mode from its map
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
Initiate_Maze_in_Text_Mode(
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

} /* Initiate_Maze_in_Text_Mode */



/*FN****************************************************************************
*
*   int Refresh_Maze_in_Text_Mode( ROBOT_T *robot_ptr,
*                                          char console_buf[][CON_COLS] );
*
*   Return:  Nothing
*
*   Purpose: Command to send maze saved in buffer to standard out
*
*   Plan:
*           Part 1: Copy the maze in a temporal buffer
*           Part 2: Take current position of robot
*           Part 3: Determine alphabetic char according to platform direction
*           Part 4: Determine alphabetic char according to sonar direction
*           Part 5: Update robot position in the maze
*           Part 6: Clear, print and pause console every 2 seconds
*
*   Register of Revisions (Debugging Proccess):
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Refresh_Maze_in_Text_Mode(
ROBOT_T *robot_ptr,            /* In: Robot status   */
char console_buf[][CON_COLS] ) /* In: Buffer of maze */
{
char console_buf_tmp[CON_ROWS][CON_COLS];
char pos_x, pos_y;
char sonar, platform;
char i, j;

/* Part 1: Copy the maze in a temporal buffer */

for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        console_buf_tmp[i][j] = console_buf[i][j];

/* Part 2: Take current position of robot */

pos_x = robot_ptr->ubication[0];
pos_y = robot_ptr->ubication[1];

/* Part 3: Determine alphabetic char according to platform direction */

if(      robot_ptr->direction[0]== 0 && robot_ptr->direction[1]==-1 )
    platform = '<';
else if( robot_ptr->direction[0]== 0 && robot_ptr->direction[1]== 1 )
    platform = '>';
else if( robot_ptr->direction[0]== 1 && robot_ptr->direction[1]== 0 )
    platform = 'V';
else
    platform = 'A';

/* Part 4: Determine alphabetic char according to sonar direction */

if(      robot_ptr->dir_sonar[0]== 0 && robot_ptr->dir_sonar[1]==-1 )
    sonar = '<';
else if( robot_ptr->dir_sonar[0]== 0 && robot_ptr->dir_sonar[1]== 1 )
    sonar = '>';
else if( robot_ptr->dir_sonar[0]== 1 && robot_ptr->dir_sonar[1]== 0 )
    sonar = 'V';
else
    sonar = 'A';

/* Part 5: Update robot position in the maze */

console_buf_tmp[pos_x][pos_y*2]     = platform;
console_buf_tmp[pos_x][pos_y*2 + 1] = sonar;

/* Part 6: Clear, print and pause console every 2 seconds */

#ifdef LINUX
system( "clear");
#else
system( "cls");
#endif

for( i=0; i<CON_ROWS; i++ )
    for( j=0; j<CON_COLS; j++ )
        fprintf( stdout, "%c", console_buf_tmp[i][j] );

//Report_Robot( robot_ptr );

/* step is global vble that must be avoided */

#ifdef LINUX
fprintf( stdout, "Step: %d (ctrl-z to stop)\n", step++ );
#else
fprintf( stdout, "Step: %d (ctrl-c to stop)\n", step++ );
#endif

/* sleep 2, could be parameterized */

#ifdef LINUX
system( "sleep 1" );
#else
system( "timeout 1 >NUL" );
#endif

return 1;

} /* Refresh_Maze_in_Text_Mode */



/*FN****************************************************************************
*
*   int Report_Robot( ROBOT_T *robot_ptr );
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
*   Sep 01/15  J.C.Giraldo  Initial implementation
*
*******************************************************************************/

int
Report_Robot(
ROBOT_T *robot_ptr ) /* In: Robot status */
{
fprintf( stdout,
        "Pos: [%d,%d]\t", robot_ptr->ubication[0], robot_ptr->ubication[1] );
fprintf( stdout,
        "Dir: [%d,%d]\t", robot_ptr->direction[0], robot_ptr->direction[1] );
fprintf( stdout,
        "Snr: [%d,%d]\n", robot_ptr->dir_sonar[0], robot_ptr->dir_sonar[1] );

return 1;

} /* Report_Robot */



/*FN****************************************************************************
*
*   int Wall_Was_Hit();
*
*   Return:  Nothing
*
*   Purpose: Report the event whenever robot hits obstacle
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
fprintf( stdout, "* GAME OVER because the robot hit the wall *\n" );
fprintf( stdout, "********************************************\n" );

return 1;

} /* Wall_Was_Hit */



/*FN****************************************************************************
*
*   int Challenge_Was_Finished();
*
*   Return:  Nothing
*
*   Purpose: Report the event that robot finished challenge
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
