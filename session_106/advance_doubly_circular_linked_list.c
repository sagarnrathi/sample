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
void insert_end(struct node *p_head_node,int n_data);

struct node * add(struct node * p_head_node_1,struct node * p_head_node_2);
void  concat(struct node * p_head_node_1,struct node * p_head_node_2);


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

struct node * add(struct node * p_head_node_1,struct node * p_head_node_2)
{
    struct node * result  = NULL;

    result = create_list();
    
     struct node * p_run  = NULL;

    p_run = (struct node * ) malloc(sizeof(struct node));
    if(p_run == NULL)
    {
        puts("failed to allocate the mem ") ;
        exit(EXIT_FAILURE);
    }

    for(p_run = p_head_node_1 -> next ;p_run != p_head_node_1;p_run = p_run ->next)
        insert_end(result,p_run -> data);

    for(p_run = p_head_node_2 -> next ;p_run != p_head_node_2;p_run = p_run ->next)
        insert_end(result,p_run -> data);
    
    return result ;


}

int main(void)
{
    struct node * my_list_1 = NULL;

    struct node * my_list_2 = NULL;

    struct node * result = NULL;

    int * p_data = NULL ;
    p_data = (int *) malloc(sizeof(int ));

    my_list_1 = create_list();
    

    insert_end(my_list_1,5000);

    my_list_2 = create_list();
    insert_end(my_list_2,6000);
    insert_end(my_list_1,4000);
    result = create_list();

    result = add(my_list_1,my_list_2);

    show(result,"result is ");

   concat(my_list_1,my_list_2);

    show(my_list_1,"concat  is ");
    show(my_list_2,"concat  is 2 2  ");
  

}

void  concat(struct node * p_head_node_1,struct node * p_head_node_2)
{
    struct node * p_run_1 = NULL ;
    p_run_1 =  (struct node *) malloc(sizeof(struct node ));
    if(p_run_1 == NULL)
    {
        puts("failed to allocate the mem ");
        exit(EXIT_FAILURE);
    
    }

    struct node * p_run_2 = NULL ;
    p_run_2 =  (struct node *) malloc(sizeof(struct node ));
    if(p_run_2 == NULL)
    {
        puts("failed to allocate the mem ");
        exit(EXIT_FAILURE);
    }

    p_run_1 = p_head_node_1 ;
    p_run_2 = p_head_node_2 ;

    while(p_run_1 -> next != p_head_node_1 )
        p_run_1 = p_run_1 -> next ;

    while(p_run_2 -> next != p_head_node_2 )
        p_run_2 = p_run_2 -> next ;
    
    if(p_run_2 != p_head_node_2)
    {
        p_run_1 -> next = p_head_node_2 ->next ;
        p_head_node_2 -> next ->prev = p_run_1 ;
        p_run_2 -> next = p_head_node_1 ; 
        p_head_node_1 -> prev = p_run_2;
    }
    free(p_head_node_2);
}
