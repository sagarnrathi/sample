#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int num;
    int choice ;
    int *arr = NULL;
    int N = 0;

    while(1)
    {
        printf("do you want to enter integer 0 yes 1 no \n");
        scanf("%d",&choice);
        if(choice!=1)
           break;
        printf("enter value ");
        scanf("%d",&num);

        N++;
        arr = (int *)realloc(arr,N * sizeof(int));
        arr[N - 1] = num ;
        
    }
    for(int i=0;i<N;i++)
        printf("arr[%d] : %d \n",i,arr[i]);
    return(0);
}