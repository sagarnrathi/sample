#include<stdio.h>
#include<stdlib.h>

void init(int ** pp);
void show(int ** pp);

int main(void)
{
    int* a[5] = {0, 0, 0, 0, 0}; 
    int i; 
    for(i = 0; i < 5; ++i)
    {
        a[i] = (int*)malloc(sizeof(int)); 
        if(a[i] == 0)
        {
            puts("malloc():error in allocating memory"); 
            exit(-1); 
        }
    }
    init(a);
    show(a);
    for(i = 0; i < 5; ++i)
    {
        free(a[i]); 
        a[i] = 0; 
    }
    
    return (0);
}
void init(int **p)
{
    int i;
      for(i = 0; i < 5; ++i)
    {
        *p[i] = (i+1) * 100; 
    }
}

void show(int **p)
{
    int i;
    for(i = 0; i < 5; ++i)
    {
        printf("*a[%d]=%d\n", i, * p[i]); 
    }
}
