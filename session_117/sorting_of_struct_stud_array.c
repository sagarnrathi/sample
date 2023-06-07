#include<stdio.h>
#include<stdlib.h>

struct student
{
 
    int roll_number ;
    double marks;
    double attend ;
};

void show(const char *msg,struct student *p_std,int N);
void sort_roll(struct student * p_std,int N);
void sort_marks(struct student *p_std,int N);
void sort_attend(struct student * p_std,int N);

struct student st_arr[5] = 
{
    {2, 89.54, 89.12}, 
    {4, 77.32, 91.23}, 
    {5, 98.3, 99.93}, 
    {3, 74.91, 65.63},
    {1, 72.69, 56.79}
};

int main(void)
{
    show("before sort ",st_arr,5);
    sort_roll(st_arr,5);
    show("after sort by roll",st_arr,5);
    sort_marks(st_arr,5);
    show("after marks sorted ",st_arr,5);
    sort_attend(st_arr,5);
    show("after sort by attend",st_arr,5);

    return(EXIT_SUCCESS);
}

void show(const char * msg,struct student *p_std,int N)
{
    int i ;
    if(msg)
       puts(msg);

    for(i=0;i<N;i++)
    {
        printf("roll = %d \t marks = %f  \t attend = %f \n",p_std[i].roll_number,p_std[i].marks,p_std[i].attend);

    }
}

void sort_roll(struct student * p_std, int N)
{
    int i,j ;
    struct student key ;
    for(j=1;j<N;++j)
    {
        key.roll_number = p_std[j].roll_number;
        key.attend      = p_std[j].attend ;
        key.marks       = p_std[j].marks ;

        i  = j - 1 ;

        while(i > -1 && p_std[i].roll_number > key.roll_number) 
        {
            p_std[i+1].roll_number = p_std[i].roll_number ;
            p_std[i+1].marks       = p_std[i].marks ;
            p_std[i + 1].attend    = p_std[i].attend ;
            i = i -1 ; 
        }
        p_std[i + 1].attend = key.attend ;
        p_std[ i + 1].marks = key.marks ;
        p_std[i + 1].roll_number = key.roll_number ;
    }
}


void sort_marks(struct student* p_st_arr, int N)
{
    int i, j; 
    struct student key; 

    for(j = 1; j < N; ++j)
    {
        key.roll_number  = p_st_arr[j].roll_number; 
        key.marks = p_st_arr[j].marks; 
        key.attend = p_st_arr[j].attend; 
        
        i = j - 1; 

        while(i > -1 && p_st_arr[i].marks > key.marks)
        {
            // memcpy(p_st_arr + i + 1, p_st_arr + i, sizeof(struct student)); 
            p_st_arr[i+1].roll_number = p_st_arr[i].roll_number; 
            p_st_arr[i+1].marks = p_st_arr[i].marks; 
            p_st_arr[i+1].attend = p_st_arr[i].attend; 
            i = i - 1; 
        }

        p_st_arr[i+1].roll_number  = key.roll_number; 
        p_st_arr[i+1].marks = key.marks; 
        p_st_arr[i+1].attend = key.attend; 
        
    }
}

void sort_attend(struct student* p_st_arr, int N)
{
    int i, j; 
    struct student key; 

    for(j = 1; j < N; ++j)
    {
        key.roll_number  = p_st_arr[j].roll_number; 
        key.marks = p_st_arr[j].marks; 
        key.attend = p_st_arr[j].attend; 
        
        i = j - 1; 

        while(i > -1 && p_st_arr[i].attend > key.attend)
        {
            // memcpy(p_st_arr + i + 1, p_st_arr + i, sizeof(struct student)); 
            p_st_arr[i+1].roll_number = p_st_arr[i].roll_number; 
            p_st_arr[i+1].marks = p_st_arr[i].marks; 
            p_st_arr[i+1].attend = p_st_arr[i].attend; 
            i = i - 1; 
        }

        p_st_arr[i+1].roll_number  = key.roll_number; 
        p_st_arr[i+1].marks = key.marks; 
        p_st_arr[i+1].attend = key.attend; 
        
    }
}
