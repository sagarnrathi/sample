#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "matrix.h"

mat2d * get_matrix(size_t M ,size_t N)
{
    mat2d *m = NULL;
    m = (mat2d *) malloc(sizeof(mat2d));
    if(m == NULL)
    {
        puts("error in allocating the mmory ");
        exit(EXIT_FAILURE);
    }
    m->p = (int *)malloc(M * N *(sizeof(int)));

    if(m->p == NULL)
        {
        puts("error in allocating the mmory ");
        exit(EXIT_FAILURE);
    }

    memset(m->p,0,M * N *(sizeof(int)));
    m -> M = M ;
    m -> N = N  ;

    return(m);
 }

status_t add(mat2d *m1,mat2d *m2,mat2d **pp_mat_sum)
{
    mat2d *mat_sum = NULL ;
    size_t i,j;
    
    if(m1->M != m2-> M || m1 -> N != m2 -> N)
        return(MAT_DIMENSION_MISMATCH);
    
    mat_sum = get_matrix(m1 -> M,m1 ->N) ;
    for(i=0;i < m1-> M ;i++)
        for(j=0;j< m1->N;j++)
           *(mat_sum ->p + i* mat_sum->N + j) =   *(m1 ->p + i* m1->N + j) + *(m2 ->p + i* m2->N + j);
    *pp_mat_sum = mat_sum ;
    return(success);
}
status_t sub(mat2d *m1,mat2d *m2,mat2d **pp_mat_sum)
{
    mat2d *mat_sum = NULL ;
    size_t i,j;
    
    if(m1->M != m2-> M || m1 -> N != m2 -> N)
        return(MAT_DIMENSION_MISMATCH);
    
    mat_sum = get_matrix(m1 -> M,m1 ->N) ;
    for(i=0;i < m1-> M ;i++)
        for(j=0;j< m1->N;j++)
           *(mat_sum ->p + i* mat_sum->N + j) =   *(m1 ->p + i* m1->N + j) - *(m2 ->p + i* m2->N + j);
    *pp_mat_sum = mat_sum ;
    return(success);
}
//status_t get(mat2d *m1,size_t row,size_t col,int * p_Dij);
status_t set(mat2d *m1,size_t row,size_t col,int Dij)
{
    if(!(row >=  0 && row  < m1->M ) ||!(col >=0 && col < m1 -> N))
        return MAT_INVALID_MATRIX ;
    
    *(m1 -> p + m1 -> N *row + col) = Dij ;
    return success ;
}

void show(const char *msg,mat2d *m)
{
    size_t i,j;
    if(msg)
        puts(msg);
    for(i = 0;i<m->M;i++){
       for(j=0;j<m->N;j++)
           printf(" %d ",*(m->p + m->N * i + j));
     printf("\n");   
    }
}

void release_matrix(mat2d** pp_m){
    free((*pp_m)->p); 
    free(*pp_m); 
    *pp_m = NULL; 
}