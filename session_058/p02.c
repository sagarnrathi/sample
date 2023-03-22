#include<stdio.h>
#include<stdlib.h>

int *get_array(int* pN);

int main(void)
{

 int *P = 0;
 int  N = -1;
 int i;

 P = get_array(&N);
 for(i=0;i<N;i++)
   *(P+i) = (i+1) * 100;
 for(i = 0;i<N;i++)
 printf("*(p +%d ) = %d \n",i,*(P+i));
 free(P);
 P = 0 ;
 exit(0);

}

int *get_array(int *pN)
{
int *p = 0;
int N;

printf("enter size if array : ");
scanf("%d",&N);
if(N<=0)
{
    puts("array size must be +ve ");
    exit(-1);
}

p = (int *) malloc(N * sizeof(int));
if(p==0)
{
    puts("error in allocating memory ");
    exit(-1);
}
*pN = N;
return (p);
}