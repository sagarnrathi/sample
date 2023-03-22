#include<stdio.h>
#include<conio.h>

#define n 8 

void show_array_1(int (*p)[n],int lenght);
void show_array_2(int *p ,int lenght);

void populate_array( int* p, int length); 

int main(void){
    int A[8] = {100,200,300,400,500,600,700,800};
    int B[n];
    show_array_1(&A,n);
    puts("-------------------");
    show_array_2(A,n);
    puts("Show array B, before populate array \n"); 
    show_array_2(B, n); 
    populate_array(B, n); 
    puts("Show array B, after populate array \n"); 
    show_array_2(B, n); 
}

void show_array_1(int (*p)[n],int lenght){
int index ;
int element;
for(index = 0;index < lenght;index++)
   {
    printf("element at index %d = %d \n",index,(*p)[index]);
   }
}

void show_array_2(int *p,int lenght)
{
    int index = 0 ;
    for(;index<lenght;index++)
    printf("element at  %d = %d \n ",index,*(p + index));

}

void populate_array( int* p, int length)
{
    int index; 

    for(index=0; index < length; ++index)
        *(p+index) = (index + 1) * 1000; 
}