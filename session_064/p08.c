#include<stdio.h>
#include<stdlib.h>

struct Date {
    int day ;
    int month;
    int year;
};

int main(void)
{
    struct Date d_arr[5];
    int i;
    
    for(i=0;i<5;i++)
    {
        d_arr[i].day = i + 1 ;
        d_arr[i].month = 10 - i ; 
        d_arr[i].year = 2020 + i ;
    }
    
    for(i=0;i<5;i++)
    {
        printf(" date at index i is %d-%d-%d\n",d_arr[i].day,d_arr[i].month,d_arr[i].year);
    }
    return 0;
}