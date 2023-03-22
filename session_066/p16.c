#include<stdio.h>
#include<stdlib.h>

int **allocate_array_of_pointer_to_integer(int *pN);
void initialise_array(int **ppn,int N);
void show_array(int **pp_arr,int N);
void release_array(int **pp_arr,int N);
void release_array_2(int ***ppp_arr,int N);

int main(void)
{
    int **pp_arr = 0;
    int N = -1 ;
    pp_arr = allocate_array_of_pointer_to_integer(&N);
    initialise_array(pp_arr,N);
    show_array(pp_arr,N);

    printf("before calling release array 2 pp_arr = %llu \n",(unsigned long long int)pp_arr);
    release_array_2(&pp_arr,N);
    printf("after calling release array 2 pp_arr %llu \n",(unsigned long long int )pp_arr);

    return 0;
}

int **allocate_array_of_pointer_to_integer(int * pN)
{
    int **pp_arr = 0;
    int N = -1;
    int i;

    printf("please enter a lenght of array \n");
    scanf("%d",&N);

    if(N < 1)
    {
        printf("please enter size of array greater than 1 ");
        exit(EXIT_FAILURE);
    }

    pp_arr =(int **) malloc(N* sizeof(int *));
    
    if(pp_arr == 0)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

   for(i=0;i<N;i++)
   {
    pp_arr[i] = (int *) malloc(N * sizeof(int ));
    if(pp_arr[i]==0)
    {
       puts("error in allocating the memory ");
       exit(EXIT_FAILURE);
    }
   }   
   *pN = N;
   return (pp_arr);
}

void initialise_array(int **ppn,int N)
{
    int i ;
    for(i=0;i<N;i++)
    {
        *ppn[i] = (i + 1) * 100;
    }
}

void show_array(int **ppn,int N)
{
    int i ;
    for(i=0;i<N;i++)
    {
        printf("element is ppn[%d] : %d  \n",i,*ppn[i]);
    }
}

void release_array(int **pp_arr,int N)
{
    int i ;
    for(i=0;i<N;i++)
    {
        free(pp_arr[i]);
        pp_arr[i] = 0;
    }
    free(pp_arr);
    pp_arr = 0;
}
void release_array_2(int ***ppp_arr,int N)
{
    int **pp_arr =0;
    int i;
    pp_arr = *ppp_arr;
    for(i=0;i<N;i++)
    {
        free(pp_arr[i]);
        pp_arr[i] = 0;
    }
    free(pp_arr);
    pp_arr = 0;
    *ppp_arr = 0;
}