#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

void cpa_sort(void * arr, int N, int nmem,int (*compare )(const void *,const void *))
{
    int i,j;
    void * key  = NULL;

    key = malloc(nmem);
    if(key == NULL)
    {
        puts("failed to allcate the memory");
        exit(EXIT_FAILURE);
    }

    for(j = 1;j<N;j++)
    {
        memcpy(key,((char*)arr) + j * nmem,nmem);
        i = j -1 ;
        while(i > -1 && compare((char *)arr + i * nmem,key)>0)
        {
            memcpy(
                ((char*)arr) + (i + 1) * nmem,
                ((char*)arr) + (i ) * nmem
            ) ;
            i = i - 1 ;
        }

        memcpy(((char *)arr) + (i +1)* nmem,key,nmem);
    }
    free(key);
    key = NULL;
}