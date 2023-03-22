#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n = 100;
    int *p;
    printf("&n = %p \n",&n);
    p=&n;
    printf("&n = %p \n",&n);
    printf("&n = %d \n",n);
     *p = 200;
     printf("&n = %d \n",n);
     return(0);
}