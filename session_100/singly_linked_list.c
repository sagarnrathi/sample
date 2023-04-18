#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node * next ;
} ;

struct node * create_list(void);
void insert_start(struct node * p_head_node,int data);
void insert_end(struct node *p_head_node,int data);
void show_list(struct node * p_head_node,const char *msg);
void destroy_node(struct node *p_head_node);

int main(void)
{
    struct node * my_list = NULL ;
    int data ;

    my_list = create_list();

    show_list(my_list,"empty_list");

    for(data = 5;data<=50;data+=5)
       insert_end(my_list,data);
    
    show_list(my_list,"after insert end");

    for(data = 5;data<55;data+=5)
          insert_start(my_list,data);
    
    show_list(my_list,"after insert start ") ;

    destroy_node(my_list);
    my_list = NULL ;

    exit(EXIT_SUCCESS);
}


struct node * create_list(void)
{
    
    struct node *p_head_node = NULL ;
    
    p_head_node = (struct node *) malloc(sizeof(struct node));

    if(p_head_node == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    
    p_head_node -> data = 0;
    p_head_node -> next = NULL ;

    return p_head_node;
}



void insert_start(struct node * p_head_node,int data)
{
    struct node * p_run = NULL ;

    p_run = (struct node *) malloc(sizeof(struct node));
    
    
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    
    p_run -> data = data;
    p_run -> next = NULL ;
    p_run ->next =  p_head_node -> next;
    p_head_node -> next = p_run ;
    

}
void insert_end(struct node *p_head_node,int data)
{
    struct node * p_new_node  = NULL ;
    struct node * p_run = NULL ;
    
    p_new_node = (struct node *) malloc(sizeof(struct node));
    
    if(p_new_node == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_new_node -> data = data;
    p_new_node -> next = NULL; 
    
    p_run = p_head_node  ;
    while(p_run -> next  != NULL)
    {
        p_run = p_run -> next ;
    }
    p_run -> next = p_new_node ;

}


void show_list(struct node * p_head_node,const char *msg)
{
    struct node * p_run  = NULL ;
    
    if(msg)
       puts(msg);
    
    printf("[start] ->") ;
    p_run = p_head_node ->next;

    while(p_run  != NULL )
    {
        printf("[%d]-> ",p_run -> data);
        p_run = p_run -> next ;
    }
    puts("[end]") ;

}
void destroy_node(struct node *p_head_node)
{
    struct node * p_run = NULL;
    struct node * p_run_next = NULL;
    
    p_run = p_head_node -> next ;
    while(p_run -> next == NULL)
    {
        p_run_next -> next = p_run -> next;
        free(p_run);
        p_run = p_run -> next ;
    }
    free(p_head_node) ;
}