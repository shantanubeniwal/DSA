#include<stdio.h>

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            int temp;
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// select the smallest and swap
void selectionSort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex!=i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        
    }
    
}

void insertionSort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; 
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

// for (int i = 0; i < 5; i++)
// {
// printf("%d, ", arr[i]);
// }
// printf("\n");

int main()
{
    int arr[] = {67, 45, 23, 98, 78};
    int n = 5;
    
    printf("before sorting:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    printf("\n");
    
    // bubbleSort(arr,n);
    
    // selectionSort(arr, n);

    insertionSort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}