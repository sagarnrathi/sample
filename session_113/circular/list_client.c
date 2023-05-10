#include "list.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

int main(void)
{

    list_t * p_list = NULL ;
    list_t * p_list_1 = NULL ;
    list_t * p_list_2 = NULL ;
    list_t * p_add_list = NULL ;
    list_t * p_merged_list = NULL;
    
    data_t data;
    p_list = create_list();
    show(p_list,"just before create list");
    
    for(data = 0; data < 10; data += 2)
        insert_end(p_list, data); 
    show(p_list, "After insert_end():"); 
     for(data = 1; data < 10; data += 2) 
          insert_start(p_list, data); 
    show(p_list, "After insert_start():"); 
    
    insert_after(p_list, 2, 100); 
    show(p_list, "After insert_after():"); 

    insert_before(p_list, 0, 200); 
    show(p_list, "After insert_before():"); 
    

    get_start(p_list, &data); 
    printf("Current start:%d\n", data); 

    get_end(p_list, &data); 
    printf("Current end:%d\n", data); 

    pop_start(p_list, &data); 
    printf("Removed Start:%d\n", data); 
    show(p_list, "after pop_start():"); 

    pop_end(p_list, &data); 
    printf("Removed End:%d\n", data); 
    show(p_list, "after pop_end():"); 

     remove_start(p_list); 
    show(p_list, "After remove_start():"); 

    remove_end(p_list); 
    show(p_list, "After remove_end():"); 

//    remove_data(p_list, 0); 
  //  show(p_list, "After remove_data():"); 

    
    p_list_1 = create_list(); 
    p_list_2 = create_list(); 

    for(data = 0; data <= 25; data = data + 5)
        insert_end(p_list_1, data); 

    for(data = 7; data <= 70; data += 7)
        insert_end(p_list_2, data); 

    show(p_list_1, "p_list_1:"); 
    show(p_list_2, "p_list_2:"); 
    
       p_add_list = add(p_list_1, p_list_2); 
    show(p_add_list, "added list:"); 

    p_merged_list = merge(p_list_1, p_list_2); 
    show(p_merged_list, "merged lists:"); 

    concat(p_list_1, p_list_2); 
    p_list_2 = NULL; 
    show(p_list_1, "After Concatenation:"); 
    
    destroy_list(&p_list_1); 
    destroy_list(&p_add_list); 
    destroy_list(&p_merged_list); 

    return (0); 
}