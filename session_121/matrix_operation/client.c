#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"

int main(void)
{
    mat2d *m1 = NULL ;
    mat2d *m2 = NULL ;
    mat2d * madd = NULL ;
    mat2d *msub  = NULL ;

    size_t m =6 , n =4 ;
    size_t i,j;
    size_t status ;

    m1 = get_matrix(m,n) ;
    m2 = get_matrix(m,n);
    madd = get_matrix(m,n);
    msub = get_matrix(m,n);
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    {
        set(m1,i,j,i+j);
        set(m2,i,j,i*j);
    }

    status  = add(m1,m2,&madd);
    status  = sub(m1,m2,&msub);
    show("m1 ",m1);
    show("m2",m2);
    show("add",madd);
    show("sub ",msub);
    return(EXIT_SUCCESS);

}