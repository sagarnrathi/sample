#include<stdio.h>
#include<stdlib.h>

void test_1(int  n);
void test_2(int *p);
void test_3(int *p);
int main(void)
{
    int m;
    int n;
    int k = 500;
    test_1(100);
    m = 200;
    test_1(m);
    
    printf("before call to test_2() %d \n",n);
    puts("-------------------");
    test_2(&n);
    printf("afer call to test_2()  %d \n", n);
    puts("-------------------");

    printf("before call to test_3() %d \n",k);
    puts("-------------------");
    test_3(&k);
    printf("afer call to test_3()  %d \n", k);
    puts("-------------------");

}
void test_1(int n)
{
    printf("received input from caller %d \n ",n);
    puts("-------------------");
}

void test_2(int *p)
{
    *p = 500;
}
void test_3(int *p)
{
    printf("just enter value if k %d \n" ,*p);

    *p =  *p * *p;
    
}