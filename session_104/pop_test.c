#include<stdio.h>
#include<stdlib.h>



#define SUCCESS 1
#define LIST_DATA_NOT_FOUND 2
#define EMPTY_LIST 3 
struct node {
    int data ;
    struct node * next ;
};

struct node * create_list(void) ;
void show(struct node * p_head_node,const char *msg);
void destroy(struct node * p_head_node ) ;

void insert_start(struct node * p_head_node,int n_Data);
void insert_end(struct node *p_head_node,int n_data);

int insert_after(struct node* p_head_node ,int e_data,int n_data);
int insert_before(struct node * P_head_node,int e_data,int n_data);

int pop_end(struct node *p_head_node ,int * p_data);
int pop_start(struct node *p_head_node ,int * p_data);

struct node * create_list(void)
{
    struct node * p_head_node = NULL ;

    p_head_node = (struct node *) malloc(sizeof(struct node));

    if(p_head_node == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_head_node -> next = p_head_node ;
    p_head_node -> data = 0 ;

    return (p_head_node );

}

void show(struct node * p_head_node,const char * msg)
{
    
    struct node * p_run = NULL;
    p_run = (struct node *) malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the memory");
        exit(EXIT_FAILURE);
    }
    if(msg)
       puts(msg);

    p_run = p_head_node -> next;
    printf("[START] -> ");
    while(p_run != p_head_node)
        {
            printf(" %d -> ",p_run -> data);
            p_run = p_run -> next ;
        }
    puts("[END]");
    
}

void destroy(struct node * p_head_node )
{
    struct node * p_run = NULL ;
    struct node * p_next = NULL ;
    
    p_run =  (struct node * ) malloc(sizeof(struct node));
     if(p_run == NULL)
    {
        puts("failed to allocate the memory");
        exit(EXIT_FAILURE);
    }
    p_next =  (struct node * ) malloc(sizeof(struct node));
    if(p_next  == NULL)
    {
        puts("failed to allocate the memory");
        exit(EXIT_FAILURE);
    }

    p_run =  p_head_node -> next ; 
    while(p_run  != p_head_node)
    {
        p_next  = p_run -> next ;
        free(p_run);
        p_run = NULL ;
        p_run  = p_next   ;
    }
    
    free(p_head_node);
    p_head_node = NULL ;

}

void insert_start(struct node * p_head_node,int n_data)
{
    struct node * p_run = NULL ;
    p_run = (struct node *) malloc(sizeof(struct node ));
    
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_run -> data = n_data ;

   p_run -> next = p_head_node -> next ;
    p_head_node -> next = p_run ;
}

void insert_end(struct node *p_head_node,int n_data)
{
    struct node * p_data = NULL ;
    struct node * p_run =  NULL ;
    p_run =  (struct node *) malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_data = (struct node *) malloc(sizeof(struct node)) ;
    if(p_data == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    p_data -> data = n_data ;
    p_run = p_head_node -> next ;
    while(p_run -> next != p_head_node)
    {
        p_run = p_run -> next ;
    }
    p_data -> next = p_run -> next ;
    p_run -> next    = p_data ;

}

int insert_after(struct node* p_head_node ,int e_data,int n_data)
{
    struct node * p_run  = NULL ;
    p_run  = (struct node *) malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    struct node * p_data  = NULL ;
    
    p_data = 
    p_run = p_head_node -> next ;
    while(p_run != p_head_node)
    {
        if(p_run -> data = e_data)
           break;
        p_run = p_run -> next ;
    }

    if(p_run == p_head_node )
        return LIST_DATA_NOT_FOUND ;

    p_data  = (struct node *) malloc(sizeof(struct node));
    if(p_data == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    
    p_data -> data = n_data ;
    p_data -> next = p_run -> next ;
    p_run -> next = p_data ;

    return SUCCESS ;
}

int insert_before(struct node * p_head_node,int e_data,int n_data)
{
    struct node * p_run = NULL ;
    struct node * p_run_prev = NULL ;
    struct node * p_data = NULL ;
    
    p_run = (struct node *) malloc(sizeof(struct node)) ;
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

     p_run_prev = (struct node *) malloc(sizeof(struct node)) ;
    if(p_run_prev == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    
    p_run = p_head_node -> next ;

    while(p_run != p_head_node)
    {
        if(p_run -> data == e_data)
            break;
        p_run_prev = p_run ;
        p_run = p_run -> next ;
    }

    if(p_run == p_head_node)
        return LIST_DATA_NOT_FOUND ;
    
    p_data = (struct node *) malloc(sizeof(struct node)) ;
    if(p_data == NULL)
      {
        puts("failed to alocate the memory ");
        exit(EXIT_FAILURE);
      }
    p_data -> data = n_data ;

    p_data -> next = p_run_prev -> next  ;
    p_run_prev -> next = p_data ;

    return SUCCESS ;

}


int pop_end(struct node *p_head_node ,int * p_data)
{
    struct node * p_run = NULL ;
    struct node * temp = NULL ;

    p_run = (struct node *) malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the mem");
        exit(EXIT_FAILURE);
    }

    temp = (struct node *) malloc(sizeof(struct node));
    if(temp == NULL)
    {
        puts("failed to allocate the mem");
        exit(EXIT_FAILURE);
    }
    
    if(p_head_node -> next == p_head_node)
       return (EMPTY_LIST) ;
    
    p_run = p_head_node ->next  ;
    temp = p_head_node ;
    
    while(p_run -> next   != p_head_node)
       {
        temp = p_run;
        p_run = p_run -> next ;     
      
       }
       
      *p_data  = 55;
      temp -> next = p_run  -> next ;
      free(p_run);
    
    return (SUCCESS);
}

int pop_start(struct node *p_head_node ,int * p_data)
{
   struct node * p_first_node = NULL;

   if(p_head_node -> next == p_head_node)
       return EMPTY_LIST ;
    
     
    *p_data = p_head_node -> next -> data ;
    
    p_first_node = p_head_node -> next ;
    
    p_head_node -> next = p_first_node -> next ;
    
    free(p_first_node);
    
    p_first_node = NULL ;
   
    return(SUCCESS);
}


int main(void)
{
    struct node * my_list = NULL;
    int data ;
    int *p_data = NULL;
    p_data = (int *) malloc(sizeof(int));
    my_list = create_list();
    show(my_list,"before insert list ");
    
    insert_start( my_list,1001);
    show(my_list,"after insert list ");
    
    insert_end( my_list,2002);
    show(my_list,"after insert at end  list ");
    
    insert_after( my_list,1001,3003);
    show(my_list,"after insert at end  list ");

    insert_before( my_list,2002,4004);
    show(my_list,"after insert at end  list ");

    data = pop_end(my_list,p_data);
    printf("data at last element is %d \n",data);
    show(my_list,"after pop end ") ;
    
    data = pop_start(my_list,p_data);
    printf("data at first  element is %d \n",data);
    show(my_list,"after pop start ") ;
    
    destroy(my_list ) ;
    my_list = NULL ;    
    
    show(my_list,"after destroy  list ");
    return (0);
}

