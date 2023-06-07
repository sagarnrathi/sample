#include<stdio.h>
#include<stdlib.h>

void carve_2d_arr(int *p,size_t N);
void carve_3d_arr(int *p,size_t N);

int main(void)
{
    size_t N = 80 ;
    int * p = NULL ;
    size_t i;

    p = (int *) malloc(N * sizeof(int));
    if(p == NULL)
    {
        puts("error in allocating the memory ");
        exit(EXIT_FAILURE);

    }
    for(i =0 ; i < N ; i++)
       *(p + i) = (i + 1) ;
    carve_2d_arr(p,N);
    carve_3d_arr(p,N);

    free(p);
    p = NULL ;

    return(EXIT_SUCCESS);
}

void carve_2d_arr(int *p,size_t n)
{
    size_t M = 10,N = 8;
    size_t i,j;

    for(i=0;i<M;i++)
       for(j=0;j<N;j++)
           printf("m[%llu][%llu] = %d \n",i,j,*(p+i*N+j));
}

void carve_3d_arr(int *p,size_t n)
{
    size_t M = 4, N = 4 ,L = 5 ;
    size_t i,j,k ;
    for(i=0;i<M;i++)
      for(j=0;j<N;j++)
         for(k=0;k<L;k++)
            printf("a[%llu][%llu][%llu] = %d \n",i,j,k,*(p + i * N * L + j * L + k));
}