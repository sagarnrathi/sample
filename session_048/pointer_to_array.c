#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int A[5] = {100,200,300,400,500};
    int i,n;
    int (*p_arr)[5];
    puts("print array using name");
    for(i=0;i<5;i++)
    {
        printf("a[%d] :  %d \n",i,A[i]);

    }
   puts("print array usig pointer ");

   p_arr = &A;
   for(i=0;i<5;i++){
    n = (*p_arr)[i];
    printf("n = %d \n",n) ;

   }
   return(0);

}