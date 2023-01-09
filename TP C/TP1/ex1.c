#include<stdio.h>
#include<stdlib.h>

void check_msb(int num)
{
    if((num>>(sizeof(int)*8-1)) &1==1)
        printf("MSB is set\n");
    else
        printf("MSb is unset\n");


}
