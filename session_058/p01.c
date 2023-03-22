#include<stdio.h>
#include<stdlib.h>

void fill_array(int *p, size_t N);
void show_array(int *p, size_t N);

int main(void)
{
    int *p_arr = 0;
    size_t N = 3 ;

    p_arr = (int *)malloc(N *sizeof(int));
    if(p_arr == 0)
    {
        puts("error in allocation the memoryb ");
        exit(EXIT_FAILURE);
    }

    fill_array(p_arr,N);
    show_array(p_arr,N);

    free(p_arr);
    p_arr = 0;
    return 0 ;
}

void fill_array(int *p,size_t N)
{

size_t i;
for(i=0;i<N;i++)
   *(p+i) = (i+1) * 100;
}

void show_array(int *p,size_t N)
{
    size_t i;
    for(i=0;i<N;i++)
    printf("*p + %lld  = %d \n",i,*(p + i));
}