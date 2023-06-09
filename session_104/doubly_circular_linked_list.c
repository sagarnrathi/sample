#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define LIST_DATA_NOT_FOUND 2
struct node
{
    int data ;
    struct node * prev;
    struct node * next ;
};

struct node * create_list() ;
void show(struct node * p_head_node,const char *msg) ;

void insert_start(struct node * p_head_node,int n_data);
void insert_end(struct node *p_head_node,int n_data);

int insert_after(struct node *p_head_nnode,int e_data,int n_data);
int insert_before(struct node *p_head_nnode,int e_data,int n_data);

int pop_start(struct node *p_head_node,int *p_data);
int pop_end(struct node *p_head_node,int *p_data);

int remove_start(struct node *p_head_node);
int remove_end(struct node *p_head_node);
int remove_data(struct node * p_head_node,int e_data);


struct node * create_list()
{
    struct node * p_head_node = NULL ;
    p_head_node = (struct node *) malloc(sizeof(struct node));
    p_head_node -> data = 0;
    p_head_node -> next = p_head_node;
    p_head_node -> prev = p_head_node ;
    
    return (p_head_node) ;
}

void show(struct node * p_head_node,const char * msg)
{
    struct node * p_run = NULL ;
    p_run = (struct node *) malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    if(msg)
        puts(msg);
    p_run = p_head_node ->next ;
   
    printf("[START] ->");
    while(p_run != p_head_node)
        {
            printf("%d ->",p_run ->data);
            p_run = p_run -> next ;
        }
    puts("[END]");
}

void insert_start(struct node * p_head_node,int n_data)
{
    struct node * p_new_data = NULL ;
    p_new_data = (struct node *)malloc(sizeof(struct node));
    p_new_data -> data = n_data ;

    p_new_data -> next = p_head_node->next;
    p_new_data -> prev = p_head_node ;

    p_head_node -> next -> prev  = p_new_data ;
    p_head_node -> next   = p_new_data ;
    
 }

void insert_end(struct node *p_head_node,int n_data)
{
    struct node * p_new_data = NULL ;
    p_new_data = (struct node *)malloc(sizeof(struct node));
    if(p_new_data == NULL)
    {
        puts("failed to allocate the mem");
        exit(EXIT_FAILURE);
    }

    struct node * p_last = NULL ;
    p_last = (struct node *)malloc(sizeof(struct node));
    if(p_last == NULL)
    {
        puts("failed to allocate the mem");
        exit(EXIT_FAILURE);
    }
    
    p_last = p_head_node -> prev ;

    p_new_data -> data = n_data ;
    
    p_new_data -> prev = p_last  ;
    p_new_data -> next = p_head_node;
  
    p_last -> next = p_new_data ;
    p_head_node -> prev  = p_new_data;
    
}

int insert_after(struct node *p_head_node,int e_data,int n_data)
{
    struct node * p_run = NULL;
    struct node * p_new_data = NULL ;

    p_run = (struct node *)malloc(sizeof(struct node));
    
    p_run = p_head_node -> next;
    while(p_run != p_head_node)
    {
    if(p_run -> data == e_data);
        break ;
    p_run = p_run ->next ;
    }

    if(p_run == p_head_node)
        return LIST_DATA_NOT_FOUND ;
    
    p_new_data = (struct node *) malloc(sizeof(struct node));
    p_new_data -> data = n_data ;

    p_new_data -> next = p_run -> next;
    p_new_data -> prev = p_run ;
    p_run ->next->prev = p_new_data;
    p_run->next  = p_new_data;

    return (SUCCESS);

}

int insert_before(struct node *p_head_node,int e_data,int n_data)
{
    struct node * p_run = NULL ;
    struct node * p_data = NULL ;

    p_run = (struct node *) malloc(sizeof(struct node));

    p_run = p_head_node ->next ;
    
    while(p_run != p_head_node)
    {
        if(p_run -> data == e_data)
           break;
        p_run = p_run -> next;
    }
    
    if(p_run == p_head_node)
       return SUCCESS ;
    
    p_data = (struct node *) malloc(sizeof(struct node));
    p_data ->data = n_data ;
    p_data -> next = p_run  ;
    p_data -> prev = p_run-> prev ;

    p_run -> prev -> next = p_data ;
    p_run -> prev = p_data ;

    return SUCCESS ;
}

