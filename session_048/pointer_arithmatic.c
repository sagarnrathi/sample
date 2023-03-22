#include<stdio.h>
#include<stdlib.h>

int main(void)
{ 
    char *pc = 0;
    short *ps = 0 ;
    int *pi = 0;
    double *pd = 0;
    
    printf(" pc + 1  = %llu \n ",pc+1);
    printf("pc + 2  = %llu \n ",pc+2);
    printf("pc + 3  = %llu \n ",pc+3);
    puts("-----------------------");
    printf(" ps + 1  = %llu \n ",ps+1);
    printf("ps + 2  = %llu \n ",ps+2);
    printf("ps + 3  = %llu \n ",ps+3);
    puts("-----------------------");
    printf(" pi + 1  = %llu \n ",pi+1);
    printf("pi + 2  = %llu \n ",pi+2);
    printf("pi + 3  = %llu \n ",pi+3);
    puts("-----------------------");
    printf(" pd + 1  = %llu \n ",pd+1);
    printf("pd + 2  = %llu \n ",pd+2);
    printf("pd + 3  = %llu \n ",pd+3);

    return(0);

}