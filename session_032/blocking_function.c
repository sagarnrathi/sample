/*
	@author : sagar rathi
	@date   : 29/11/2022
	@goal   : to demonstrate the function of blocking funtion with the help of _getch() function .

*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char c;
	printf("start of program \n");
	c = _getch();
	printf("c = %c \n",c);
	printf("end of program \n");
	exit(0);
}