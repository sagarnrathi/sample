#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    
   
    #ifdef X
       puts("start of x");
    #endif
    puts("-----------");

    #ifdef Y
       puts("end of Y ");
    #endif

}