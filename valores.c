#include<stdio.h>
int main(){
int xvaluecontent=25;
int yvaluecontent=43;
int *duplicatedxvalueaddress,*duplicatedyvalueaddress,*temporalcontent;
duplicatedxvalueaddress=&xvaluecontent;
printf("el contenido de duplic %p \n",&duplicatedxvalueaddress);
printf("el valor de duplic %c \n",*duplicatedxvalueaddress);
duplicatedyvalueaddress=&yvaluecontent;
printf("el valor de duplicatedy %c \n",*duplicatedyvalueaddress);
temporalcontent=*duplicatedxvalueaddress;
*duplicatedxvalueaddress=*duplicatedyvalueaddress;
*duplicatedyvalueaddress=temporalcontent;
printf("el contenido es %p \n",&temporalcontent);}
