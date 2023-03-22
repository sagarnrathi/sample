/*
@author  : sagar rathi
@date    : 30-nov-2022
@goal    : demonstrate  the if else statement 
*/

#include<stdio.h>
int main(void){

    int n1;
    printf("please enter the value ");
    scanf("%d",&n1);
    if(n1 %2 == 0){
        printf(" %d  is even nuber \n",n1);
    }
    else{
        printf(" %d  is odd nuber \n",n1);
    }
   exit(0)
}