#include<stdio.h>

int main(){
	int *ava,xvc=14,*bva,yvc=15;
	ava=&xvc;
	xvc=*bva;
	yvc=xvc;
	ava=bva;
	printf("la variable = %d \n", xvc);
	printf("la variable = %d \n", yvc);
	printf("la variable = %p \n",ava);
	printf("la variable = %p \n", bva);
	return 0;
}
