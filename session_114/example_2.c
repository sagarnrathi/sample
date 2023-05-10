#include<stdio.h>
#include<stdlib.h>

unsigned long long int x;

int main(void)
{
    printf("1. x = %llx \n",x);
    *(unsigned char *)&x = 0x1a ;
    printf("2. x = %llx \n",x);
	printf("2. x = %lld \n",x);
    *(unsigned short *)((char *)&x + 1) = 0x2b3c ;
    printf("3. x = %llx \n",x);
    *(int *)((char*)&x+3) = 0xa0b0c0d0 ;
    printf("4. x = %llx \n",x);
    *(char * )((char *) &x + 7) = 0xdd ;
    printf("5. x = %llx \n",x);
    return(0);
}