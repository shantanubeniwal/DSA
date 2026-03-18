#include <stdio.h>
#include <stdlib.h>

#define PARENT(i) (i - 1) / 2
#define LEFT(i) (2 * i) + 1
#define RIGHT(i) (2 * i) + 2

typedef struct 
{
    int* data;
    int size;
    int capacity;
} PriorityQueue;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(PriorityQueue *pq, int index) {
    if (index == 0) return;
    int p = PARENT(index);
    if (pq->data[index] < pq->data[p]) {
        swap(&pq->data[p], &pq->data[index]);
        heapify_up(pq, p);
    }
}

void heapify_down(PriorityQueue *pq, int index) {
    int l = LEFT(index);
    int r = RIGHT(index);
    int smallest = index;

    if (l < pq->size && pq->data[l] < pq->data[smallest])
        smallest = l;
    if (r < pq->size && pq->data[r] < pq->data[smallest])
        smallest = r;

    if (smallest != index) {
        swap(&pq->data[index], &pq->data[smallest]);
        heapify_down(pq, smallest);
    }
}

PriorityQueue* pq_create(int initCap) {
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->capacity = initCap;
    pq->data = malloc(initCap * sizeof(int));
    return pq;
}

void pq_push(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = realloc(pq->data, pq->capacity * sizeof(int));
    }
    pq->data[pq->size] = value;
    heapify_up(pq, pq->size);
    pq->size++;
}

int pq_pop(PriorityQueue *pq, int *outValue) {
    if (pq->size == 0) return 0; // Failure

    *outValue = pq->data[0]; // "Return" value via pointer
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    if (pq->size > 0) heapify_down(pq, 0);
    return 1; // Success
}

int pq_peek(PriorityQueue *pq) {
    return (pq->size > 0) ? pq->data[0] : -1;
}

int pq_is_empty(PriorityQueue *pq) {
    return pq->size == 0;
}

void pq_destroy(PriorityQueue *pq) {
    free(pq->data);
    free(pq);
}

int main() {
    PriorityQueue *emergencyRoom = pq_create(10);

    // Enqueue tasks (Lower number = Higher urgency in a Min-Heap)
    pq_push(emergencyRoom, 3); // Minor flu
    pq_push(emergencyRoom, 1); // Critical injury
    pq_push(emergencyRoom, 5); // Check-up
    pq_push(emergencyRoom, 2); // Broken arm

    printf("Processing Priority Queue:\n");
    
    int currentTask;
    while (!pq_is_empty(emergencyRoom)) {
        if (pq_pop(emergencyRoom, &currentTask)) {
            printf("Serving patient with priority level: %d\n", currentTask);
        }
    }

    pq_destroy(emergencyRoom);
    return 0;
}