int pop_start(struct node *p_head_node,int *p_data_e)
{
 
     struct node * p_data = NULL ;
     p_data = (struct node *)malloc(sizeof(struct node));
     
     if(p_data == NULL )
     {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
     }

     *p_data_e = p_head_node-> next -> data ;

     p_data = p_head_node -> next ;

     p_data -> next -> prev = p_head_node ;
     p_head_node ->next = p_data -> next ;

     free(p_data);
     p_data = NULL;

     return SUCCESS ;

}

int pop_end(struct node *p_head_node,int *p_data_e)
{

   
     struct node * p_data = NULL ;
     p_data = (struct node *)malloc(sizeof(struct node));
     
     if(p_data == NULL )
     {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
     }

     *p_data_e = p_head_node-> prev -> data ;

     p_data = p_head_node -> prev ;

     p_data -> prev -> next = p_head_node ;
     p_head_node ->prev = p_data ->prev ;

     free(p_data);
     p_data = NULL;

     return SUCCESS ;

}

int remove_start(struct node *p_head_node)
{
    struct node * p_run = NULL ;

    p_run = (struct node *)malloc(sizeof(struct node));

    p_run = p_head_node ->next;

    p_run -> next -> prev = p_head_node ;
    p_head_node -> next = p_run -> next ;
    free(p_run);
    p_run = NULL ;

    return SUCCESS ;
}

int remove_end(struct node *p_head_node)
{
    struct node * p_run = NULL ;

    p_run = (struct node *)malloc(sizeof(struct node));

    p_run = p_head_node ->prev;
    printf("%d",p_run ->data);
    p_run -> prev -> next = p_head_node ;
    p_head_node -> prev = p_run -> prev ;
    free(p_run);
    p_run = NULL ;

    return SUCCESS ;

}

int remove_data(struct node * p_head_node,int e_data)
{
    struct node * p_run  = NULL ;
    p_run = (struct node *) malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the mem ") ;
        exit(EXIT_FAILURE);
    }

   
    p_run = p_head_node -> next ;
    while(p_run != p_head_node)
    {
        if(p_run -> data == e_data)
           break;
        p_run = p_run -> next ;
    }

    if(p_run == p_head_node)
    return LIST_DATA_NOT_FOUND ;

   p_run->prev -> next = p_run -> next ;
   p_run ->next ->prev = p_run -> prev ;
   free(p_run) ;
   p_run =NULL;
   return SUCCESS ;
}
int main(void)
{
    struct node * my_list = NULL;
    int * p_data = NULL ;
    p_data = (int *) malloc(sizeof(int ));

    my_list = create_list();
    show(my_list,"created");
   
   insert_start(my_list,1000);

    show(my_list,"inserted 1000");

     insert_end(my_list,5000);

    show(my_list,"inserted 5000");
    insert_after(my_list,1000,2000);

    show(my_list,"inserted 2000");

    insert_before(my_list,5000,9000);

    show(my_list,"inserted 9000");
    

    insert_before(my_list,5000,700);

    insert_before(my_list,5000,1700);
    insert_before(my_list,5000,1800);
    show(my_list,"inserted 700");
    
     pop_start(my_list,p_data) ;

     show(my_list,"pop first");

      
     pop_end(my_list,p_data) ;
     printf("poped data is %d \n",*p_data);
     show(my_list,"pop end");
    
     remove_start(my_list) ;
    
     show(my_list,"remove first");

       remove_end(my_list) ;
    
     show(my_list,"remove end");

   
    remove_data(my_list,700) ;
    
     show(my_list,"remove 700");

     


}