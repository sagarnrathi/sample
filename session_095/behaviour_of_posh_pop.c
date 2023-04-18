#define _CRT_RAND_S
#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define VEC_INVALID_INDEX 2
#define VEC_EMPTY 3

struct vector_int
{
    int *arr;
    size_t N ;
} ;

struct vector_int *create_vector_int(void);
void destroy_vector_int(struct vector_int *p_vec_int);

void push_back(struct vector_int *p_vec_int,int new_data);
void push_front(struct vector_int *p_vec_int,int new_data);
void push_at_index(struct vector_int *p_vec_int,size_t index,int new_data);

int pop_back(struct vector_int *p_vec_int,int *p_back_data);
int pop_back(struct vector_int *p_vec_int,int *p_back_data);
int pop_index(struct vector_int *p_vec_int,int *p_data);

int get_index(struct vector_int *p_vec_int,size_t index,int *p_data);
int set_index(struct vector_int *p_vec_int, size_t index,int new_data);

void show(struct vector_int* p_vec_int, const char* msg); 

int main(void)
{
    struct vector_int *p_vec_1 = NULL;
    struct vector_int *p_vec_2 = NULL;
    size_t i;

    unsigned int num;

    p_vec_1 = create_vector_int();
    p_vec_2 = create_vector_int();

    show(p_vec_1,"empty vector 1 : ") ;
    push_back(p_vec_1,1);
    push_back(p_vec_1,22);
    push_back(p_vec_1,333);
    push_back(p_vec_1,4444);
    show(p_vec_1,"after pushing 1,22,333,4444") ;

    show(p_vec_2,"empty vector 2:") ;
    for(i=0;i<10000;i++)
    {
        rand_s(&num) ;
        push_back(p_vec_2,num);
    }
    show(p_vec_2,"after pushing 10000");

    destroy_vector_int(p_vec_1);
    p_vec_1 = NULL;

    destroy_vector_int(p_vec_2);
    p_vec_2 = NULL;

}

struct vector_int * create_vector_int(void)
{
    struct vector_int *p_vec = NULL;

    p_vec = (struct vector_int *) malloc(sizeof(struct vector_int)) ;
    if(p_vec == NULL)
    {
        puts("failed to allocate the memory ");
        exit(-1);
    }
    p_vec->arr =  NULL;
    p_vec->N = 0;
    return(p_vec);
}

void push_back(struct vector_int *p_vec_int,int new_data)
{
    p_vec_int->arr = (int *) realloc(p_vec_int-> arr,
    (p_vec_int->N + 1)*sizeof(int));

    if(p_vec_int ->arr == NULL)
    {
        puts("failed to allocate the memory ");
        exit(-1);
    }

    p_vec_int -> N++;
   
    p_vec_int->arr[p_vec_int->N - 1] = new_data ;
}

void push_front(struct vector_int *p_vec_int,int new_data)
{
    size_t i;
    p_vec_int ->arr = (int * ) realloc(p_vec_int->arr,(p_vec_int->N+1)*(sizeof(int)));
    
    if(p_vec_int->arr == NULL)
    {
        puts("error in resizing the array ");
        exit(EXIT_FAILURE);
    }
    p_vec_int->N +=1;
    for(i=p_vec_int->N-1;i>0;i++)
    {
        p_vec_int->arr[i] = p_vec_int->arr[i -1];
    }
    p_vec_int->arr[0] = new_data ;
}

void push_at_index(struct vector_int *p_vec_int,size_t index,int new_data)
{
    size_t i;

    if(index >=p_vec_int -> N)
        return (VEC_INVALID_INDEX);
    
    p_vec_int -> arr = (int *) realloc(p_vec_int ->arr,(p_vec_int->N+1)*sizeof(int));
    p_vec_int -> N += 1;

    for(i=p_vec_int->N-1;i>index;i--)
        p_vec_int->arr[i] = p_vec_int->arr[i -1];
    
    p_vec_int->arr[index] = new_data ;
    return (SUCCESS);
}


int pop_back(struct vector_int *p_vec_int,int *p_back_data)
{
    
}
int pop_back(struct vector_int *p_vec_int,int *p_back_data);
int pop_index(struct vector_int *p_vec_int,int *p_data);

void show(struct vector_int *p_vec_int,const char* msg)
{
    size_t i;
    if(msg!=NULL)
        puts(msg);
    
    for(i=0;i< p_vec_int->N;i++)
         printf("p_vec_init ->arr[%llu]:%d \n",i,p_vec_int->arr[i]);
}

void destroy_vector_int(struct vector_int * p_vec_int)
{
    free(p_vec_int->arr);
    free(p_vec_int);
    p_vec_int = NULL;
}

