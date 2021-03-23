/* Ruler 1         2         3         4         5         6         7        */

/*********************************  select.h  *********************************/
/*                                                                            */
/*   Purpose: Demonstration of "selector constructs" with math functions      */
/*                                                                            */
/*   Origin:  Written and tested by ------------, August 21th, 2015           */
/*                                                                            */
/*   Notes:   None                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef SELECT_H
#define SELECT_H

/**********************  Declarations of Public Functions  ********************/

double Selection_Binary( int n, double value );
double Selection_Prioritized( int n, double value );
double Selection_Bypassed( int n, double value );
double Selection_Jump( int n, double value );
double Selection_Goto( int n, double value );
double Selection_Index( int n, double value );

#endif /* SELECT_H */
