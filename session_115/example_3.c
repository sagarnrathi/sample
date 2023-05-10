#include<stdio.h>
#include<stdlib.h>

struct A
{
    int a;
    int b;
    int c ;
    char d;
} ;

struct B
{
    char a,b ;
    int c,d ;
} ;

int main(void)
{
    struct A inA ;
    struct A * ptrA = 0 ;
    
    unsigned  long long int off_c = 0 ;
    off_c = (unsigned long long int )&inA.c - (unsigned long long int )&inA;
    printf("1 : offset is :%llu \n",off_c);

    off_c = (unsigned long long int)(&((struct A *)0)->c);
    printf("2 : offset is :%llu",off_c);

    return(0);

}