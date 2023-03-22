#include<stdio.h>
#include<stdlib.h>

int cpa_add(int n1,int n2);
double compute_gravity(double m1,double m2,double r);

int main(void)
{
   int ret;
   double retd;
   int (*pfn1)(int,int);
   double (*pfn2)(double,double,double);
 
   pfn1 = cpa_add;
   pfn2 = compute_gravity;

   ret = pfn1(10,20);
   retd = pfn2(10.2,10.5,3.3);
   printf("ret = %d ,retd = %lf",ret,retd);
   return 0;
}
int cpa_add(int n1,int n2)
{
    puts("in cpa_add \n");
    return 0;
}

double compute_gravity(double m1,double m2,double r)
{
    puts("in compute \n");
    return 0;
}