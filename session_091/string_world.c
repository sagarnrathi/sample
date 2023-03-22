#include<stdio.h>
#include<stdlib.h>

void test_1(void);
void test_2(void);

char *callee_1(int *pN);
void caller_1(void);

int main(void)
{
    test_1();
    caller_1();
    test_2();
    return (0);
}


void test_1(void)
{
    char a[6] = {'h','e','l','l','o','\0'};
    int i;
    for(i=0;i<5;i++)
       printf("a[%d] : %c \n",i,a[i]);
    
    char *pa = a;
    for(i=0;i<5;i++)
       printf("a[%d]  : %c \n",i,a[i]);
}

void caller_1(void)
{
    char * p_string = NULL;
    int str_len = 0 ;
    int i;
    p_string = callee_1(&str_len);
    for(i=0;i<5;i++)
       printf("p_string[%d] : %c \n",i,p_string[i]);
    free(p_string);
    p_string  = NULL;
}

char *callee_1(int *pn)
{
    int N = 5;
    char *p_str = NULL;

    p_str = (char *) malloc(N + 1);
    if(p_str == NULL)
    { 
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    p_str[0] = 'H';
    p_str[1] = 'E';
    p_str[2] = 'L';
    p_str[3] = 'L';
    p_str[4] = 'o';
    p_str[5] = '\0';
    *pn = 5;
    return (p_str);
}

void test_2(void)
{
    int i;
    char ** pp_str = NULL;
    char *p_char[5] = {
     "abc",
     "pqr",
     "xyz",
     "lmn",
     "ijk"
    };

    puts("in test 2");

    for(i=0;i<5;i++)
        printf("pp_char[%d] : %s \n",i,p_char[i]);
    printf("\n");
    pp_str = p_char;
    for(i=0;i<5;i++)
       printf("pp_str[%d] : %s \n",i,pp_str[i]);
       
    
}