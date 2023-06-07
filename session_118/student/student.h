#ifndef _STUDENT_H
#define _STUDENT_H

struct student 
{
    int roll;
    double marks;
    double attend ;
};

void show(const char *msg, struct student  * arr,int N);
int compare_by_roll(const struct student * ps1,const struct student *ps2);
int compare_by_marks(const struct student * ps1,const struct student *ps2);
int compare_by_attend(const struct student * ps1,const struct student *ps2);

#endif
