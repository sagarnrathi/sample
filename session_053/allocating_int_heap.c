#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *p=0;
    int m;

    p = (int*) malloc(sizeof(int));
    *p = 200;
    m = *p ;
    
    printf("m= %d \n",m);

    free(p);
    p = 0;
    
    return(0);
}