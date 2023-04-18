char** cpa_split(const char* src, char sep, int* pN); 

void caller_of_cpa_split()
{
    char* str = "abc:pqrst:uvw:Yogeshwar:Shukla:CPA"; 
    char sep = ':'; 

    char** words_in_str = 0; 
    int N = -1; 

    int i; 

    words_in_str = cpa_split(str, sep, &N); 
    for(i = 0; i < N; ++i)
        printf("words_in_str[%d]:%s\n", i, words_in_str[i]); 

    for(i = 0; i < N; ++i)
        free(words_in_str[i]); 
    
    free(words_in_str); 
    words_in_str = 0; 
}

/////////////////////////////////////////////////////////

void cpa_split(const char* src, char sep, char*** ppp_str, int* pN); 

void caller_of_cpa_split()
{
    char* str = "abc:pqrst:uvw:Yogeshwar:Shukla:CPA"; 
    char sep = ':'; 

    char** words_in_str = 0; 
    int N = -1; 

    int i; 

    cpa_split(str, sep, &words_in_str, &N); 
    for(i = 0; i < N; ++i)
        printf("words_in_str[%d]:%s\n", i, words_in_str[i]); 

    for(i = 0; i < N; ++i)
        free(words_in_str[i]); 
    
    free(words_in_str); 
    words_in_str = 0; 
}