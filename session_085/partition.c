#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 15

void show_array(int *a,int N, const char *msg);
int partition(int *a,int p,int r);

int main(void)
{
    int a[ARRAY_SIZE] = {
                            30,1,44,
                            75,11,2,85,88,17,20,25,
                            100,543,123,5
                        };
    int q,p=3,r=10;
    
    show_array(a,ARRAY_SIZE,"before partition () :");
    q = partition(a,p,r);
    show_array(a,ARRAY_SIZE,"after partition() :");
    printf("q = %d \n",q);

    return(EXIT_SUCCESS);

}

void show_array(int *a,int N,const char *msg)
{
    int k;

    if(msg)
    puts(msg);

    for(k=0;k<N;k++)
    printf("a[%d] = %d \n",k,a[k]);
}

int partition(int *a,int p,int r)
{
    int i ; 
    int j ; 
    int pivot ;
    int tmp;

    pivot = a[r];
    i = p-1;
    for(j=p;j<r;++j)
    {
     if(a[j] <= pivot)
        {
            i = i + 1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;

        }
    }
    
    tmp = a[r];
    a[r] = a[i+1];
    a[i+1] = tmp;
    return (i + 1);
}