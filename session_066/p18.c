#include<stdlib.h>
#include<stdio.h>

struct Date 
{
int day;
int month;
int year;
};

int main(void)
{
    int N = 5;
    struct Date *d_arr[5] = {0,0,0,0,0};
    int i;

    for(i=0;i<N;i++)
    {
        d_arr[i] = (struct Date *) malloc(sizeof(struct Date));
        if(d_arr[i] == 0){
            puts("error in allocating the memory ");
            exit(EXIT_FAILURE);
        }

    }

    for(i=0;i<N;i++)
    {
        d_arr[i]->day = 10 + i ;
        d_arr[i]->month = 12 - i;
        d_arr[i]->year = 2021 + i;
    }

    for(i=0;i<N;i++)
    {
        printf("date instance is %d : %d-%d-%d \n",i,d_arr[i]->day,d_arr[i]->month,d_arr[i]->year);
    }
    for(i=0;i<N;i++)
    {
        free(d_arr[i]);
        d_arr[i] = 0;
    }
    return 0 ;
}