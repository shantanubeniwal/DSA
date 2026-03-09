#include<stdio.h>

void insertionSort(int arr[], int size){
    // int i;
    // int j;
    // for ( i = 1; i < size; i++)
    // {
    //     int key = arr[i];
    //     for ( j = i - 1; j >= 0; j--)
    //     {
    //         if (arr[j] > key)
    //         {
    //             arr[j + 1] = arr[j];
    //         }else{
    //             break;
    //         }
    //     }
    //     arr[j+1] = key;
    // }
    
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key > arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

int main()
{
    int arr[] = {10, 5, 3, 7, 60, 5, 24};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("--before sort--\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ,", arr[i]);
    }
    printf("\n");

    insertionSort(arr, size);
    
    printf("--after sort--\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ,", arr[i]);
    }
    
    return 0;
}