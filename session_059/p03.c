#include<stdio.h>
#include<stdlib.h>

void get_array(int **pp_arr,int *pN);
void fill_array(int *p_arr,int N);
void show_array(int *p_arr,int N);
void release_array(int **pp_arr);

int main(void)
{
    int *p_arr = 0;
    int N = -1;

    get_array(&p_arr,&N);
    fill_array(p_arr,N);
    show_array(p_arr,N);
    release_array(&p_arr);

    return(0);
}

void get_array(int **pp_arr,int *pN)
{
    int *p_arr = 0;
    int N = -1 ;
    
    printf("please enter size of an array : \n");
    scanf("%d",&N);

   if(N<1){
    puts("array size must be +ve ");
    exit(-1);
   }

   p_arr = (int *)malloc(N * sizeof(int));

   if(p_arr == 0){
    puts("error in allocating the memory ");
    exit(-1);
   }

   *pN = N;
   *pp_arr = p_arr;
}

void fill_array(int *p_arr,int N)
{
    int i = 0 ;
    for(i=0;i < N;i++)
    p_arr[i] = (i + 1) * 100;
}

void show_array(int *p_arr,int N)
{
    int i = 0 ;
    for(i = 0;i< N; i++)
    printf("value at p[%d] : %d \n",i,p_arr[i]);
}

void release_array(int **p_arr)
{
    free(*p_arr);
    **p_arr = 0;
}