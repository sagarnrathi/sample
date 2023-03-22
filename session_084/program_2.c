#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define N_INPUT 15

void show_array(int *a,int N,const char *msg);
void get_subarray(int *a_input,int N_input,
                int **ppa_even,int *pN_even,
                int **ppa_odd,int *pN_odd,
                int **ppa_prime,int *pN_prime);
            
int main(void)
{
    int *a_even = NULL,*a_odd = NULL,*a_prime = NULL ;
    int N_even = 0, N_odd = 0, N_prime =0;
    int a_input[15] = {
                         -1,8,99,87,10,
                         10,30,5,15,17,
                         25,35,-11,2, 520};
    
    get_subarray(a_input,N_INPUT,
                 &a_even,&N_even,
                 &a_odd,&N_odd,
                 &a_prime,&N_prime);
    show_array(a_input,N_INPUT,"input arrray ");
    show_array(a_even,N_even,"even array");
    show_array(a_odd,N_odd,"odd array ");
    show_array(a_prime,N_prime,"prime array");
    
    free(a_even);
    a_even = NULL;

    free(a_odd);
    a_odd = NULL;

    free(a_prime);
    a_prime = NULL;

    return(EXIT_SUCCESS);

}