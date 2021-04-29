/* Ruler 1         2         3         4         5         6         7        */

/* challenge.c ****************************************************************/
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

#include <stdio.h>
#include <stdlib.h>

#include "maze.h"

#define JSEBASTIAN_dot_CLAVIJOC_A 0
#define PRUEBAS 1
//#define JSEBASTIAN.CLAVIJOC_C 6
//#define JSEBASTIAN.CLAVIJOC_D 7

#include "jsebastian.clavijoc_a.h"
#include "pruebas.h"
//#include "jsebastian.clavijoc_c.h"
//#include "jsebastian.clavijoc_d.h"

int
main()
{
Testing_Maze();

while( Running() ) {
   jsebastian_dot_clavijoc_robot();
   pruebas_robot();
  //  username_c_robot();
  //  username_d_robot();
}

Challenge_Was_Finished();

} /* main */
