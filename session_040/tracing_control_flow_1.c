#include <stdio.h> 
#include <stdlib.h> 

void f1(void); 
void f2(void); 
void f3(void); 

int main(void)
{
    f1(); 
    f2(); 
    f3(); 
    return (0); 
}

void f1(void)
{
    puts("In f1()"); 
    f2(); 
}

void f2(void)
{
    f3(); 
    puts("In f2()"); 
}

void f3(void)
{
    puts("In f3()"); 
}