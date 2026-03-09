#include<stdio.h>

void merge(int arr[], int start, int mid, int end){
    int i, j, k;

    int n1 = mid - start + 1, n2 = end - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[start + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end){
    if (start < end)
    {
        int mid = start + (end - start) / 2;
    
        mergeSort(arr, start, mid); // left array
        mergeSort(arr, mid + 1, end); // right array
    
        merge(arr, start, mid, end); // merge arrays
    }
}
int main()
{
    int arr[] = {23, 65, 12, 45, 10, 5, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("\n--BEFORE SORTING--\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf(" %d ", arr[i]);
    }

    mergeSort(arr, 0, arr_size - 1);

    printf("\n\n--AFTER SORTING--\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf(" %d ", arr[i]);
    }

    printf("\n\n");
    return 0;
}


// -----------------------------AI--------------------------------
// #include <stdio.h>
// #include <stdlib.h>

// // Function to merge two halves
// void merge(int arr[], int left, int mid, int right) {
//     int i, j, k;
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // Create temporary arrays
//     int L[n1], R[n2];

//     // Copy data to temporary arrays L[] and R[]
//     for (i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     // Merge the temporary arrays back into arr[left..right]
//     i = 0; // Initial index of first subarray
//     j = 0; // Initial index of second subarray
//     k = left; // Initial index of merged subarray
    
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy any remaining elements of L[]
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Copy any remaining elements of R[]
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// // Main function that implements Merge Sort
// void mergeSort(int arr[], int left, int right) {
//     if (left < right) {
//         // Same as (left+right)/2, but avoids overflow for large l and h
//         int mid = left + (right - left) / 2;

//         // Sort first and second halves
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         merge(arr, left, mid, right);
//     }
// }

// // Utility function to print the array
// void printArray(int A[], int size) {
//     for (int i = 0; i < size; i++)
//         printf("%d ", A[i]);
//     printf("\n");
// }

// int main() {
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);

//     printf("Given array is \n");
//     printArray(arr, arr_size);

//     mergeSort(arr, 0, arr_size - 1);

//     printf("\nSorted array is \n");
//     printArray(arr, arr_size);

//     return 0;
// }