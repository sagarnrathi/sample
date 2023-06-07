#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student 
{
    int roll;
    double marks;
    double attend;
};

void show(const char *msg,struct student * p_std,int N);

void sort(struct student *arr,int N,int(*compare)(const struct student *ps1,const struct student *ps2));

int compare_by_roll(const struct student * ps1,const struct student *ps2);
int compare_by_marks(const struct student * ps1,const struct student *ps2);
int compare_by_attend(const struct student * ps1,const struct student *ps2);

struct student st_arr[5]  = 
{
     {2, 89.54, 89.12}, 
    {4, 77.32, 91.23}, 
    {5, 98.3, 99.93}, 
    {3, 74.91, 65.63},
    {1, 72.69, 56.79}  
} ;

int main(void)
{
    show("before sort ",st_arr,5);
    sort(st_arr,5,compare_by_roll);
    show("after sort by roll ",st_arr,5);
    sort(st_arr,5,compare_by_attend);
    show("after sort by attend ",st_arr,5);
    sort(st_arr,5,compare_by_marks);
    show("after sort by marks",st_arr,5);
    return(0);
}

void sort(struct student * st_arr,int N,int(* compare)(const struct student *ps1,const struct student *ps2))
{
    int i,j;
    struct student key;
    for(j = 1;j<N;j++)
    {
        memcpy(&key,&st_arr[j],sizeof(struct student));
        i = j - 1 ;
        while(i > -1 && (compare(&st_arr[i],&key))>0)
        {
            memcpy(&st_arr[i + 1],&st_arr[i],sizeof(struct student));
            i = i - 1 ;

        }
        memcpy(&st_arr[i + 1],&key,sizeof(struct student));
    }
}

void show(const char *msg,struct student *st_arr,int N)
{
    int i;
    if(msg)
        puts(msg);
    for(i= 0 ; i<N;i++)
    {
        printf("roll no = %d \t marks = %.2lf \t attend = %.2lf \n",st_arr[i].roll,st_arr[i].marks,st_arr[i].attend);
    }
}

int compare_by_roll(const struct student * ps1,const struct student *ps2)
{
    if(ps1->roll > ps2 -> roll)
       return 1;
    else if(ps1 -> roll < ps2-> roll)
        return -1;
    else 
      return 0 ;
}
int compare_by_marks(const struct student * ps1,const struct student *ps2)
{
    if(ps1->marks > ps2 -> marks)
       return 1;
    else if(ps1 -> marks < ps2-> marks)
        return -1;
    else 
      return 0 ;
}
int compare_by_attend(const struct student * ps1,const struct student *ps2)
{
    if(ps1->attend > ps2 -> attend)
       return 1;
    else if(ps1 -> attend < ps2-> attend)
        return -1;
    else 
      return 0 ;
}