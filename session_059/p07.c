#include<stdio.h>
#include<stdlib.h>

struct Date 
{
    int day;
    int month;
    int year;
};

void get_date(struct Date **pp_date);
void show_date(struct Date *p_date);
void release_date(struct Date **pp_date);

int main(void)
{
     struct Date *pdate =0;
     
     get_date(&pdate);
     show_date(pdate);
     release_date(&pdate);

     return 0;
    
}

void get_date(struct Date ** ppDate)
{
    struct Date *pDate = 0;
    pDate = (struct Date *) malloc(sizeof(struct Date));
    if(pDate == 0){
        puts("Failed to allocate memory ");
        exit(-1);
    }
    pDate->day = 11;
    pDate->month=11;
    pDate->year = 1111;
    *ppDate = pDate;
}

void show_date(struct Date *pDate)
{
printf("%d %d %d \n",pDate->day,pDate->month,pDate->year);
}

void release_date(struct Date **pp_date)
{
    free(*pp_date);
    *pp_date = 0;
}