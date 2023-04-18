#include<stdio.h>
#include<stdlib.h>

struct vector_int
{
    int *arr;
    size_t N;
};

struct vector_int *create_vector_int(void) ;
void destroy_vector_int(struct vector_int * p_vec_int);
void push_back(struct vector_int *p_vec_arr,int data);

int main(void)
{
    struct vector_int * p_vec_1 = NULL;
    struct vector_int *p_vec_2 = NULL;

    p_vec_1 = create_vector_int();
    p_vec_2 = create_vector_int();

    destroy_vector_int(p_vec_1);
    p_vec_1 = NULL ;

    destroy_vector_int(p_vec_2);
    p_vec_2 = NULL;
}

struct vector_int * create_vector_int()
{
    struct vector_int *p_vec = NULL ;
    p_vec = (struct vector_int *) malloc(sizeof(struct vector_int)) ;

    if(p_vec == NULL)
    {
        puts("failed to allocate the memory ");
        exit(-1);
    }

    p_vec ->arr = NULL;
    p_vec -> N = 0;
}

void destroy_vector_int(struct vector_int * p_vec_int)
{
    free(p_vec_int->arr);
    free(p_vec_int);
}

struct vector_int * create_vector_int()
{
    struct vector_int *p_vec = NULL;
    p_vec = (struct vector_int *) malloc(sizeof(struct vector_int));
    if(p_vec == NULL)
    {
        puts("failed to allocate ");
        exit(-1);
    }
    p_vec->arr = NULL;
    p_vec-> = 0;
}

void destroy_vector_int(struct vector_int *p_vec_int)
{
free(p_vec_int -> arr);
free(p_vec_int);
}

struct vector_int * create_vector_int()
{
    struct vector_int *p_vec= NULL;
    p_vec = (struct vector_int *) malloc(sizeof(struct vector_int));
    if(p_vec == NULL)
    {
        puts("failed to allocate");
        exit(-1);
    }
    p_vec->arr= NULL;
    p_vec->N = 0;
}

void destroy_vector_int(struct vector_int *p_vec_int)
{
    free(p_vec_int-> arr);
    free(p_vec_int);
}

void push_back(struct vector_int *p_vec_arr,int data)
{
    p_vec_arr->arr = (int *) (struct vector_int * p_vec_a
}