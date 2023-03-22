#include<stdio.h>
#include<stdlib.h>

size_t cpa_strlen_1(const char *msg);

size_t cpa_strlen_1(const char *msg)
{
    size_t len = 0;
    size_t i;
    
    for(i=0;msg[i]!= '\0';i++)
    {
     len++;
    }
    
    return (len);

}

void cpa_strlen_2(const char *msg,size_t *p_len);

void cpa_strlen_2(const char *msg,size_t *p_len)
{
    size_t i=0;
    while(msg[i]!='\0')
         i++;
    *p_len = i;
}

void cpa_strcpy_1(char *dest,char *src)
{
    size_t i;

    while(src[i]!='\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char *cpa_strcpy_2(const char *src)
{
    char *dest = NULL;
    size_t i;
    size_t N;
    
    N = cpa_strlen_1(dest);

    dest = (char * ) malloc(N+1);
    dest[N] = '\0';

    for(i=0;i<N;i++)
    {
        dest[i] = src[i];
    }

    return dest;

}

void cpa_strcpy_3(const char *src,char **pp_dest_str);

void cpa_strcpy_3(const char *src,char **pp_dest_str)
{
    char * dest = NULL;
    size_t i = 0;
    size_t N = 0;

    N = cpa_strlen_3(src);

    dest = (char *) malloc(N);
    if(dest ==NULL)
    {
        puts("error in allocating the memory ");
        exit(EXIT_FAILURE);
    }

    while(src[i]!='\0')
    {
        dest[i] = src[i];
        i++;
    }
    *pp_dest_str = dest;
    free(dest);
    dest = NULL; 
}

void cpa_strcat_1(char *dest,const char *src1,const char *src2);

void cpa_strcat_1(char *dest,const char *src1,const char *src2)
{

    size_t N1 = cpa_strlen_1(src1);
    cpa_strcpy_1(dest,src1);
    cpa_strcpy_1(dest+N1,src2);
}

char * cpa_strcat_2(const char* src1,const char *src2);

char * cpa_strcat_2(const char * src1,const char *src2)
{
    char * dest = NULL;
    int N1 = cpa_strlen_1(src1);
    int N2 = cpa_strlen_1(src2);

    dest = (char *) malloc((N1 + N2 + 1 ));

    cpa_strcpy_1(dest,src1);
    cpa_strcpy_1(dest + N1,src2);
}

void cpa_strcat_3(char *src1,char * src2,char **dest);

void cpa_strcat_3(char *src1,char *src2,char **dest)
{
     char *ret = NULL;
     int N1,N2;
      
    N1 = cpa_strlen_1(src1);
    N2 = cpa_strlen_1(src2);

    ret = (char *) malloc(N1 + N2 + 1);

    cpa_strcpy_1(ret,src1);
    cpa_strcpy_1(ret + N1 ,src2)  ;
    
    *dest = ret ;
    free(ret);
    ret = NULL;
}