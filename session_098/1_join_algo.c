typedef long long int ssize_t ;

#include<stdio.h>
#include<stdlib.h>

ssize_t cpa_strlrn(const char *src);
char * join(char ** pp_str,char * join_str,ssize_t N);
void test(void);

int main(void)
{
    test();
    return(0);
}
ssize_t cpa_strlen(const char *src)
{
    ssize_t i = 0;
    while(src[i]!='\0')
        ++i ;
    return i ;
}

char *join(char **pp_str,char *join_str,ssize_t N)
{
    char * result = NULL ;
    ssize_t len_result = 0 ;
    ssize_t len_old = 0;
    ssize_t len_join = 0 ;
    ssize_t len_curr  = 0;
    ssize_t i , k ;

    len_join = cpa_strlen(join_str) ;
    if(len_join == 0)
    {
        puts("not a valid str");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<N -1; i++)
    {

      len_curr = cpa_strlen(pp_str[i]);
      result = (char *) realloc(result,(len_result + len_curr + len_join));
      if(result == NULL)
      {
        puts("failed to reallocate the memory ");
      }
      len_old = len_result ;
      len_result +=(len_curr + len_join) ;

      for(k=0;k<len_curr;k++)
          result[len_old + k] = pp_str[i][k];
      for(k=0;k<len_join;k++)
          result[len_old+len_curr+k] = join_str[k];
    }
    
    len_curr  = cpa_strlen(pp_str[i]);
    
    result = (char*) realloc(result,(len_result + len_curr+1));
    if(result == NULL)
    {
        puts("failed to allocate the memory");
        exit(EXIT_FAILURE);
    }
    for(k=0;k<len_curr;k++)
       result[len_result + k] = pp_str[i][k];
    result[len_result + k] = '\0';
    return (result) ;

    
}

void test(void)
{
    char * strings[] = {"sagar","rathi","akot"};
    char * sub = "#$#";
    char * result = NULL ;

    result = join(strings,sub,3) ;
    printf("%s",result);
}