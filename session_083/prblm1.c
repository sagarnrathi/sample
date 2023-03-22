#include<stdio.h>
#include<stdlib.h>

void get_cloned_sub_arrays(int *a,int N,int **pp_a1,int *pn1,int **pp_a2,int *pn2);

void show_array(int *a,int N,const char *msg);

int main(void)
{
    int *a1=NULL,*a2=NULL;
    int N1 = 0 ,N2 = 0;

    int a[15] = {1,8,99,87,
                 10,20,30,
                 5 , 15,17 ,25,35,-11,2,530};

         
    get_cloned_sub_arrays(a,15,&a1,&N1,&a2,&N2);

    show_array(a1,N1,"array of even numbers ");
    
    show_array(a2,N2,"array of odd numbers ");

    free(a1);
    a1= NULL;

    free(a2);
    a2 = NULL;

    return(EXIT_SUCCESS);
}



void get_cloned_sub_arrays(int *a,int N,int **pp_a1,int *pn1,int **pp_a2,int *pn2)

{
    int *a1 = NULL, *a2 = NULL;
    int k,k1,k2;
    int n1=0,n2 = 0;
    for(k=0;k<N;k++)
    {
        if(a[k]%2==0)
          n1++;
        else 
           n2++;
    }
    a1 = (int * ) malloc(n1 * sizeof(int));
    if(a1 == NULL)
    {
        puts("failed to allocate the memory ");
        exit(EXIT_FAILURE);
    }
    a2 = (int *) malloc(n2 * sizeof(int));
    if(a2 == NULL)
    {
        puts("failed to allocate the memory");
        exit(EXIT_FAILURE);
    }
    k1 = 0;
    k2= 0 ;
    for(k=0;k<N;k++)
    {
    if(a[k]%2 ==0)
       {
         a1[k1] = a[k];
         k1++;
       }
    else 
      {
       a2[k2] = a[k];
       k2++;
       }

    }

    *pp_a1 = a1;
    *pn1 = n1;

    *pp_a2 = a2;
    *pn2 = n2; 
}

void show_array(int *a ,int N,const char *msg)
{
    int k;
    
    if(msg)
    puts(msg);

    for(k=0;k<N;k++)
    {
        printf("a[%d] : %d \n",k,a[k]);
    }
}