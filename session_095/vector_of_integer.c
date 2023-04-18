#define _CRT_RAND_S

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS           1
#define VEC_INVALID_INDEX 2
#define VEC_EMPTY         3

struct vector_int{
    int *arr;
    size_t N;
};

struct vector_int *create_vector_int(void);
void destroy_vector_int(struct vector_int * p_vec_int);

void push_back(struct vector_int *p_vec_int,int new_data);
void push_front(struct vector_int *p_vec_int,int new_data);
int push_at_index(struct vector_int *p_vec_int,size_t index,int new_data);

int pop_back(struct vector_int * p_vec_int,int *p_back_data);
int pop_frontt(struct vector_int *p_vec_int,int *p_front_data);
int pop_index(struct vector_int *p_vec_int,size_t index,int *p_data);

int get_index(struct vector_int *p_vec_int,size_t index,int *p_data);
int set_index(struct vector_int *p,size_t index,int new_data);

size_t get_size(struct vector_int *p_vec);
void show(struct vector_int *p_vec,const char *msg);

int main(void)
{
    int data;
    int status;
    struct vector_int * p_vec = NULL;
    
    p_vec  =  create_vector_int();

    show(p_vec,"Initial state : ");
    
    for(data=5;data<=20;data = data +5)
        push_back(p_vec,data);
    show(p_vec,"after pushing 5,10,15,20") ;

    for(data = 25;data <=40;data = data + 5)
       push_front(p_vec,data);
    show(p_vec,"after pushing 25,30,35,40");
    show(p_vec,"before push at index (p_vec,3,500)");
    status =  push_at_index(p_vec,1,500);
    if(status == SUCCESS)
    {
        printf("popped at index data = %d \n",data);
        show(p_vec,"after pop_index(p_vec,3,data)") ;
    }
 /*   
    status  = pop_back(p_vec,&data) ;
    if(status == SUCCESS)
    {
     printf("poped front data = %d \n",data);
     show(p_vec,"after pop back");
    }

    status = pop_front(p_vec,&data);
    if(status == SUCCESS)
    {
        printf("poped front data  = %d \n",data);
        show(p_vec,"after pop front ");
    }

    if(status == SUCCESS)
    {
        printf("popped at index data = %d \n",data);
        show(p_vec,"after pop_index(p_vec,3,data)") ;
    }
*/
    destroy_vector_int (p_vec);
    p_vec = NULL;
    
    return(EXIT_SUCCESS);
}

struct vector_int *create_vector_int(void)
{
    struct vector_int *p_vec = NULL;
    p_vec = (struct vector_int *) malloc(sizeof(struct vector_int));

    if(p_vec == NULL) 
    {
    puts("failed to allocate the memory ");
    exit(EXIT_FAILURE);
    }
    p_vec-> arr = NULL;
    p_vec->N = 0;

    return(p_vec);
}

void push_back(struct vector_int *p_vec_int,int new_data)
{
    p_vec_int-> arr = (int *) realloc(p_vec_int->arr,sizeof( int)*(p_vec_int->N + 1)) ;

    if(p_vec_int->arr == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);

    }
    p_vec_int ->arr[p_vec_int->N] = new_data;
    p_vec_int->N+=1;

}

void push_front(struct vector_int *p_vec_int,int new_data)
{
    size_t i;
    printf("int front");
    p_vec_int -> arr = (int *) realloc(p_vec_int->arr,(p_vec_int->N+1)*sizeof(int));

    if(p_vec_int->arr == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    
    p_vec_int->N+=1;
    for(i=p_vec_int->N-1;i>0;i--)
    {
        
        p_vec_int->arr[i] =  p_vec_int->arr[i-1];
    }
    
    p_vec_int->arr[0] = new_data ;
    
}

int push_at_index(struct vector_int *p_vec_int,size_t index,int new_data)
{

   size_t i;

   if(index >= p_vec_int -> N)
   {
    puts("failed to allocate the memory ");
    exit(EXIT_FAILURE) ;
   }

   p_vec_int->arr = (int *) realloc(p_vec_int->arr,(p_vec_int->N +1)*sizeof(int));

   for(i=p_vec_int->N;i>index;i--)
       p_vec_int->arr[i] = p_vec_int->arr[i - 1];
    
    p_vec_int->arr[index] = new_data;
    return (SUCCESS);
}

void destroy_vector_int(struct vector_int * p_vec_int)
{
    free(p_vec_int->arr);
    free(p_vec_int);
    p_vec_int = NULL;
}

void show(struct vector_int *p_vec_int,const char *msg)
{
    size_t i;

    if(msg != NULL)
       puts(msg);

    for(i=0;i<p_vec_int->N;i++)
        printf("p_vec_int -> arr[%llu] : %d \n",i,p_vec_int->arr[i]);
}

int pop_back(struct vector_int *p_vec_int,int *p_back_data)
{
    if(p_vec_int->N == 0)
       return(VEC_EMPTY);
    
    *p_back_data = p_vec_int->arr [p_vec_int->N-1];
    p_vec_int -> arr = (int *) realloc(p_vec_int,sizeof(int)*(p_vec_int->N-1));
    p_vec_int -> N -= 1 ;
    return(SUCCESS);

}

int pop_front(struct vector_int *p_vec,int *p_front_data)
{
    size_t i;
    if(p_vec ->N == 0)
        return (VEC_EMPTY);
    
    *p_front_data = p_vec->arr[0];
    
    for(i=1;i<p_vec->N;i++)
      p_vec->arr[i-1] = p_vec->arr[i];
    
    p_vec->arr = (int *) realloc(p_vec,(p_vec->N)*sizeof(int));

    p_vec -> N-=1;
    
    return(SUCCESS); 
}

int pop_index(struct vector_int *p_vec,size_t index,int *p_data) 
{
    size_t i;
    
    if(p_vec -> N == 0)
        return(VEC_EMPTY);

    *p_data = p_vec->arr[index];
    for(i=index+1;i<p_vec->N;i++)
       p_vec->arr[i-1] = p_vec->arr[i];
    
    p_vec->arr = (int *) realloc(p_vec->arr,sizeof(int) *(p_vec -> N -1));
    
    p_vec->N-=1;

    return SUCCESS;
}

int get_index(struct vector_int *p_vec,size_t index,int *p_data)
{
    if(index >=p_vec -> N )
       {
        puts("invalid index ");
        return (VEC_INVALID_INDEX);
        }

        *p_data = p_vec->arr[index];
        return (SUCCESS);
}

int set_index (struct vector_int *p_vec,size_t index,int new_data)
{
    if(index >= p_vec -> N)
     return(VEC_INVALID_INDEX);

    p_vec->arr[index] = new_data ;
    
    return (SUCCESS);
     
}

size_t get_size(struct vector_int *p_vec)
{
    return (p_vec->N);
}