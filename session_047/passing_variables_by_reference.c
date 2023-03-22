#include<stdio.h>

void f1(char* p );
void f2(unsigned char* p);

void f3(short *p);
void f4(unsigned short *p);

void f5(int *p);
void f6(unsigned int *p);

void f7(long *p);
void f8(unsigned long *p);

void f9(long long *p);
void f10(unsigned long long *p);

void f11(float *p);
void f12(double *p);

int main()
{
    char c = 'A';
    unsigned char uc1 = 100;

    short sn = -200;
    unsigned short usn = 500;

    int n = -2345;
    unsigned int un = 5321;

    long lng_n = -34567;
    unsigned long u_lng_n = 5674;

    long long lng_lng_n = -9989898;
    unsigned long long u_lng_lng_n = 34543;

    float f = -9.098 ;
    double d1 = 9.0987;

    puts("before calls to function ");
    printf("c = %c, uc1 = %hhu , sn = %hd,usn = %hu, n= %d, un = %u , lng_n = %ld , u_lng_n = %lu \n ",
    c,uc1,sn,usn,n,un,lng_n,u_lng_n) ;
    printf("lng_lng_n = %lld ,u_lng_lng_n = %llu ,flt_1 = %f, d1 = %lf \n ",lng_lng_n,u_lng_lng_n,f,d1);
    f1(&c);
    f2(&uc1);
    f3(&sn);
    f4(&usn);
    f5(&n);
    f6(&un);
    f7(&lng_n);
    f8(&u_lng_n);
    f9(&lng_lng_n);
    f10(&u_lng_lng_n);
    f11(&f);
    f12(&d1);
    puts("after call to function ");
    printf("c = %c, uc1 = %hhu , sn = %hd,usn = %hu, n= %d, un = %u , lng_n = %ld , u_lng_n = %lu \n ",
    c,uc1,sn,usn,n,un,lng_n,u_lng_n) ;
    printf("lng_lng_n = %lld ,u_lng_lng_n = %llu ,flt_1 = %f, d1 = %lf \n ",lng_lng_n,u_lng_lng_n,f,d1);
    return(0);
}

void f1(char *p){
    *p = 'x' ;
}


void f2(unsigned char *p){
    *p = '444' ;
}


void f3(short *p){
    *p = 4444 ;
}


void f4(unsigned short  *p){
    *p = 44444 ;
}


void f5(int  *p){
    *p = 44444 ;
}


void f6(unsigned int  *p){
    *p = 4444 ;
}


void f7(long  *p){
    *p = -999999 ;
}


void f8(unsigned long *p){
    *p = 99999 ;
}


void f9(long long  *p){
    *p = -1010101 ;
}


void f10(unsigned long long  *p){
    *p = 1010101 ;
}


void f11(float *p){
    *p = 3.33333 ;
}


void f12(double  *p){
    *p = 5.6666 ;
}

