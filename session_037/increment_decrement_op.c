/*
@author : sagar rathi
@date : 06122022
@goal : demo of pre and post incre and decre
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){

    int num = 10 ;
    printf("original value %d \n",num);
    num =  num + 1 ;
    printf("after add value %d \n",num) ; 
    num  = num - 1; 
    printf("after sub value %d \n",num) ; 
    return(0);
}