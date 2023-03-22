#include<stdio.h>
#include<stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Date * allocate(size_t *N);
void init(struct Date *p_date,size_t N);
void show(struct Date *p_date,size_t N);
void free_a(struct Date **p_date);

int main(void)
{
    size_t N = 5;
    struct Date *p_date =    allocate(&N);
    init(p_date,N);
    show(p_date,N);
    free_a(&p_date);

    return(0);
}

struct Date * allocate(size_t * pN)
{
    struct Date *p_date  = 0;
    size_t  N = 5;
    p_date = (struct Date *) malloc(N * sizeof(struct Date));

    if(p_date == 0)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    *pN = N;
    return p_date;
}

void init(struct Date *p_date,size_t N)
{
    int i;
    for(i=0;i<N;i++)
    {
        p_date[i].day = i + 1;
        p_date[i].month = i + 10;
        p_date[i].year = i + 2020;
    }
}

void show(struct Date *p_date,size_t N)
{
    int i;
    for(i=0;i<N;i++)
    {
      printf("valu at index %d is %d-%d-%d \n",i, p_date[i].day,p_date[i].month,p_date[i].year) ;
    }
}

void free_a(struct Date ** p)
{
free(*p);
*p = 0;
}