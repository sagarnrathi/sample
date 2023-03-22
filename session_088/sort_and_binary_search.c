#define CRT_RAND_S

#include<stdio.h>
#include<stdlib.h>

#define CAP 1001
#define N_MAX 25000

void insertion_sort(int *pA,int N);
void get_array(int **pp_arr,int *pN);
void show_array(int *a,int N,const char *msg);
int bin_search(int *pA,int start_index,int end_index,int search_data);
void show(int *pA,int N,const char *msg);

int main(void)
{
    int *pA =NULL;
    int N = -1;
    int search_data;
    int index;

    get_array(&pA,&N);
    insertion_sort(pA,N);
    show(pA,N,"showing sorted array ");

    printf("enter data to be searched \n");
    scanf("%d",&search_data);

    index  = bin_search(pA,0,N-1,search_data);
    if(index == -1)
    {
        printf("%d is not present in an array \n",search_data);

    }
    else
    {
    printf("%d is present in array at index %d \n",search_data,index);
    }

    free(pA);
    pA = NULL;

    return (EXIT_SUCCESS);
}

void get_array(int **pp_arr,int *pN)
{
    int *pA = NULL;
    int N;
    unsigned int num;
    int i;

    printf("enter N between[1-25000] : ");
    scanf("%d",&N);

    if(N<=0 || N > N_MAX)
    {
      printf("size of an array must be between 0 to %d",N_MAX);
      exit(EXIT_FAILURE);
    }
  
    pA = (int *) malloc(N* sizeof(int));
    if(pA == NULL)
    {
        puts("error in allocating the memory ");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<N;i++)
    {
        rand_s(&num);
        pA[i] = num % CAP;
    }

   *pp_arr =pA;
   *pN = N ;
}

void insertion_sort(int *pA,int N)
{
    int i,j,key;
    for(j=1;j<N;j++)
    {
        key = pA[j];
        i = j - 1;
        while(i> -1 && pA[i] > key)
        {
            pA[i+1] = pA[i];
            i = i -1;
        }
        pA[i + 1 ] = key ;
    }
}

int bin_search(int *pA,int start_index,int end_index,int search_data)
{
    int mid_index ;
    if(start_index <= end_index)
    {
        mid_index = (start_index + end_index) / 2;
        if(pA[mid_index]==search_data)
             return (mid_index);
        else if (search_data < pA[mid_index])
             return bin_search(pA,start_index,mid_index-1,search_data);
        else 
            return bin_search(pA,mid_index+1,end_index,search_data);
    }

    return (-1);
}

void show(int *pA,int N,const char *msg)
{
    int i;
    if(msg)
       puts(msg);
    for(i=0;i<N;i++)
    printf("pA[%d] : %d \n",i,pA[i]);
}