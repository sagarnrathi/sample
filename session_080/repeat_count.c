#include<stdio.h>
#include<stdlib.h>

void get_array(int **pp_arr,int *pN);
void print_unique_elements_with_repeat_count(int *pN,int N);

int main(void)
{
    int *p_arr = NULL;
    int N = -1;

    get_array(&p_arr,&N);
    print_unique_elements_with_repeat_count(p_arr,N);
    free(p_arr);
    p_arr = NULL;

    return(EXIT_SUCCESS);
}

void get_array(int **pp_arr,int *pN)
{
    int * p_arr = NULL;
    int N;
    int i;

    printf("enter size of an array \n");
    scanf("%d",&N);

    if(N<1)
    {
        puts("bad size ");
        exit(EXIT_FAILURE);
    }

    p_arr = (int *) malloc(N * sizeof(int));
    if(p_arr == NULL)
    {
        puts("error in allocating the memory ");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<N;i++)
    {
        printf("enter data at index %d ",i);
        scanf("%d",p_arr+i);

    }
    *pp_arr = p_arr;
    *pN = N; 
}

void print_unique_elements_with_repeat_count(int *p_arr,int N)
{
    int i;
    int k;
    int repeat_count;

    for(i=0;i<N;++i)
    {
        for(k=0;k<i;k++)
        {
            if(p_arr[k]==p_arr[i])
            break;
        }
        if(k<i)
        continue;
        repeat_count = 0;
        for(k=i;k<N;k++)
          if(p_arr[k]==p_arr[i])
            repeat_count++;
        printf("unique element %d time %d \n",p_arr[i],repeat_count);
    }
}