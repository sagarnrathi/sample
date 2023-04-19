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
void insert_start(struct node * p_head_node,int data);
void insert_end(struct node *p_head_node,int data);
void show_list(struct node * p_head_node,const char *msg);
void destroy_node(struct node *p_head_node);

int insert_after(struct node * p_head_node,int e_data,int data);
int insert_before(struct node * p_head_node,int e_data,int data);

int get_start(struct node *p_head_node ,int * p_data);
int get_end(struct node *p_head_node ,int * p_data);


int pop_start(struct node *p_head_node ,int * p_data);
int pop_end(struct node *p_head_node ,int * p_data);


int main(void)
{
    struct node * my_list = NULL ;
    int data ;
    int *p_data = NULL;
    p_data =(int *) malloc(sizeof(int));
    my_list = create_list();

    show_list(my_list,"empty_list");

    for(data = 5;data<=50;data+=10)
       insert_end(my_list,data);
    
    show_list(my_list,"after insert end");

    for(data = 5;data<55;data+=10)
          insert_start(my_list,data);
    
    show_list(my_list,"after insert start ") ;

    data = insert_after(my_list,5,1000);
    if(data == 1)
        printf("success fully inserted 1000");
    else
        printf("data not found");
    show_list(my_list,"after insert 1000 start ") ;

    data = insert_before(my_list,20,2000);
    if(data == 1)
        printf("success fully inserted 1000");
    else
        printf("data not found");
    show_list(my_list,"after insert 2000 start ") ;

    data = get_start(my_list,p_data);

    printf("data at first element is %d \n",*p_data);

     data = get_end(my_list,p_data);

    printf("data at last element is %d \n",*p_data);

    data = pop_start(my_list,p_data);
    printf("data at first  element is %d \n",*p_data);
    show_list(my_list,"after pop start ") ;
   
    
    data = pop_end(my_list,p_data);
    printf("data at last element is %d \n",*p_data);
    show_list(my_list,"after pop end ") ;
    
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

int insert_after(struct node * p_head_node,int e_data,int n_data)
{
    struct node * p_data = NULL ;
    struct node * p_in = NULL ;
    p_data = (struct node *) malloc(sizeof(struct node));
    if(p_data == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

      p_in = (struct node *) malloc(sizeof(struct node));
    if(p_in == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_in -> data = n_data;
    p_in->next = NULL ;

    p_data = p_head_node -> next ;
   
    while(p_data != NULL)
    {   
       
        if(p_data -> data == e_data)
        {
           
           break ;
        }
        p_data = p_data -> next ;
       
    }
    if(p_data == NULL)
       return DATA_NOT_FOUND ;
    
    p_in -> next = p_data -> next ;
    p_data -> next = p_in ;

    return SUCCESS ;

}

int insert_before(struct node * p_head_node,int e_data,int n_data)
{
    struct node * p_new_data = NULL ;
    struct node * p_e_data = NULL ;
    struct node * p_e_data_prev = NULL ;

    p_e_data = (struct node *) malloc(sizeof(struct node));
    
    if(p_e_data == NULL)
    {
        puts("failed to alocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_e_data_prev = (struct node *) malloc(sizeof(struct node));
    if(p_e_data_prev == NULL)
    {
        puts("failed to alocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_e_data = p_head_node -> next ;
    p_e_data_prev = p_head_node  ;
    
    while(p_e_data != NULL)
    {
      if(p_e_data ->data ==  e_data)
          break;
      p_e_data_prev  = p_e_data ;
      p_e_data = p_e_data -> next ;
    }
    if(p_e_data == NULL)
        return DATA_NOT_FOUND ;
    
    p_new_data = (struct node *) malloc(sizeof(struct node)) ;

    if(p_new_data == NULL)
       {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
       }
    
    p_new_data -> data = n_data ;
    p_new_data -> next = NULL ;

    p_new_data->next = p_e_data_prev -> next;
    p_e_data_prev -> next = p_new_data ;

    return SUCCESS; 
}


int get_start(struct node *p_head_node ,int * p_data)
{
    
    if(p_head_node -> next == NULL)
       return EMPTY_LIST ; 
    *p_data = p_head_node -> next->data;
    
    return SUCCESS;
}

int get_end(struct node *p_head_node,int *p_data)
{

    struct node * p_run = NULL ;
    struct node * p_prev = NULL ;

   
    if(p_head_node -> next == NULL )
       return EMPTY_LIST ;
    
    p_run  = (struct node *) malloc(sizeof(struct node));
    p_prev  = (struct node *) malloc(sizeof(struct node));
    p_run  = p_head_node -> next ;
    p_prev  = p_head_node  ;
  
    while(p_run != NULL )
        {  
             
             p_prev = p_run ; 
            p_run  = p_run -> next ;
        }

    
    *p_data = p_prev -> data ;
    return SUCCESS ;
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
        printf("%d",temp ->data);
       }
      printf("%d",temp ->data);
      temp -> next = p_run  -> next ;
      free(p_run);

    return (SUCCESS);
}