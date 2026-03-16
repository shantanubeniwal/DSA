// Max-Heap: The value of each node must be greater than or equal to the values of its children. The largest element is always at the root.

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
    int largest = i;

    if (l < heap_size && heap[l] > heap[largest])
    {
        largest = l;
    }
    
    if(r < heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        MAX_HEAPIFY(heap, heap_size, largest);
    }
}

int main()
{
    int heap[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int heap_size = sizeof(heap) / sizeof(heap[0]);

    MAX_HEAPIFY(heap, heap_size, 1);

    for (int i = 0; i < heap_size; i++)
    {
        printf("%d \n", heap[i]);
    }
    
    return 0;
}