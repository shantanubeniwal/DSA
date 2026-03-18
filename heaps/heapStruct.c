#include<stdio.h>

#define MAX 100

#define PARENT(i) (i - 1) / 2
#define LEFT(i) (2 * i) + 1
#define RIGHT(i) (2 * i) + 2

typedef struct heap{
    int data[MAX];
    int size;
} MinHeap;

/*
Use of size vaiable in struct heap

Tracking the "Next Available" Slot: In a zero-indexed array, size always points to the index where the next element will be inserted.

Boundary Control: It tells the algorithms (like heapifyDown) exactly where the tree ends, preventing the code from accessing "garbage" values or memory outside the current heap.
*/

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* h, int index){
    int p = PARENT(index);
    if (index > 0 && h->data[index] < h->data[p])
    {
        swap(&h->data[index], &h->data[p]);
        minHeapify(h, p);
    }
}

void insert(MinHeap *h, int value){
    if (h->size == MAX)
    {
        printf("Heap Overflow\n");
        return;
    }
    h->data[h->size] = value;
    h->size++;
    minHeapify(h, h->size - 1);
}

// take out the min value of the min-heap
int extractMin(MinHeap* h){
    if (h->size == 0)
    {
        return -1;
    }
    return h->size - 1;
}

int main(){
    MinHeap h;
    h.size = 0;

    insert(&h, 15);
    insert(&h, 10);
    insert(&h, 20);
    insert(&h, 5);

    for (int i = 0; i < h.size; i++)
    {
        printf("%d, ", h.data[i]);
    }
    
    return 0;
}