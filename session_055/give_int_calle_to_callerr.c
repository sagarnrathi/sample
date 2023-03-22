#include<stdio.h>
#include<stdlib.h>

int  get_integer_1(void);

int *get_integer_2(int init_value);

void get_integer_3(int **p);

int main(void)
{
    int ret ;
    int m = 500;
    int *x = 0;
    int *y = 0;
    
    ret = get_integer_1();
    puts("get integer 1 demo \n");
    printf("ret = %d \n ",ret);
    puts("--------------------------");
    
    x = get_integer_2(m);
    printf("*x = %d \n",*x);
    free(x);
    x=0;

    printf("pointer y before call = %p \n ",y);
    get_integer_3(&y);
    printf("pointer y after call = %p \n ",y);
    *y = 100;
    free(y);
    y  =0;
} 
int get_integer_1(void)
{
    return 20;
}

int *get_integer_2(int init_value)
{
    int *p = 0;
    
    p = (int * ) malloc(sizeof(int));
    if(p==0)
    {
        puts("error in allocation mem");
        exit(-1);
    }
    
    *p = init_value;
    
    return (p);
}
void get_integer_3(int **pp)
{
int *p = 0;
p = (int*) malloc(sizeof(int));
if(p==0)
  {
    puts("out memory ");
    exit(-1);
  }
  printf("p= %p \n ",p);
  **pp = &p ;
}