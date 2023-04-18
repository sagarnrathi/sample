#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node * next;

};

int main(void)
{
    struct node n1,n2 ,n3;
    
    n1.data = 10;
    n1.next = &n2;

    n2.data = 20;
    n2.next = &n3 ;

    n3.data = 30;
    n3.next = NULL;

    return(0);

}