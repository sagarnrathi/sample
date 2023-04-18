#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node * next ;
} ;
int main(void)
{
    struct node * p_node = NULL ;
    
    p_node = (struct node *)malloc(sizeof(struct node));

    if(p_node == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }

    p_node -> data = 100;
    p_node -> next =NULL;

    p_node -> next = (struct node *) malloc(sizeof(struct node));
    if(p_node -> next == NULL)
    {
        puts("failed to allocate ");
        exit(EXIT_FAILURE);
    }
    p_node -> next -> data = 20 ;
    p_node ->next -> = NULL; 

}