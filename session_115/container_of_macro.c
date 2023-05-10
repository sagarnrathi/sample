#include<stdio.h>
#include<stdlib.h>

#ifndef OFFSET_OF
#define OFFSET_OF(type,mem)   ((unsigned long long int )(&((type *)0) -> mem))
#endif

#ifndef CONTAINER_OF
#define CONTAINER_OF(add,type,mem)  ((type*)((unsigned long long int)(add) - OFFSET_OF(type, mem)))
#endif

void test(float * p);

struct A
{
    int a ;
    char b ;
    float c;
} ;

int main(void)
{
    struct A inA1 = {10, 'A', 1.1f}; 
    struct A inA2 = {20, 'B', 2.2f}; 
    struct A inA3 = {30, 'C', 3.3f}; 
    puts("OUTPUT USING CONTAINER_OF MACRO"); 
    test(&inA1.c);
    test(&inA2.c); 
    test(&inA3.c);  

    return (0); 
}

void test(float *p)
{
    struct A * pA = 0 ;

    pA = CONTAINER_OF(p,struct A, c);
        printf("pA->a = %d, pA->b = %c, pA->c = %.2f\n", pA->a, pA->b, pA->c); 

}