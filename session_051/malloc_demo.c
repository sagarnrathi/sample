#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
    int *p;
    int m;
    p = (int*) malloc(sizeof(int));
    if (p==0)
    {
        puts("error ") ;
        exit(0);
    }
    *p = 200;
    m = *p;
    printf("m is %d" , m);
    free(p);
    p = 0;
    return(0);
}