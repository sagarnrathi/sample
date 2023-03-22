#include<stdio.h>
#include<stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

void  allocate(struct  Date **ppdate,size_t *pN);
void  init_array(struct  Date *ppdate,size_t N);
void  show_array(struct  Date *ppdate,size_t N);
void  free_date_array(struct  Date **ppdate);

int main(void)
{
    struct Date * p_date = 0 ;
    size_t N;
     
    allocate(&p_date,&N);
    
    init_array(p_date,N);
    
    show_array(p_date,N);
    free_date_array(&p_date);

    return(0);

}

void allocate(struct Date **ppdate,size_t *pN)
{  

    size_t N = 5;
    struct Date *p_date = 0;
    p_date = (struct Date *) malloc(N * sizeof(struct Date));

    if(p_date == 0)
    {
        puts("error in allocating in memory ");
        exit(EXIT_FAILURE);
    }
    
    *pN = N;
    *ppdate = p_date;
}

void init_array(struct Date *ppdate, size_t N)
{
  size_t i;

 for(i=0;i<N;i++)
   {
   
    ppdate[i].day = i + 1;
    ppdate[i].month = 10 - i ;
    ppdate[i].year = 2020 + i ;
   }

}

void show_array(struct Date *pdate,size_t N){
    size_t i = 0;
    for(i = 0;i< N; i++)
    {
        printf("value at %llu is %d-%d-%d \n",i,pdate[i].day,pdate[i].month,pdate[i].year);
    }
}

void free_date_array(struct Date ** ppdate)
{
    free(*ppdate);
    *ppdate = 0;
}