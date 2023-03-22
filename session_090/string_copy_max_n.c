#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int N = 30;
    const char * src = "this is moderate string";
    char * dest = NULL;
    int i = 0;

    dest = (char *) malloc(N);
    
    if(dest == NULL)
    {
        puts("failed in allocating the memory ");
        exit(EXIT_FAILURE);
    }

    while(src[i]!='\0' && i< N)
    {
        dest[i] = src[i];
        i++;
    }
    
    dest[i] = '\0';
   
    printf("dest = %s",dest);
    
    free(dest);
    dest = NULL;
    return(EXIT_SUCCESS);
}