#include<stdio.h>
#include<stdlib.h>

struct Date 
{
    int day;
    int month;
    int year ;
} ;

unsigned char arr[12] = {
0x1,0x0,0x0,0x0,
0x1,0x0,0x0,0x0,
0xB2,0x7,0x0,0x0
} ;

int main(void)
{
    void * p = NULL ;
    p = arr ;
    
    printf("%d day is \n",((struct Date *)p)->day);
    printf("%d month is \n",((struct Date *)p)->month);
    printf("%d year is ",((struct Date *)p)-> year) ;
}

