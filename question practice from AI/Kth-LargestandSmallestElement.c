/*
The Challenge: Given an array and a number k, find the kth smallest and kth largest elements in the array.

Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 3

Output: 3rd smallest is 7, 3rd largest is 10.
*/

#include<stdio.h>

#define PARENT(i) ((i -1) / 2)
#define LEFT(i) ((2 * i) + 1)
#define RIGHT(i) ((2 * i) + 2)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void MAX_HEAPIFY(int heap[], int heap_size, int i){
    int l = LEFT(i);
    int r = RIGHT(i);
    
    // Assume the current node is the largest
    int largest = i;

    // Check if left child is larger than current largest
    if (l < heap_size && heap[l] > heap[largest])
    {
        largest = l;
    }
    
    // Check if right child is larger than current largest
    if (r < heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }

    // If the largest is not the parent, swap and recurse
    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        MAX_HEAPIFY(heap, heap_size, largest);
    }
}

void Build_Max_Heap(int arr[], int arr_size){
    int n = arr_size;
    for (int i = (n/2 - 1); i >= 0; i--)
    {
        MAX_HEAPIFY(arr, arr_size, i);
    }
}

void heapSort(int arr[], int arr_size){
    // create the MAX HEAP of the input array
    Build_Max_Heap(arr, arr_size);

    for (int i = arr_size - 1; i > 0; i--)
    {
        // put largest element in last of the array
        swap(&arr[0], &arr[i]);

        // call MAX_HEAPIFY function for reduced size of heap
        MAX_HEAPIFY(arr, i, 0);
    }
}

// find the kth smallest number 
int kth_smallest(int arr[], int k){
    return arr[k - 1];
}

// find the kth largest number
int kth_largest(int arr[], int arr_size, int k){
    return arr[arr_size - k];
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15}, k = 3;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // build_min_heap(arr, arr_size);
    heapSort(arr, arr_size);
    // for (int i = 0; i < arr_size; i++)
    // {
    //     printf("%d, ", arr[i]);
    // }

    printf("%d is %dth smallest number in given array.\n", kth_smallest(arr, k), k);
    printf("%d is %dth largest number in given array.\n", kth_largest(arr, arr_size, k), k);
    return 0;
}