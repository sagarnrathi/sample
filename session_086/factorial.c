#include<stdio.h>
#include<stdlib.h>

size_t fact(size_t N);

int main(void)
{
    size_t result ;
    
    result = fact(5);
    printf("result = %llu \n",result);

    result = fact(11);
    printf("result = %llu \n ",result);

    result =  fact(20);
    printf("result = %llu \n",result);

    return(EXIT_SUCCESS);

}

size_t fact(size_t N)
{
    if(N == 0)
        return(1);
    else
       return N * fact(N-1);
}