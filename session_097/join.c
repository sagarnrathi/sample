#include <stdio.h> 
#include <stdlib.h> 

typedef long long int ssize_t; 

char* join(char** pp_str, ssize_t N, char* join_str); 
void test_join(void); 
ssize_t cpa_strlen(const char* src); 

int main(void)
{
}

char* join(char** pp_str, ssize_t N, char* join_str)
{
    char* result = NULL; 
    ssize_t len_join_str; 
    ssize_t len_curr_str; 

    len_join_str = cpa_strlen(join_str); 
    if(len_join_str == 0)
    {
        puts("Invalid join string"); 
        exit(EXIT_FAILURE); 
    }
    


}

void test_join(void) 
{
    char* strings[] = {
        "CoreCode", 
        "Programming", 
        "Academy", 
        "Yogeshwar", 
        "Shukla"
    }; 

    char* join_str = "#$#";
    char* result = NULL; 

    result = join(strings, 5, join_str); 
    printf("result = %s\n", result); 
    /* 
        Expected result: 
        CoreCode#$#Programming#$#Academy#$#Yogeshwar#$#Shukla
    */

   free(result); 
   result = NULL; 
}

ssize_t cpa_strlen(const char* src)
{
    ssize_t i; 
    ssize_t len; 

    len = 0; 
    i = 0; 
    while(src[i] != '\0')
    {
        ++i; 
        ++len; 
    }

    return len; 
}