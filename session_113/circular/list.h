#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>

#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef int data_t ;
typedef int status_t;
typedef long long int len_t;
typedef struct node node_t;
typedef node_t list_t;

struct node {
    data_t data ;
    struct node * next ;
    struct node * prev;
};

list_t * create_list(void);

status_t insert_start(list_t *p_list,data_t new_data);
status_t insert_end(list_t *p_list,data_t new_data);
status_t insert_after(list_t *p_list,data_t e_data,data_t new_data);
status_t insert_before(list_t *p_list,data_t e_data,data_t new_data);

status_t get_start(list_t *p_list,data_t *p_start_data);
status_t get_end(list_t *p_list,data_t *p_end_data);
status_t pop_start(list_t *p_list,data_t *p_pop_start);
status_t pop_end(list_t *p_list,data_t *p_pop_end);

status_t remove_start(list_t * p_list);
status_t remove_end(list_t * p_list);
status_t remove_data(list_t *p_list,data_t r_data);

len_t get_lenght(const list_t *p_list);
status_t find(const list_t *p_list,data_t f_data);
status_t is_empty(const list_t *p_list);
void show(const list_t *p_list,const char *msg);
status_t destroy_list(list_t ** pp_list);

list_t * add(const list_t *p_list_1,const list_t * p_list_2);
status_t concat(list_t * p_list_1,list_t * p_list_2);
list_t *merge(list_t * p_list_1,list_t * p_list_2);
list_t * get_reversed_list(const list_t * p_list);
status_t reverse_list(list_t * p_list);

static void generic_insert(node_t * p_beg,node_t * p_mid,node_t * p_end);
static void generic_delete(node_t * delete_node);
static node_t * search_node(const list_t *p_list,data_t s_data);
static node_t * get_node(data_t new_data);
static void *xcalloc(size_t number_of_element,size_t size_per_element);
#endif