#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    typedef struct{
        double real;
        double imaginario;
    } COMPLEX_T;
 
int solve_Quadratic_Ecuation( 
COMPLEX_T   *root_1,
COMPLEX_T   *root_2,
double      a,
double      b,
double      c)
{
    double discriminante;
    discriminante = ((b*b)-(4*a*c));

    discriminante > 0.0 ? root_1->real = ((-b+(sqrt((b*b)-(4*a*c))))/(2*a)) , root_2->real = ((-b-(sqrt((b*b)-(4*a*c))))/(2*a)), root_1->imaginario = 0.0 ,root_2->imaginario = 0.0 : 0;discriminante < 0.0 ? root_1->real = (-b/(2*a)) , root_1->imaginario = ((sqrt((4*a*c)-(b*b)))/(2*a)) , root_2->real = (-b/(2*a)) , root_2->imaginario = (-(sqrt((4*a*c)-(b*b)))/(2*a)) : 0;discriminante == 0.0 ? root_1->real = (-b/(2*a)) , root_2->real = (-b/(2*a)) , root_1->imaginario = 0.0 , root_2->imaginario = 0.0 : 0;return 1;
}
 
int main(int argc, char *argv[])
{
 
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    COMPLEX_T root_1, root_2;
    solve_Quadratic_Ecuation(&root_1,&root_2,a,b,c);
    fprintf(stdout,"Solucion 1 : %.2f, %.2f i\n",root_1.real,root_1.imaginario);
    fprintf(stdout,"Solucion 2 : %.2f, %.2f i\n",root_2.real,root_2.imaginario);
    return 0;
}
