#include<stdio.h>
#include<stdlib.h>

typedef long long int ssize_t;

struct vector_str 
{
    char ** pp_str ;
    ssize_t N ;
} ;

struct vector_str * create_vector_str(void) ;
void destroy_str_vector(struct vector_str * p_vec_str);
void show(struct vector_str *p_vec_str,const char *msg) ;

char *cpa_strdup(const char * src) ;
ssize_t cpa_strlen(const char *src);

void push_back(
                struct vector_str * p_vec_str,
                char *new_str 
               );
            
void push_front (
    struct vector_str *p_vec_str , 
    char * new_str 
) ;

int main(void)
{
    struct vector_str * p_vec_str = NULL ;
    p_vec_str = create_vector_str();

    push_back(p_vec_str,"hello");
    push_back(p_vec_str,"world") ;
    push_back(p_vec_str,"corecode ");
    push_back(p_vec_str,"programming ");
    push_back(p_vec_str,"academy ");

    show(p_vec_str,"after few push back ");

    destroy_str_vec(p_vec_str);
    p_vec_str = NULL ;

    return (0);
}

struct vector_str * create_vector_str()
{
    struct vector_str * p_str =NULL;

    p_str = (struct vector_str *) malloc(sizeof(struct vector_str)) ;

    if(p_str == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_str ->pp_str = NULL;
    p_str->N = 0;
    
    return(p_str);
}

void show(struct vector_str *p_vec_str,const char *msg) 

{
    ssize_t i;
    for(i=0;i<p_vec_str->N;++i)
       printf("p_vec_str -> pp_str[%lld ] :%s \n",i,p_vec_str->pp_str[i]);
    
}


destroy_str_vec(struct vector_str *p_str)
{
    ssize_t i;
    for(i=0;i<p_str->N;++i)
        free(p_str->pp_str[i]);
    free(p_str->pp_str);
    free(p_str);
}

void push_back(struct vector_str * p_vec_str, char *new_str )
{
    p_vec_str -> pp_str = (char **) realloc(p_vec_str->pp_str,(p_vec_str->N +  1 )* sizeof(char *)) ;
    
    if(p_vec_str -> pp_str == NULL)
        {
            puts("failed to allocate the memory ");
            exit(EXIT_FAILURE);
         }
    p_vec_str -> N+=1;
    p_vec_str ->pp_str[p_vec_str -> N -1 ] = cpa_strdup(new_str) ;

}

char *cpa_strdup(const char * src) 

{
    ssize_t len = 0,i = 0;

    char *p = NULL;

    len = cpa_strlen(src);

    p = (char *) malloc(len +  1) ;
    for(i=0;i<len;i++)
    {
        p[i] = src[i];
        
    }
   
    p[i] = '\0' ;
   
    return (p) ;

}
            
ssize_t cpa_strlen(const char * src)
{
    ssize_t i = 0;
    while(src[i] !='\0')
       ++i;
    
    return (i) ;

}