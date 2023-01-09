#include <stdio.h>

void arr(int n) 
{
    int array[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", array + i);

    printf("array: \n");
    printf("[ ");
    for (int i = 0; i < n-1; ++i)
        printf("%d , ", *(array + i));
    printf("%d ]\n",*(array + n-1));
    
}

int main()
{
    int n = 5;
    arr(n);
}
