#include<stdio.h>
int main()
{
    // int a = 7;
    // int *ptra = &a;

    // printf("a = %d\n", a);
    // printf("a = %d\n", *ptra);

    // printf("address of a %d\n", &a);
    // printf("address of a %d\n", ptra);

    // int* ptr2;
    // printf("value inside ptr2 %p\n", ptr2);

    // int arr[] = {10, 20, 30};
    // printf("%d\n", arr[1]);
    // printf("%d\n", *(arr));
    // printf("%d\n", &arr[4]);

    int arr2[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int *ptr = arr2;

    for (int i = 0; i < 8; i++)
    {
        printf("value of inder [%d] by using array notation:%d\n", i, arr2[i]);
        printf("value of inder [%d] by using pointer notation:%d\n", i, *(ptr+i));
    }

    return 0;
}