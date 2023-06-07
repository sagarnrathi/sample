struct Date {
    int Day ;
    int Month ;
    int year ;
} ;

struct A
{
    struct B {
        unsigned char arr[24];
    }inB ;
} inA;

unsigned char arr[12];

int main(void)
{
    void *p1, *p2 ;
    p1 = &inA.inB.arr[12] ;
    p2 = arr;

    ((struct Date *)p1) -> Day;
    ((struct Date *)p1) -> Month ;
    ((struct Date * )p1) -> year ;

    ((struct Date * )p2) -> Day ;
    ((struct Date * )p2) -> Month ;
    ((struct Date *)p2)  -> year ;
}