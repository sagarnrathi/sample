#include<stdio.h>
#include<conio.h>

int get_integer_val_1();
void get_integer_val_2(int * p_int);

int main(void)
{
    int number_1,number_2;
    number_1 = get_integer_val_1();
    get_integer_val_2(&number_2) ;
    
    printf("number_1 %d number_2 = %d  \n ",number_1,number_2);
    return(0);

}

int get_integer_val_1()
{
    int n = 500;
    return (n);
}

void get_integer_val_2(int * p_int)
{
    *p_int = 1000;
}