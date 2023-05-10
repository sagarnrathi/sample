#include<stdio.h>
#include<stdlib.h>

#define add(a,b) ((a ) + (b))

int main(void)
{
    int rs;
    int m = 10 , n = 25;
    rs = add(5,7);
    printf("rs = %d \n ",rs) ;
    rs = add(4 + 5,7 - 9);
    printf("rs = %d \n ",rs);
    rs = add(m+1,n*2);
    printf("rs = %d \n ",rs) ;
}