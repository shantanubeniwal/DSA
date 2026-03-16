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

int main()
{
    // {16, 4, 10, 14, 7, 9, 3, 2, 8, 1}
    int heap[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int heap_size = sizeof(heap) / sizeof(heap[0]);

    // MAX_HEAPIFY(heap, heap_size, 1);

    Build_Max_Heap(heap, heap_size);
    for (int i = 0; i < heap_size; i++)
    {
        printf("%d \n", heap[i]);
    }
    
    return 0;
}