#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node * next;
    struct node * prev;
} ;

struct node * create_list();
void insert_start(struct node * p_head_node,int data) ;
void insert_end(struct node * p_head_node,int data) ;
void show_list(struct node * p_head_node,const char *msg);
int insert_after(struct node*p_head_node ,int e_data,int n_data);
int insert_before(struct node*p_head_node ,int e_data,int n_data);

int get_start(struct node * p_head_node,int *p_data) ;
int get_end(struct node * p_head_node,int *p_data) ;

int pop_start(struct node * p_head_node,int *p_data );
int main(void)
{
    struct node * my_list = NULL ;
    int status ;

    int * p_data = NULL ;

    my_list = create_list();

    insert_start(my_list,11);

    show_list(my_list,"after 11 insert");

    insert_end(my_list,22);

    show_list(my_list,"end 22 insert");

    status = insert_after(my_list,11,44);

    show_list(my_list,"end 44 insert");
    status = insert_before(my_list,44,33);

    show_list(my_list,"end 44 insert");
    status = insert_before(my_list,44,55);

    show_list(my_list,"end 44 insert");

    p_data = (int *) malloc(sizeof(int));

    status = get_start(my_list,p_data);
    printf("start is %d \n",*p_data);

    
    status = get_end(my_list,p_data);
    printf("end is %d \n",*p_data);

    status = pop_start(my_list,p_data);
    printf("end is %d \n",*p_data);
    show_list(my_list,"pop 1 element ");

     status = pop_end(my_list,p_data);
    printf("end is %d \n",*p_data);
    show_list(my_list,"pop end element ");
}

struct node* create_list()
{
    struct node * p_head_node = NULL;
    
    p_head_node = (struct node *) malloc(sizeof(struct node));
        if(p_head_node == NULL)
    {
        puts("failed we are  to allocate the mem ");
        exit(EXIT_FAILURE);
    }
    
    p_head_node-> data  = 0;
    p_head_node-> prev  = NULL ;
    p_head_node -> next = NULL ;

    return (p_head_node );
}

void insert_start(struct node * p_head_node,int n_data) 
{
    struct node * new_data = NULL ;
    
    new_data = (struct node *) malloc(sizeof(struct node));
        if(new_data == NULL)
    {
        puts("failed to allocate the mem ");
        exit(EXIT_FAILURE);
    }
    new_data -> data = n_data ;
    new_data -> next = NULL;
    new_data -> prev = NULL ;

    new_data -> next = p_head_node ->next ;
    new_data -> prev = p_head_node;

    if(p_head_node-> next != NULL)
        p_head_node -> next -> prev = new_data ;
    p_head_node -> next = new_data ;

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

void insert_end(struct node * p_head_node,int n_data)
{
    struct node *new_data = NULL ;
    struct node *p_run = NULL ;
    
    p_run = (struct node *)malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the mem ");
        exit(EXIT_FAILURE);
    }
    p_run = p_head_node  ;
    while(p_run ->next !=NULL)
    {
     p_run = p_run ->next ;
    }

    
    new_data = (struct node *) malloc(sizeof(struct node));
    if(new_data == NULL)
    {
        puts("failed to allocate the mem ");
        exit(EXIT_FAILURE);
    }
    new_data -> data = n_data ;
    new_data -> next = NULL ;
    new_data -> prev = NULL ;
       
    new_data -> prev = p_run ;
    p_run -> next = new_data ;
    
}

int insert_after(struct node*p_head_node ,int e_data,int n_data) 
{
    struct node * p_run = NULL ; 
    struct node * p_data = NULL ; 
    p_run  =  (struct node *) malloc(sizeof(struct node)) ;
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    
    p_run = p_head_node -> next ;
    while(p_run  != NULL)
    {
        if(p_run -> data == e_data)
            break;
        p_run = p_run -> next ;
    }

    if(p_run  == NULL)
       return (LIST_DATA_NOT_FOUND);
    
    
    p_data  =  (struct node *) malloc(sizeof(struct node)) ;
    if(p_data == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_data -> data =  n_data ;
    p_data -> next = NULL ;
    p_data -> prev = NULL ;

    p_data -> next = p_run -> next ;
    p_data -> prev = p_run  ; 

    if(p_run -> next -> prev != NULL)
        p_run->next -> prev = p_data;
    p_run -> next = p_data ;

    return SUCCESS;
}

int insert_before(struct node*p_head_node ,int e_data,int n_data)
{
    struct node * p_run = NULL ;
    struct node * p_data = NULL ;
    p_run = (struct node *) malloc(sizeof(struct node));
   
   if(p_run == NULL)
   {
    puts("failed to allocate the memory ");
    exit(EXIT_FAILURE);
   }

   p_run = p_head_node ->next  ;
   
   while(p_run != NULL)
   {
    if(p_run -> data == e_data )
       break;
    p_run = p_run -> next ;
   }
   
   if(p_run == NULL)
      return LIST_EMPTY ;
   
    
    p_data = (struct node *) malloc(sizeof(struct node));
   
   if(p_data == NULL)
   {
    puts("failed to allocate the memory ");
    exit(EXIT_FAILURE);
   }

   p_data -> data = n_data ;
   p_data -> next = NULL ;
   p_data -> prev = NULL;
   
   p_data -> next = p_run ;
   p_data -> prev = p_run -> prev ;

   p_run->prev -> next = p_data;
   p_run -> prev = p_data;

   return(SUCCESS);

}


int get_start(struct node * p_head_node,int *p_data) 
{
    if(p_head_node -> next == NULL && p_head_node -> prev == NULL)
    {
        return LIST_EMPTY ;
    }

    *p_data = p_head_node -> next ->data ;
    return SUCCESS ;
}
int get_end(struct node * p_head_node,int *p_data) 
{    
    struct node * p_run = NULL ;
    
    if(p_head_node ->next ==NULL && p_head_node -> prev == NULL)
        return LIST_EMPTY;
    p_run = (struct node *) malloc(sizeof(struct node)) ;
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    p_run = p_head_node ;
    while(p_run -> next != NULL)
       p_run = p_run->next ;

    *p_data = p_run -> data ;
    return SUCCESS;
}

int pop_start(struct node * p_head_node,int *p_data )
{

    struct node * p_run = NULL ;

    if(p_head_node -> next == NULL && p_head_node -> prev == NULL)
        return LIST_EMPTY;
    
    p_run = (struct node *) malloc(sizeof(struct node)) ;
    if(p_run == NULL)
       {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
       }

    *p_data = p_head_node -> next -> data ;
    p_run  = p_head_node -> next ;
    p_run->prev->next = p_run -> next ;
    if(p_run -> next != NULL)
        p_run -> next -> prev = p_run -> prev ;

    free(p_run);
    p_run =NULL;
    return SUCCESS;
}

int pop_end(struct node *p_head_node,int *p_data)
{
     struct node * p_run = NULL ;

    if(p_head_node -> next == NULL && p_head_node -> prev == NULL)
        return LIST_EMPTY;
    
    p_run = (struct node *) malloc(sizeof(struct node)) ;
    if(p_run == NULL)
       {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
       }

       p_run = p_head_node -> next ;

       while(p_run -> next != NULL)
          p_run = p_run -> next ;
        
      p_run -> prev -> next = NULL ;

      free(p_run);
      p_run =NULL;

      return SUCCESS;

}