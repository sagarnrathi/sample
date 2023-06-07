#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>

unsigned long long int vsum(unsigned int n,...) ;

int main(void)
{
    unsigned long long int rs ;
    rs = vsum(0);
    printf("rs = %llu \n",rs);
    rs = vsum(1,100);
    printf("rs = %llu \n",rs);
    rs = vsum(2,500,200);
    printf("rs = %llu \n",rs);
    rs = vsum(3,1000,200,300);
    printf("rs = %llu \n",rs);
    rs = vsum(5,1500,200,300,400,500);
    printf("rs = %llu \n",rs);
    return(0);
}

unsigned long long int vsum(unsigned int n,...)
{
    va_list ap;
    unsigned long long int summation = 0 ;
    unsigned int i;
    
    va_start(ap, n);   // S3 

    for(i=0;i<n;i++)
        summation += va_arg(ap,int);
    va_end(ap);
    return(summation); 
    
}