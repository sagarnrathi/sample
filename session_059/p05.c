#include<stdio.h>
#include<stdlib.h>

struct Date{
int day;
int month;
int year;
};

void initialize_date(struct Date *pdate,int day,int month,int year);
void show_date(struct Date *pDate);

int main(void)
{
struct Date date;
struct  Date *pdate = 0;

puts("this is prgm 05 \n");
pdate = (struct Date *) malloc(sizeof(struct Date));

if(pdate == 0)
{
        puts("failed to allocate the memory ");
        exit(-1);
}
initialize_date(&date,2,22,2222);
initialize_date(pdate,3,33,3333);

show_date(&date);
show_date(pdate);

free(pdate);
pdate = 0 ;

return 0;
}

void initialize_date(struct Date *pdate,int day,int month,int year)
{
    pdate->day = day;
    pdate->month = month;
    pdate->year = year;
}

void show_date(struct Date *pdate)
{
    printf("%d %d %d \n",pdate->day,pdate->month,pdate->year);
}