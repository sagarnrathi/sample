#include<stdlib.h>
#include<stdio.h>
int main(void)
{
    int a[5] = {9,8,7,6,5};
    /*int (*p)[5] = &a; 
    for(int i = 0;i < 5 ; i++)
    {
     printf(" value is %d \n",(*p)[i]);
    }
*/
    int *p = &a[0];
    for(int i = 0;i < 5 ; i++)
    {
     printf(" value is %d \n",*(p + i));
    }
    
}