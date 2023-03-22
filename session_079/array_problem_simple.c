#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0



void even_numbers(int *p_arr,int N);
void odd_numbers(int *p_arr,int N);
void is_prime_1(int *p_arr,int N);

int main(void)
{
int arr[10] = {1,7,3,28,5 ,9, 18,17,22,30};
int N = 10;
even_numbers(arr,N);
printf("--------------------\n");
odd_numbers(arr,N);
is_prime_1(arr,N);
return 0 ;

}

void even_numbers(int *p_arr,int N)
{
    int i;
    for(i=0;i<N;i++)
    if(p_arr[i]%2 == 0)
    printf("arr[%d] is even %d\n",i,p_arr[i]);
}

void odd_numbers(int *p_arr, int N)
{
    int i;
    for(i=0;i<N;i++)
    if(p_arr[i]%2!=0)
    printf("arr[%d] is odd %d \n",i,p_arr[i]);
}

void is_prime_1(int *p_arr,int N)
{ 
    
    int i,k,flag;
    for(i=0;i<N;i++)
    {
        
        if(p_arr[i]<=1)     
             continue;
        else if(p_arr[i]==2)
            
             printf("p_arr[%d] is a prime number %d \n",i,p_arr[i]);
        else
        {
            flag = TRUE;
            for(k=2;k<p_arr[i];k++)
            if(p_arr[i]%k == 0)
            {
                flag = FALSE;
                break;
            }
            if(flag == TRUE)
            printf("p_arr[%d]: %d is prime \n",i,p_arr[i]);
        }
    }
}