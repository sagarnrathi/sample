#include<stdio.h>
#include<stdlib.h>

int a[5][3];

int main(void)
{
    int i,j;
    printf("addr = %llu \n",(unsigned long long int )a);
    for(i=0;i<5;i++)
        printf("addr[%d] : %llu \n",i,(unsigned long long int)&a[i]);
    
    for(i=0;i<5;i++)
        for(j=0;j<3;j++)
            printf("addr[%d][%d] : %llu   \n",i,j,(unsigned long long int)&a[i][j]);
    
    return 0;
}