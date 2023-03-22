#include<stdio.h>
#include<conio.h>

struct B
{
double x;
double y;

};

struct A
{
int num;
float f_arr[5];
struct B inB;
};

int main(void)
{
    struct  A inA;
    
    {
        /* data */
    };
    
    int i;

    inA.num = 100;
    for(i=0;i<5;i++)
    {
        inA.f_arr[i] = (100 + i)/3.0;
    }
   
   inA.inB.x = 300;
   inA.inB.y = 400;

   printf("num is %d  \n",inA.num);

  for(i=0;i<5;i++)
  printf("arr is f_arr[%d] = %f \n",i,inA.f_arr[i]);

  printf("in b x is %lf \n",inA.inB.x);
  printf("in b y is %lf \n ",inA.inB.y);  
}