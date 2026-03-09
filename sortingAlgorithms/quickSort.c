#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){
    int piviot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= piviot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}

void quickSort(int arr[],int start, int end){
    if (start < end)
    {
        int pi = partition(arr, start, end);

        quickSort(arr, start, pi - 1); // left array
        quickSort(arr, pi + 1, end);   // right array
    }
}

int main()
{
    int arr[] = {8, 6, 7, 3, 4, 2, 1, 9, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("\n--BEFORE SORTING--\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf(" %d ", arr[i]);
    }

    quickSort(arr, 0, arr_size - 1);

    printf("\n\n--AFTER SORTING--\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf(" %d ", arr[i]);
    }

    printf("\n\n");
    return 0;
}