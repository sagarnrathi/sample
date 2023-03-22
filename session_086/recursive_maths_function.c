#include<stdio.h>
#include<stdlib.h>

long long f(long long N);

int main(void)
{
    long long N = 17;
    long long result ;
 
    result = f(17);
    printf("result is %lld \n",result);

    return (EXIT_SUCCESS);
}

long long f(long long N)
{
    if(N == 0)
       return (1);
    return (3 *f(N/2) +1 ) ;
}