#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

// void enequeue(int value){
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     if (!newNode)
//     {
//         printf("heap overflow\n");
//     }
//     newNode->data = value;
//     newNode->next = NULL;

//     rear = newNode;
//     if (rear == NULL)
//     {
//         front = rear = newNode;
//     }
//     rear->next = newNode;
//     rear = newNode;

//     printf("Added %d\n", value);
// }

void enqueue(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
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
    struct node* temp = front;
    printf("Dequeued %d from Queue.\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();
    dequeue();
    return 0;
}