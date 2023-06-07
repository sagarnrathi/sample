#include<stdio.h>
#include<stdlib.h>

#include "book.h"
#include "sort.h"

struct Book bk_arr[5]= {
     {3, 300, 560.5}, 
    {1, 589, 600.0}, 
    {2, 150, 250.0}, 
    {1, 1000, 1250.5}, 
    {5, 1235, 1780.5}
};

int main(void)
{
    show("before sort ",bk_arr,5);
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_edition);
    show("after compare by edition",bk_arr,5);
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_pages);
    show("after compare by pages ",bk_arr,5);
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_price);
    show("after comapre by price ",bk_arr,5);
    return(0);
}

void show(const char *msg,const struct Book * bk_arr,int N)
{
    int i ;
    if(msg)
        puts(msg);
    for(i= 0 ;i < N;i++)
    printf(" Edition = %d \t NR_pages  = %d \t price = %.2lf \n",bk_arr[i].book_edition,bk_arr[i].bk_nr_pages,bk_arr[i].book_price);
}

int compare_by_edition(const struct Book * pb1,const struct Book *pb2)
{

 if(pb1-> book_edition > pb2->book_edition)
     return 1;
 else if (pb1 -> book_edition < pb2 -> book_edition)
    return -1;
else 
     return 0;    
}

int compare_by_pages(const struct Book * pb1, const struct Book * pb2)
{
     if(pb1-> bk_nr_pages > pb2->bk_nr_pages)
     return 1;
 else if (pb1 -> bk_nr_pages < pb2 -> bk_nr_pages)
    return -1;
else 
     return 0;  
}

int compare_by_price(const struct Book * pb1, const struct Book * pb2)
{
     if(pb1-> book_price > pb2->book_price)
     return 1;
 else if (pb1 -> book_price < pb2 -> book_price)
    return -1;
else 
     return 0;  
}