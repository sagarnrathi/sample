#include<stdio.h>
#include<stdlib.h>

int main(void)

{
  const char *src = "this is moderatly long string ";
  char * dest = NULL;
  int i=0,n=0;
  
  while(src[i]!='\0')
  {
    i++;
    n++;
  }
  
  dest = (char *) malloc(n);
  if(dest == NULL)
  {
    puts("failed to allocate the memory ");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<n;i++)
  {
    dest[i] = src[i];

  }

  dest[i] = '\0';
  printf(" src = %s \n dest = %s ",src,dest);
  free(dest);
  dest = NULL;
  
  return (EXIT_SUCCESS);
}