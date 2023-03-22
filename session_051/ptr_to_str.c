#include<stdio.h>
#include<stdlib.h>

struct Date {
    int Day ;
    int month;
    int year;
};

int main(void)
{
    struct Date exam_date;
    struct Date *p_exam_date;
    int dd ,mm ,yy;

    p_exam_date = &exam_date;
    (*p_exam_date).Day = 5;
    (*p_exam_date).month = 12;
    (*p_exam_date).year = 2022;

    dd = (*p_exam_date).Day;
    mm = (*p_exam_date).month;
    yy = (*p_exam_date).year;

    printf("%d-%d-%d ",dd,mm,yy);
}