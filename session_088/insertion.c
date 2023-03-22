#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[10] = {2,4,3,65,4,-55,32,43,78,11};
    int i,j;
    int key ;
    for(i=1;i<10;i++)
      { 
        j = i-1;
        key = a[i];

        while(j> -1 && a[j]> key)
        {
          a[j+1] = a[j];
          j--;
        }

      a[j + 1] = key;
      }
    for(i=0;i<10;i++)
    printf("%d \n",a[i]);

}