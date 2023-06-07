#include<stdio.h>
#include<stdlib.h>

void matrix_M_N(void);

int main(void)
{
    matrix_M_N();
    return(EXIT_SUCCESS);
}

void matrix_M_N()
{
    size_t M,N;
    int *pM = NULL ;
    size_t i,j;

    printf("enter the number of rows of matric :");
    scanf("%llu",&M);
    printf("enter the number of coulmns of matrix : ");
    scanf("%llu",&N);

    pM = (int *) malloc(M * N *sizeof(int));
    if(pM == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<M;i++)
       for(j=0;j<N;j++)
          *(pM + i* N + j ) = i + j ;
    
    for(i=0;i<M;i++)
       for(j=0;j<N;j++)
          printf("Matrix[%llu][%llu] == %d \n",i,j,*(pM + i * N + j));

    free(pM);
    pM = NULL ;
}