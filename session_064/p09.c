#include<stdio.h>
#include<stdlib.h>

struct Date 
{
    int day;
    int month;
    int year;
};

void init_array(struct Date * p_date, size_t N);
void show_array(struct Date *p_date, size_t N);

int main(void)
{
    struct Date *p_date = 0;
    size_t N = 5;

    p_date = (struct Date * ) malloc(sizeof(struct Date)*N);

    if(p_date == 0)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    init_array(p_date,N);
    show_array(p_date,N);

    free(p_date);
    p_date = 0 ;
    return 0;
    
}

void init_array(struct Date *p_date,size_t N)
{
    size_t i ;
    for(i=0;i<N;i++)
    {
        p_date[i].day =  i;
        p_date[i].month = 10 - i;
        p_date[i].year = 2020 + i ;
    }
}


void show_array(struct Date *p_date,size_t N)
{
    size_t  i;
    for(i=0;i<N;i++)
    {
        printf("date at index %llu is %d-%d-%d\n",i,p_date[i].day,p_date[i].month,p_date[i].year);
    }
}