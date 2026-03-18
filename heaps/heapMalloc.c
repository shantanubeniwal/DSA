/*
creating min-heap using dynamic memory allocation
*/

#include<stdio.h>
#include<stdlib.h>

// used to find the parent of the given index
#define PARENT(i) (i - 1)/2
#define LEFT(i) (2 * i) + 1
#define RIGHT(i) (2 * i) + 2

typedef struct
{
    int *data;
    int size;
    int capacity;
} DynamicHeap;

DynamicHeap* createHeap(int initialCapacity){
    DynamicHeap *heap = (DynamicHeap *)malloc(sizeof(DynamicHeap));
    if (!heap) return NULL; // Safety check

    heap->size = 0;
    heap->capacity = initialCapacity;
    heap->data = (int *)malloc(initialCapacity * sizeof(int));

    if (!heap->data) { // Safety check
        free(heap);
        return NULL;
    }

    return heap;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// this function maintain the min-heap property
void insert_fixup(DynamicHeap* h, int index){
    // Base case: if we are at the root, stop
    if (index == 0) return;

    int p = PARENT(index);
    if (h->data[p] > h->data[index])
    {
        // swap the index element with its parent
        swap(&h->data[index], &h->data[p]);
        insert_fixup(h, p);
    }
    
}

void insert(DynamicHeap* h, int value){
    if (h->size == h->capacity)
    {
        h->capacity *= 2;
        h->data = (int *)realloc(h->data, h->capacity * sizeof(int));
        printf("Heap expanded to capacity: %d\n", h->capacity);
    }
    h->data[h->size] = value;
    h->size++;
    insert_fixup(h, h->size -1);
}

void extract_fixup(DynamicHeap* h, int index){
    int l = LEFT(index);
    int r = RIGHT(index);
    int smallest = index;

    if (l < h->size && h->data[l] < h->data[smallest])
    {
        smallest = l;
    }

    if (r < h->size && h->data[r] < h->data[smallest])
    {
        smallest = r;
    }
    
    if (smallest != index)
    {
        swap(&h->data[index], &h->data[smallest]);
        extract_fixup(h, smallest);
    }
}

void extractMin(DynamicHeap* h){
    if (!h || h->size == 0) {
    printf("Error: Heap underflow\n");
        return;
    }

    int minVal = h->data[0];

    h->data[0] = h->data[h->size - 1];
    h->size--;

    if (h->size > 0) {
        extract_fixup(h, 0);
    }
    printf("%d is minimum value\n", minVal);
    return;
}

void freeHeap(DynamicHeap *h) {
    if (h) {
        free(h->data);
        free(h);
    }
}

int main()
{
    DynamicHeap* h = createHeap(5);

    insert(h, 78);
    insert(h, 5);
    insert(h, 8);
    insert(h, 178);
    insert(h, 768);
    insert(h, 784);  // This will trigger a resize
    insert(h, 9);

    printf("Min-Heap Array: ");
    for (int i = 0; i < h->size; i++)
    {
        printf("%d, ", h->data[i]);
    }

    printf("\n\n");

    extractMin(h);
    extractMin(h);

    freeHeap(h); // Clean up!
    return 0;
}