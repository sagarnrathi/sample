struct B {
double x;
double y;
};

struct  A
{
    int a;
    struct B *b;

};

int main(void)
{
    struct B inB;
    struct A inA;
    
    inA.b = &inB;

    struct A *Pa = &inA;

    (*(*Pa).b).x = 100;

    printf("valus is %lf \n",inB.x);
    printf("valus is %lf",Pa->b->x);
    

}
