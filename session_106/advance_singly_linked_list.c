#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 1
#define DATA_NOT_FOUND 2
#define EMPTY_LIST 3 
struct node
{
    int data ;
    struct node * next ;
} ;

struct node * create_list(void);

void insert_end(struct node *p_head_node,int data);
void show_list(struct node * p_head_node,const char *msg);
void destroy_node(struct node *p_head_node);

void concat(struct node * p_head_node_1,struct node * p_head_node_2);
struct node * add(struct node * p_head_node_1,struct node * p_head_node_2);
struct node * merge(struct node * p_head_node_1 ,struct node * p_head_node_2);
int main(void)
{
    struct node * my_list_1 = NULL ;
    my_list_1 = create_list();

    struct node * my_list_2 = NULL ;
    my_list_2 = create_list();
    insert_end(my_list_1,100);
    insert_end(my_list_2,200);
    struct node * result = NULL ;
    
    
    result = add(my_list_1,my_list_2);
    insert_end(my_list_2,300);
     insert_end(my_list_1,400);
    


    result = merge(my_list_1,my_list_2);
    
    show_list(result,"after merger");
    show_list(my_list_1,"1 ");
    show_list(my_list_2," 2 ");
    
    concat(my_list_1,my_list_2);
    show_list(my_list_1,"after concat");
    destroy_node(my_list_1);
    my_list_1 = NULL ;
      destroy_node(my_list_2);
    my_list_2 = NULL ;
      destroy_node(result);
    result = NULL ;

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

struct node * add(struct node * p_head_node_1,struct node * p_head_node_2)
{
    struct node * p_run = NULL ;
    p_run = (struct node *)malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    struct node * p_result = NULL ;
    p_result = (struct node *)malloc(sizeof(struct node));
    if(p_result == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_result = create_list();

    for(p_run = p_head_node_1 -> next ;p_run !=NULL;p_run = p_run -> next)
       insert_end(p_result,p_run -> data);
    
    for(p_run = p_head_node_2 -> next ;p_run !=NULL;p_run = p_run -> next)
       insert_end(p_result,p_run -> data);
    
    return p_result;
}

void concat(struct node * p_head_node_1,struct node * p_head_node_2)
{
    struct node * p_run = NULL ;
    p_run = (struct node *)malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    for(p_run = p_head_node_1 -> next ;p_run->next !=NULL;p_run = p_run -> next)
      
    ;
    p_run ->next = p_head_node_2 -> next ;

    free(p_head_node_2) ;

    p_head_node_2 = NULL;
    
}

struct node * merge(struct node * p_head_node_1 ,struct node * p_head_node_2)
{
    
    struct node * merge = NULL ;    
    merge = create_list();

    struct node * p_run_1 =  NULL;

    p_run_1 = (struct node *)malloc(sizeof(struct node));
    if(p_run_1 == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    struct node * p_run_2 =  NULL;
    p_run_2 = (struct node *)malloc(sizeof(struct node));
    if(p_run_2 == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    
    p_run_1 = p_head_node_1 -> next;
    p_run_2 = p_head_node_2  -> next;
   
   while(1)
   {
       if(p_run_1 == NULL)
       {
        
        while(p_run_2 != NULL)
        {
            insert_end(merge,p_run_2 -> data);
            p_run_2 = p_run_2 -> next ;
        }
        break ;
       }

       if(p_run_2 == NULL)
       {
        while(p_run_1 != NULL)
        {
            insert_end(merge,p_run_1 -> data);
            p_run_1 = p_run_1 -> next ;
        }
        break ;
       }

       if(p_run_1 -> data < p_run_2 -> data)
       {
        insert_end(merge,p_run_1 ->data);
        p_run_1 = p_run_1 -> next ;
       }
       else
       {
        insert_end(merge,p_run_2 -> data);
        p_run_2 = p_run_2 -> next;

       }

   }

   return merge;
}       