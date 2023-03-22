#include<stdio.h>
#include<stdlib.h>

size_t fab(size_t N);

int main(void)
{
    puts("5th term of fib sequence ");
    printf("fib(5) = %llu \n",fab(5));

    puts("11th term of fib squence ");
    printf("fib(11) = %llu \n",fab(11));
    
    return (EXIT_SUCCESS);

}

size_t fab(size_t N)
{
    if(N == 0)
        return (0);
    
     if(N==1)
        return (1);
    return (fab(N-1 ) + fab(N -2));
}