#include<stdio.h>
#include<stdlib.h>

int strlen(char *src);

int main(void)
{
    char *str = "sagar rathi";
    int len = strlen(str);
    printf("elnght id string is %d ",len);
}

int strlen(char *src)
{
    int i =0;
    while(src[i]!='\0')
    {
        i++;
    }
    return i;
}