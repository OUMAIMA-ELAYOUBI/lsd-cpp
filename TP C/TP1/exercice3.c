#include<stdio.h>
#include<stdlib.h>
#include"tp0.h"

int main()
{
 int num;
 unsigned char byte ;
 printf("num=");
 scanf("%d",&num);
 chek_msb( num);
 printf("byte=");
 scanf("%hhu",&byte);
 printBits ( byte);

}
