#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char *p = "21/03/2023";
    char **arr = NULL;
    int count = 0 ,i=0;
    int temp = 0;
    while(p[i]!='\0')
       if(p[i] == '/')
          count++ ;
    arr = (char **)malloc(count * sizeof(char*)) ;
    if(arr == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<=count;i++)
    {
        for(temp=0;temp<)
        arr[i] = ()
    }
}