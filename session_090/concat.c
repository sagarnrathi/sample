#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char *msg1 = "sagar ";
    char *msg2 = "rathi";
    char * dest = NULL;
    int n1=0,n2=0,i=0;
    
    while(msg1[i]!='\0')
      {
        n1++;
        i++;
      }
    i = 0;
    while(msg2[i]!='\0')
    {
       n2++;
       i++;
    }
    
    
    dest = (char *) malloc(n1 + n2 + 1);
    if(dest == NULL)
    {
        puts("failed to allocate memory ");
        exit(EXIT_FAILURE);
    }
    dest[n1 + n2] = '\0';
    for(i=0;i<n1;i++)
    {
        dest[i] = msg1[i];
    }
    
    for(i=0;i<n2;i++)
    {
        dest[n1 + i] = msg2[i];
    }

    printf("destination string is := %s \n",dest);
    free(dest);
    dest = NULL;

    return (EXIT_SUCCESS);

}