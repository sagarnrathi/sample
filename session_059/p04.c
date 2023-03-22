#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int Day;
    int Month;
    int Year;
};

void show_date (struct Date * pDate);

int main(void)
{

struct Date exam_date = {1,2,2023};
struct Date *pDate = 0;


pDate = (struct Date *) malloc(sizeof(struct Date));

if(pDate==0){
    puts("failed  to allocate memory ");
    exit(-1);
}

pDate->Day = 30;
pDate->Month = 33;
pDate->Year=3030;
show_date(&exam_date);
show_date(pDate);

free(pDate);
pDate = 0 ;

}

void show_date(struct Date * pDate)
{
    printf("%d %d %d \n",pDate->Day,pDate->Month,pDate->Year);
}