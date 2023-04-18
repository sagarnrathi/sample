typedef  long long int ssize_t ;

#include<stdio.h>
#include<stdlib.h>

void test(void);
ssize_t  cpa_strlen(const char *src) ;
char * join(char **pp_str,char *join_str,ssize_t N);

int main(void)
{
    test();
    return (0);
}

ssize_t cpa_strlen(const char *src)
{
    ssize_t i = 0 ; 
    while(src[i]!='\0')
        i++ ;
    return i ;
}

char * join(char **pp_str,char * join_str,ssize_t N)
{
    char *result = NULL ;
    ssize_t len_curr = 0 ;
    ssize_t len_target = 0 ;
    ssize_t len_join = 0 ;
    ssize_t i,k;
    
    ssize_t old_len; 
 
    
    len_join = cpa_strlen(join_str);
    if(len_join < 0)
       {
        puts("Invalid string ");
        exit(EXIT_FAILURE);
       }
    for(i=0;i<N -1 ; i++)
    {  
        len_curr = cpa_strlen(pp_str[i]);

        result = (char *) realloc(result,(len_curr + len_target + len_join));
        if(result == NULL)
        {
            puts("failed to reallocate ");
            exit(EXIT_FAILURE);
        }
        old_len =  len_target ;
        len_target +=(len_curr + len_join);

        for(k=0;k<len_curr;k++)
            result[old_len + k ] = pp_str[i][k] ;
        
        for(k=0;k<len_join;k++)
           result[old_len+len_curr + k ] = join_str[k];
        
    }
    

    len_curr = cpa_strlen(pp_str[i]);
    result = (char *) realloc(result,(len_curr+len_target + 1));
    old_len = len_target ;
    len_target+=len_curr;
     
    for(k=0;k<len_curr;k++)
       {
        
       result[old_len + k] = pp_str[i][k];}
    result[old_len + k] = '\0';
   
    return result ;
}

void test(void)
{
    char *strings[] =  {"sagar","rathi","akot"};
    char *joins = "$$$$";
    char * result = NULL ;
    
    result = join(strings,joins,3);
    printf("result = %s",result) ;

    free(result);
    result = NULL ;
}