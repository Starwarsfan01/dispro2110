#include<stdio.h>
unsigned char x=0x02,n=3;
int main(){
x |= (unsigned char)(1<<n);
printf("el resultado es: %d \n",x);
return 0;;
}

