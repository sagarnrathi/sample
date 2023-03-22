#include<stdio.h>
#include<stdlib.h>

void prn_frwd(int *a,size_t N, int K);
void prn_bkwd(int *a, size_t N,int K);
void prn_bkwd_alt(int *a,int K);

int main(void)
{
    int a[10] = {
        10,23,45,62,17,
        83,44,65,32,12
    };

    puts("forward printing of array a : ");
    prn_frwd(a,10,0);

    puts("backward printing of array a :");
    prn_bkwd(a,10,0);

    puts("backward printing of arry a alternative :");
    prn_bkwd_alt(a,9);
    
    return 0;
}


void prn_frwd(int *a,size_t N,int K)
{
    if(K == N)
       return ;
    printf("a[%d]  : %d  \n",K ,a[K]);
    prn_frwd(a, N,K+1);
}

void prn_bkwd(int *a,size_t N,int K)
{
    if(K==N)
       return ;
    prn_bkwd(a,N,K + 1);
    printf("a[%d]  : %d \n",K,a[K]);

}

void prn_bkwd_alt(int *a,int K)
{
    if(K<0)
       return ;
    printf("a[%d] : %d \n",K,a[K]);
    prn_bkwd_alt(a,K-1) ; 
}