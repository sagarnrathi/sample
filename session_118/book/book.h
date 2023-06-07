#ifndef _BOOK_H
#define _BOOK_H

struct Book
{
    int book_edition ;
    int bk_nr_pages ;
    double book_price ;
};

void show(const char *msg,const struct Book * book_arr,int N);
int compare_by_edition(const struct Book * pb1,const struct Book *pb2);
int compare_by_pages(const struct Book * pb1,const struct Book *pb2);
int compare_by_price(const struct Book * pb1,const struct Book * pb2);

#endif