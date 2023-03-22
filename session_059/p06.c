#include<stdio.h>
#include<stdlib.h>

struct Date {
int day;
int month;
int year;
};

struct Date * get_date(void);

int main(void)
{
    struct Date *p = 0;
    p = get_date();

    printf("%d %d %d \n",p->day,p->month,p->year);

    free(p);
    p = 0 ;

    return 0 ;
    
 }

 struct Date * get_date(void)
 {
    struct Date *p= 0;
    p = ( struct Date *) malloc(sizeof(struct Date));
    if(p==0){
        puts("failed to allocate the memory ");
        exit(-1);
    }
    p->day = 22;
    p->month = 33;
    p->year = 5555;
   return p;
    
 }
