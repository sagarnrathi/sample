#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node * next ;
} ;

struct node * create_list(void ) ;
void insert_start(struct node* p_head_node,int data);
void insert_end(struct node*p_head_node,int data);
void show_list(struct node * p_head_node,const char* msg);
void destroy_list(struct node * p_head_node);

int main(void)
{
    int data ;
   struct node * p_head_node = NULL ;

   p_head_node = create_list();
   
   show_list(p_head_node,"empty List ");
   
    for(data = 5; data <= 25; data += 5)
        insert_start(p_head_node, data);
    
   show_list(p_head_node,"after insert start") ;

    for(data = 5; data <= 25; data += 5)
        insert_end(p_head_node, data);
    
   show_list(p_head_node,"after insert end  ") ;
   destroy_list(p_head_node);
   p_head_node = NULL;
}

struct node * create_list(void)
{
   
   struct node * p_node = NULL ;

   p_node = (struct node *) malloc(sizeof(struct node));
   if(p_node == NULL)
   {
    puts("failed to allocate the memory ");
    exit(EXIT_FAILURE);
   }

   p_node -> data = 0;
   p_node -> next = NULL ;

   return (p_node) ;  
}

void show_list(struct node * p_head_node,const char *msg)
{
    struct node * p_run = NULL ;

    p_run = p_head_node -> next ;


    if(msg)
        puts(msg);
    printf(" [START] ->");
    while(p_run != NULL)
    {
      printf("%d ->",p_run->data) ;
      p_run = p_run->next ;
    }
    puts("[END]");
}

void destroy_list(struct node * p_head_node)
{
    struct node * p_run = NULL ;
    struct node * p_run_next = NULL;

    p_run = p_head_node ->next ;

    while(p_run != NULL)
    {
        p_run_next = p_run ;
        free(p_run);
        p_run  = p_run_next ;
    }
    free(p_head_node);
}

void insert_start(struct node* p_head_node,int data)
{
    struct node * p_data = NULL ;
    p_data = (struct node *) malloc(sizeof(struct node));
    if(p_data == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_data -> data = data ;
    p_data -> next = p_head_node -> next ;
    p_head_node -> next = p_data ; 
}


void insert_end(struct node *p_head_node,int data)
{

    struct node *p_data = NULL ;
    struct node *p_run  = NULL ;
    p_data = (struct node *) malloc(sizeof(struct node));
    
    if(p_data == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_run  =  (struct node *) malloc(sizeof(struct node));
    
    if(p_run == NULL)
    {
        puts("failed to allocate the memory");
        exit(EXIT_FAILURE);
    }
    
    p_data -> data = data ;
    p_data -> next = NULL;
    p_run = p_head_node ;
    while(p_run -> next != NULL)
    {
        p_run = p_run -> next ;
    }
    p_run -> next = p_data ;

}