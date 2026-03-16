#include<stdio.h>

#define parent(i) ((i -1) / 2)
#define left_child(i) ((2 * i) + 1)
#define right_child(i) ((2 * i) + 2)

int main()
{
    int heap[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int heap_size = sizeof(heap) / sizeof(heap[0]);

    int index = 9;
    printf("Element at index %d is: %d\n", index, heap[index]);

    if (index > 0) {
        printf("Parent: index %d, value %d\n", parent(index), heap[parent(index)]);
    } else {
        printf("Index 0 is the root and has no parent.\n");
    }

    if (left_child(index) < heap_size) {
        printf("LEFT Child: index %d, value %d\n", left_child(index), heap[left_child(index)]);
    }
    
    if (right_child(index) < heap_size) {
        printf("RIGHT Child: index %d, value %d\n", right_child(index), heap[right_child(index)]);
    }
    return 0;
}