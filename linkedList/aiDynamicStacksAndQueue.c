#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Pointers for Stack and Queue
struct Node* top = NULL;
struct Node *front = NULL, *rear = NULL;

// --- STACK FUNCTIONS ---
void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto Stack.\n", val);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d from Stack.\n", temp->data);
    top = top->next;
    free(temp);
}

// --- QUEUE FUNCTIONS ---
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into Queue.\n", val);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued %d from Queue.\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

// --- DISPLAY FUNCTION ---
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- DYNAMIC DATA STRUCTURES ---\n");
        printf("1. Push (Stack)\n2. Pop (Stack)\n3. Enqueue (Queue)\n4. Dequeue (Queue)\n5. Display All\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); push(val); break;
            case 2: pop(); break;
            case 3: printf("Enter value: "); scanf("%d", &val); enqueue(val); break;
            case 4: dequeue(); break;
            case 5: 
                printf("Stack: "); display(top);
                printf("Queue: "); display(front);
                break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}