#include<stdio.h>
#include<stdlib.h>
#include"student.h"
#include"sort.h"


struct student st_arr[5] = {
    {2, 89.54, 89.12}, 
    {7, 77.32, 91.23}, 
    {5, 98.3, 99.93}, 
    {3, 74.91, 65.63},
    {1, 72.69, 56.79}  
}; 


int main(void)
{
    show("before sort :",st_arr,5);
    cpa_sort(st_arr,5,sizeof(struct student),compare_by_roll);
    show("after sort by roll",st_arr,5);
    cpa_sort(st_arr,5,sizeof(struct student),compare_by_marks);
    show("after sort by marks",st_arr,5);
    cpa_sort(st_arr,5,sizeof(struct student),compare_by_attend);
    show("after sort by atend",st_arr,5);
    return 0 ;
}
void show(const char *msg, struct student  * p_arr,int N)
{
    int i ;
    if(msg)
       puts(msg);

    for(i=0;i<N;i++)
    {
        printf("roll = %d \t marks = %.2lf \t attend = %.2lf \n",p_arr[i].roll,p_arr[i].marks,p_arr[i].attend);
    }
}

int compare_by_roll(const struct student * ps1,const struct student *ps2)
{
    if(ps1->roll > ps2 -> roll)
       return 1;
    else if (ps1-> roll <ps2-> roll)
       return -1;
    else 
       return 0 ;
}


int compare_by_marks(const struct student* ps1, const struct student* ps2)
{
    if(ps1->marks > ps2->marks)
        return (1); 
    else if(ps1->marks < ps2->marks)
        return (-1); 
    else 
        return (0); 
}


int compare_by_attend(const struct student* ps1, const struct student* ps2)
{
    if(ps1->attend > ps2->attend)
        return (1); 
    else if(ps1->attend < ps2->attend)
        return (-1); 
    else 
        return (0); 
} 