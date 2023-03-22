#include<stdio.h>
#include<stdlib.h>

int main(void)
{

    char * msg = "this is string to cpy";
    char * cpy = NULL;
    int i = 0;
    int N1= 0;

    while(msg[i]!='\0')
        {
            i++;
            N1++;
        }
    
    cpy = (char *) malloc(N1 +1 );
    if(cpy ==NULL)
    {
        puts("error in allocating the memory ");
        exit(EXIT_FAILURE);
    }
    cpy[N1] = '\0';
    for(i=0;i<N1;i++)
    {
        cpy[i] = msg[i];
    }
    printf("msg is := %s ",cpy);
    free(cpy);
    cpy = NULL;
    
    return(0);
}