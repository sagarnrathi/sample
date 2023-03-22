#include<stdio.h>
#include<stdlib.h>

void merge(int *p_arr,int p,int q,int r);

int main(void)
{
    int a[15] = {-1,8,99,87,10,20,30,5,15,17,25,35,-11,2,520};
    merge(a,4,6,11);
    return 0;
}

void merge(int *p_arr,int p,int q,int r)
{
    int n1,n2;
    int i;
    int *a1 = NULL;
    int *a2 = NULL;

    n1 = q-p+1;
    n2 = r-q;

    a1 = (int *) malloc(n1 * sizeof(int));
    //if(a1==NULL)
    
    a2 = (int *) malloc(n2  * sizeof(int));

    for(i=0;i<n1;i++)
    a1[i] = p_arr[p+i];

    for(i=0;i<n2;i++)
    a1[i] = p_arr[q+1+i];
    
    printf("this is a1 \n");
    for(i=0;i<n1;i++)
    {
        printf("a1[%d] : %d \n",i,a1[i]);
    }


}