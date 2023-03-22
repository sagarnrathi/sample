#include<stdio.h>
#include<stdlib.h>

void get_array(int **pp_arr,int *pN);
void insert_at_sorting_position(int *p_arr,int N);
void show_array(int *p_arr,int N,const char *msg);

int main(void)
{
    int *p_arr = NULL;
    int N;

    get_array(&p_arr,&N);
    show_array(p_arr,N,"before sorting :");
    insert_at_sorting_position(p_arr,N);
    show_array(p_arr,N,"after sorting() :");

    free(p_arr);
    p_arr = NULL;

    return(0);
}

void insert_at_sorting_position(int *p_arr, int N)
{
    int tmp;
    int k;

    tmp = p_arr[N-1];
    k = N-2;

    while(k>=0 && p_arr[k]>tmp)
    {
        p_arr[k + 1 ] = p_arr[k];
        k = k - 1;
    }
    p_arr[k + 1 ] = tmp;

}

void get_array(int **pp_arr,int *pN)
{
    
    int *p_arr = NULL;
    int N;
    int i;

    printf("please enter size of an array :");
    scanf("%d",&N);

    if(N<=0)
    {
        puts("bad size ");
        exit(EXIT_FAILURE);
    }

    p_arr = (int *) malloc(N * sizeof(int));
    if(p_arr == NULL)
    {
        puts("error in allocatig the memory ");
        exit(EXIT_FAILURE);
    }
    puts("enter sorted elemnt except last one ");
    for(i=0;i<N;i++)
    {
     printf("please enter data at index %d :",i);
     scanf("%d",p_arr + i);
    }
    *pp_arr = p_arr;
    *pN = N;
}

void show_array(int *p_arr,int N,const char *msg)
{
    int i;
    if(msg)
      puts(msg);
    
    for(i=0;i<N;i++)
    printf("p_arr[%d]:%d \n",i,p_arr[i]);
}