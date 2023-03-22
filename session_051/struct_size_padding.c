struct A
{
    int a ;
    char b;
    float c;
    char d;
};

struct B
{
    int a ;
    float b;
    char c,d;
};

struct C
{
    unsigned long long val;
    int num;
    char c1,c2;    /* data */
};

struct D
{
    char i;
   int  j;

    /* data */
};

int main(void)
{
    printf("sizeof(struct A is  = %llu \n",sizeof(struct A));
    printf("sizeof(struct B is ) = %llu \n ",sizeof(struct B));
    printf("sizeof(struct C is ) = %llu \n ",sizeof(struct C));
    printf("sizeof(struct D is ) = %llu \n ",sizeof(struct D));
    

}


