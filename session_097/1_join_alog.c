#include<stdio.h>
#include<stdlib.h>

typedef long long int ssize_t ;

ssize_t cpa_strlen(const char * src);
void test_join(void) ;
char * join(char **pp_str,ssize_t N,char *join_str);

int main(void)
{
    test_join();
    return (0);
}

ssize_t cpa_strlen(const char *src)
{
    ssize_t i = 0;
   
    while(src[i]!='\0')
       ++i;
    return i ;
}

char * join(char **pp_str,ssize_t N,char * join_str)
{
    ssize_t len_curr ;
    ssize_t len_join ;
    char * result = NULL ;
    ssize_t len_old ;
    ssize_t len_result =0 ;
    ssize_t i , k;

    len_join = cpa_strlen(join_str);
    
    if(len_join == 0)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE) ;
    }

    for(i=0;i<N-1;i++)
    {
        len_curr = cpa_strlen(pp_str[i]);

        result = (char *) realloc(result,len_result + len_join + len_curr);
        
        if(result == NULL)
        {
            puts("failed to allocate the memory ");
            exit(EXIT_FAILURE);
        }
        
        len_old = len_result ;
        len_result += (len_curr + len_join) ;

        for(k=0;k<len_result;++k)
            result[len_old + k] = pp_str[i][k] ;
        for(k = 0;k<len_join;k++)
           result[len_old + len_curr + k] = join_str[k];
    }

    len_curr = cpa_strlen(pp_str[i]);

    result = (char *) realloc(result,(len_result + len_curr+ 1));
    
    if(result == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE) ;
    }

    len_old  = len_result ;

    len_result +=(len_curr);

    for(k=0;k<len_curr;k++)
    {
        result[len_old + k] = pp_str[i][k];
    }
  
    result[len_old + k] = '\0';

     return result ;
}

void test_join(void)
{
    char * strings[]  = {
        "sagar","rathi","akot"
    };

    char * join_str  = "$$$" ;
    char * result = NULL ;

    result =join(strings,3,join_str);

    printf("result : %s \n ",result );
    free(result);
    result = NULL ;
}