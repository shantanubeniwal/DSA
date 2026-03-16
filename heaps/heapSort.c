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

    int size = arr_size;
    
    for (int i = arr_size - 1; i > 0; i--)
    {
        // put largest element in last of the array
        swap(&arr[0], &arr[i]);

        // reduce the size of the heap because the end part of array is sorted array but starting to index i it is a MAX HEAP
        size -= 1;

        // call MAX_HEAPIFY function for reduced size of heap
        MAX_HEAPIFY(arr, size, 0);
    }
}

int main()
{
    int heap[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int heap_size = sizeof(heap) / sizeof(heap[0]);

    heapSort(heap, heap_size);
    for (int i = 0; i < heap_size; i++)
    {
        printf("%d, ", heap[i]);
    }
    
    return 0;
}

// before sorting
// {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}

// after sorting
// {1, 2, 3, 4, 7, 8, 9, 10, 14, 16}