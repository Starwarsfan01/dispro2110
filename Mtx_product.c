/*
 * =====================================================================================
 *
 *       Filename:  Mtx_product.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/25/2021 10:42:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Juan Sebastian Clavijo (), jclavijomartinez@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#define	FP double
int COLS;			/*  */
int
Mtx_Product (FP mtx_1[][COLS],  FP mtx_2[][COLS], FP mtx[][COLS],  int max_i,  int max_j,  int max_k); 
{
register int k;
register int j;
register int i;
for( i = 0; i < max_i; i++ )
 for( j = 0; j < max_j; j++ )
 for( k = 0; k < max_k; k++ )
 mtx[i][j] += mtx_1[i][k] * mtx_2[k][j];
return 1;
} /* Mtx_Product */
