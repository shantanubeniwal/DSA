#include<stdio.h>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i) ((2 * i) + 1)
#define RIGTH(i) ((2 * i) + 2)

// swap numbers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// maintain the min-heap property
void min_heapify(int arr[], int arr_size, int index){
    // smallest number is index value
    int l = LEFT(index), r = RIGTH(index);
    int smallest = index;
    if (l < arr_size && arr[l] < arr[smallest])
    {
        smallest = l;
    }
    if (r < arr_size && arr[r] < arr[smallest])
    {
        smallest = r;
    }
    if (smallest != index)
    {
        // swap parent with smallest
        swap(&arr[index], &arr[smallest]);
        min_heapify(arr, arr_size, smallest);
    }
}

// make the min heap of any given array
void build_min_heap(int arr[], int arr_size){
    int n = arr_size;
    for (int i = (n/2) - 1; i >= 0; i--)
    {
        min_heapify(arr, arr_size, i);
    }
}

// heap sort
void heapSort(int arr[], int arr_size){
    build_min_heap(arr, arr_size);

    int heap_size = arr_size;
    
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15}, k = 3;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    build_min_heap(arr, arr_size);
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}