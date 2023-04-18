#include<stdio.h>
#include<stdlib.h>

typedef long long int ssize_t ;

ssize_t cpa_strlen(const char * src) ;
ssize_t cpa_substr_index(const char * target_src,const char *sub_str);

void test_cpa_substr_index(void);

int main(void)
{
    test_cpa_substr_index();

    return (0);
}

ssize_t cpa_substr_index(const char * target_str,const char *sub_str)
{
   ssize_t i ,k;
   ssize_t len_target;
   ssize_t len_sub ;

   len_target = cpa_strlen(target_str) ;
   len_sub = cpa_strlen(sub_str) ;

   for(k = 0 ; k < len_target - len_sub ;k++)
    {   for(i = 0; i < len_sub;i++)
       
        if(target_str[k + i] != sub_str[i])
            break;
        
         if(i == len_sub)
           return k; 
    } 
   return -1 ;
}

ssize_t cpa_strlen(const char *src)
{
    ssize_t i = 0;

    while(src[i] != '\0')
       i++ ;
 
   return(i);
}

void test_cpa_substr_index(void)
{
    char * target  = "aaBBBBcccAAAAABBBBCCCaaaaBBx";
    char * sub_str_1 = "xyz";
    char * sub_str_2 = "aa";
    char * sub_str_3 = "AA";
    char * sub_str_4 = "BBBB" ;
    ssize_t i ;

     i = cpa_substr_index(target, sub_str_1); 
    if(i == -1)
        printf("%s is not substring of %s\n", sub_str_1, target); 
    else 
        printf("%s is substr of %s at index %lld\n", sub_str_1, target, i); 
    
    i = cpa_substr_index(target,sub_str_2);
    if(i == -1)
        printf("%s is not substring of %s \n",sub_str_2,target,i);
    else
        printf("%s is substring of %s  at index %lld \n",sub_str_2,target,i);

    i = cpa_substr_index(target,sub_str_3) ;
    if(i == -1)
       printf("%s is not substring of %s  \n",sub_str_3,target,i);
    else
       printf("%s is sunstring of %s at index %lld\n",sub_str_3,target,i);

     i = cpa_substr_index(target,sub_str_4) ;
    if(i == -1)
       printf("%s is not substring of %s \n",sub_str_4,target,i);
    else
       printf("%s is sunstring of %s at index %lld\n \n",sub_str_4,target,i);
    
    

}