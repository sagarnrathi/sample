#include<stdio.h>
#include<stdlib.h>

int f1()
{
    return (0);
}

void caller_of_f1()
{
    int n1 ;
    n1 = f1();
}

void f2(int *p_int)
{
    *p_int =  0 ;
}

void caller_of_f2()
{
    int n1;
    f2(&n1) ;
}

int *f3()
{
    int *p = 0;
    p = (int *) malloc(sizeof(int));
    if(p==0)
    {
        puts("error");
        exit(-1);

    }
    return p;
}

void caller_of_f3(void)
{
    int *p_ret = NULL;
    p_ret = f3();
    *p_ret = 100 ;
    printf("p_ret = %d ",*p_ret);
    free(p_ret);
    p_ret = NULL;
}

void f4(int** pp_int)
{
    int * ptr= NULL;
    ptr  = (int *) malloc(sizeof(int));
    if(ptr == NULL)
    {
        puts("failed to allocate the memory ") ;
        exit(EXIT_FAILURE);
    }
    *pp_int = ptr ;
}

void caller_of_f4(void)
{
    int *pn =NULL;
    f4(&pn);
    *pn = 100;
    printf("pn is %d ",*pn);
    free(pn);
    pn = NULL;
}

int **f5(int *pN)
{
    int **pp_int = NULL;
    int i;

    pp_int  = (int **) malloc(5 * sizeof(int *));
    if(pp_int ==NULL)
    {
        puts("failed to allocate the memory ");
        exit(-1);
    }

    for(i=0;i<5;i++)
    {
        pp_int[i] = (int *) malloc(sizeof(int));
        if(pp_int[i] == NULL)
        {
            puts("failed to allocate the memory ");
            exit(-1);
        } 
    }
    *pN = 5;
    return (pp_int );
}

void caller_of_f5(void )
{
    int **pp = NULL;
    int N;
    int i;
    pp = f5(&N);

    for(i=0;i<N;i++)
        *pp[i] = (i+1) * 100;
    
    for(i=0;i<N;i++)
        free(pp[i]) ;
    free(pp);
    pp = NULL;
}

void f6(int ***ppp_int ,int *pn)
{
    int **pp = NULL ;
    int i;
    pp = (int **) malloc(5 *sizeof(int *));
    if(pp == NULL)
    {
        puts("error ") ;
        exit(EXIT_FAILURE);
    }
    for(i=0;i<5;i++)
    {
        pp[i] = (int *) malloc(sizeof(int)) ;
        if(pp[i] == NULL)
        {
            puts("failed to allocate the memory ");
            exit(EXIT_FAILURE);
        }
        
    }
    *pn = 5 ;
    *ppp_int = pp;
}

void caller_of_f6(void)
{
    int ** pp_int_of_caller = NULL;
    int N = -1 ;
    int i;
    
    f6(&pp_int_of_caller,&N);
    
    for(i=0;i<N;i++)
        *pp_int_of_caller[i] = (i + 1 ) * 100 ;
    
    for(i=0;i<N;i++)
         printf("*pp_int_of_caller[%d]:%d\n", i, 
                *pp_int_of_caller[i]); 
    for(i=0;i<N;i++)
         free(pp_int_of_caller[i]);
    free(pp_int_of_caller);
    pp_int_of_caller = NULL ;

}

int main(void)
{
    caller_of_f1();
    caller_of_f2();
    caller_of_f3();
    caller_of_f4();
    caller_of_f5();
    caller_of_f6();
}