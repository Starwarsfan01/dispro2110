#include<stdio.h>

int main(){
	int *ava,xvc=14,*bva,yvc=15;
	ava=&xvc;
	xvc=*bva;
	yvc=xvc;
	ava=bva;
	printf("la variable xvc = %d \n", xvc);
	printf("la variable yvc = %d \n", yvc);
	printf("la variable ava = %p \n",&ava);
	printf("la variable bva = %p \n", *bva);
	return 0;
}
