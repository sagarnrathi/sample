#include "Date.h"

#ifndef NULL 
#define NULL ((void*)0) 
#endif 

int main(void)
{
    Date_t* p_date = NULL;  
    int status ;
    p_date = create_date(15, 8, 1947); 
    show_date(p_date); 
    set_day(p_date, 2); 
    set_month(p_date, 2); 
    set_year(p_date, 1900); 
    show_date(p_date); 
    status = set_day(p_date, 28);
    if(status == 2)
        printf("invalid date ");
    destroy_date(&p_date); 

    return (0); 
}