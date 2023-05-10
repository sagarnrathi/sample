#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n = 0x0a0b0c0d ;
    if(*(char *)&n == 0xd)
       puts("we are little endian");
    else if (*(char *)&n == 0xa)
       puts("we are big endian");
    else 
       puts("invalid control flow");
    
    return (0);
}