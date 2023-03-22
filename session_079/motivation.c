#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[5] = {1,2,33,5,6};
    int s = 10;
    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(a[i] + a[j]<=s)
            printf("%d %d \n",a[i],a[j]);
        }
    }
}