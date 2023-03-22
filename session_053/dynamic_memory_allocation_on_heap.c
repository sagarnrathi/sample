#include<stdio.h>
#include<stdlib.h>

void built_in_data_type(void);
void array_of_built_in_data_type(void);
void user_defined_data_type(void);

int main(void)
{
    built_in_data_type();
    array_of_built_in_data_type();
    user_defined_data_type();
    return(0);
}

void built_in_data_type(void)
{
    float *fp = 0 ;
    fp = (float *) malloc(sizeof(float));
    if(fp == 0)
    {
        puts("no allocated ");
        exit(0);
    }
    printf("please enter fraction val    ")
}