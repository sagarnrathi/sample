#define NULL ((void *)0)

typedef unsigned long long int size_t ;

#include<stdio.h>
#include<stdlib.h>

void * malloc(size_t size_in_bytes);
void *calloc(size_t number_of_elements,size_t size_of_elements);

void *cpa_calloc(size_t number_of_elements,size_t size_of_elements)
{
    void *p = NULL;

    p = malloc(number_of_elements * size_of_elements);
    if(p!=NULL)
    {
        memset(p,0,number_of_elements * size_of_elements);
    }
    return(p);
}