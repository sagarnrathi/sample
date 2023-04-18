#include<stdio.h>
#include<stdlib.h>

void caller_of_split(void);

int main(void)
{
    caller_of_split() ;
    return 0;
}

char ** cpa_split(char * src,char sep ,int *pN)
{
    char ** words_of_str = NULL ;
    char * word = NULL ;
    int N = 0 ;
    int word_len ;

    int i,j,k ; 
    i = 0;
    
    while(1)
    {

        for(j=i;src[j] !='\0' && src[j] !=':';++j)
          ;
        word_len = j - i ;
        if(word_len == 0)
           {
            
             i = j + 1 ;
             continue ;
           }
        word = (char*)malloc(word_len+1); 
        word[word_len] = '\0' ;
        
        for(k=0;k<word_len;k++)
           word[k] = src[i + k] ;
        
        words_of_str = (char **) realloc(words_of_str,(N + 1) * sizeof(char *));

        if(words_of_str == NULL)
           {
            puts("failed to allocate the memory ") ;
            exit(EXIT_FAILURE);
           }
        
        N +=1;
        words_of_str[N -1] = word ;
        if(src[j] == '\0' || (src[j] == ':' && src[j+1]=='\0'))
            break; 

        i=j+1;
    }

    *pN = N;
    return(words_of_str) ;
}

void caller_of_split(void)
{
    char * str = "sagar:rathi:akot:tcs" ;
    char sep = ':' ;
    char ** words_str = NULL ;
    int N = -1 ;
    int i;
    puts("caller of spirit ") ;
    words_str = cpa_split(str,sep,&N);
    puts("for loop") ;
    for(i=0;i<N;i++)
        printf("words in str[%d] : %s \n",i,words_str[i]);
    
    for(i=0;i<N;i++)
        free(words_str[i]) ;
    free(words_str);
    str = 0 ;
}