#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int N;
    int *p = 0;
    puts("please values of N ");
    scanf("%d",&N);

    if(N<2)
    {
    puts("please enter value of N greater than 1");
    exit(EXIT_SUCCESS);
    }

   p = (int *) malloc(sizeof(int)*N);
   
   
}