#include<stdio.h>
#include<stdlib.h>

int main()
{
    // ========================use of malloc
    // int n;
    // int *ptr;

    // printf("Enter the numberr of elements you want in array:");
    // scanf("%d", &n);

    // ptr = (int *)malloc(n * sizeof(int));

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter the value at %d index:",i);
    //     scanf("%d", &ptr[i]);
    // }
    
    // for (int i = 0; i < n; i++)
    // {
    //     printf("The value at %d index: %d\n",i,ptr[i]);
    // }

    // free(ptr);

    //======================== use of calloc
    int n;
    int *ptr;

    printf("Enter the numberr of elements you want in array:");
    scanf("%d", &n);

    ptr = (int *)calloc(n , sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value at %d index:",i);
        scanf("%d", &ptr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("The value at %d index: %d\n",i,ptr[i]);
    }

    // ========================use of realloc
    printf("Enter the new numberr of elements you want in array:");
    scanf("%d", &n);

    ptr = (int *)realloc(ptr, n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value at %d index:",i);
        scanf("%d", &ptr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("The value at %d index: %d\n",i,ptr[i]);
    }

    free(ptr);
    return 0;
}