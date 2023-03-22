#include <stdio.h> 
#include <stdlib.h> 

int f1(int, int); 
double f2(int, int, int); 
int f3(int); 

int g1(int); 
double g2(int); 
double g3(double); 

int main(void)
{
    int ret_1; 
    double ret_2; 

    ret_1 = f1(10, 20); 
    ret_2 = g1(100); 

    return (0); 
}

int f1(int m, int n)
{
    int result; 
    double rs; 
    result = m + n; 
    printf("result = %d\n", result); 
    rs = f2(1, 4, 8); 
    printf("rs = %lf\n", rs); 
    return (rs); 
}

double f2(int a, int b, int c)
{
    double mean; 
    int x; 
    mean = (a + b + c)/3; 
    x = f3(40); 
    printf("f2():mean = %lf, x = %d\n", mean, x); 

    return (mean); 
}

int f3(int n)
{
    return n * n; 
}

int g1(int a)
{
    double rs; 
    rs = g2(5); 
    printf("rs = %lf\n", rs); 
    return a * 10; 
    }

double g2(int n)
{
    double x; 
    x = g3(3.3); 
    printf("x = %lf\n", x); 
    return n /10; 
}

double g3(double x)
{
    printf("x = %d\n", x); 
    return x * 2.0; 
}