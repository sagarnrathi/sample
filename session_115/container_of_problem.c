#include<stdio.h>
#include<stdlib.h>

#ifndef OFFSET_OF
#define OFFSET_OF(type , mem) ((unsigned long long int) (&((type *)0) -> mem))
#endif

void test(float * p) ;

struct A 
{
    int a ;
    char b;
    float c ;
};

int main(void)
{

struct A inA1 = {4,'c',3.1f};
struct A inA2 = {5,'d',2.1f};
struct A inA3 = {6,'e',1.1f};

test(&inA1.c);
test(&inA2.c);
test(&inA3.c);
return (0);
}

void test(float *p)
{
    struct  A * a = 0 ;
    a = (struct A * ) ((unsigned long long int)p - OFFSET_OF(struct A,c));

    printf("%d %c %f \n",a->a,a->b,a->c);
}