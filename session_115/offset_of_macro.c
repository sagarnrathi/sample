#include<stdio.h>
#include<stdlib.h>

#ifndef OFFSET_OF 
#define OFFSET_OF(type ,mem) ((unsigned long long int )(&((type * )0) -> mem))
#endif

struct A 
{
    int a ;
    char b;
    float c;
} ;

int main(void)
{
    unsigned long long int off_a,off_b,off_c ;
    
    off_a = OFFSET_OF(struct A,a);
    off_b = OFFSET_OF(struct A,b);
    off_c = OFFSET_OF(struct A,c);
    
    printf(" offset of a is %llu \n",off_a);
    printf(" offset of b is %llu \n",off_b);
    printf(" offset of c is %llu \n",off_c);
    return (0);
}

#define offset_of(type,mem)   ((unsigned int int long )(&((type *)0) -> mem))
#define offset_of(type,mem)   ((unsigned int long long )(&((type *) 0) -> mem))
#define offset_of(type,mem)   ((unsigned long long int)(&((type *) 0) -> mem))