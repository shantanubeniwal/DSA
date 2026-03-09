#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if (rear == MAX - 1)
    {
        printf("Queue Overflow cannot add %d\n", value);
    }else{
        if (front == -1) front = 0;  // for first element
        
        rear += 1;
        queue[rear] = value;
        printf("Added %d\n", value);
    }
}

void dequeue(){
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty.\n");
    }else{
        printf("Dequeued element %d\n", queue[front]);
        front += 1;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void peek(){
    if (front == -1)
    {
        printf("Queue is empty nothing to peek.\n");
    }else{
        printf("Top element is: %d\n", queue[front]);
    }
}

void display(){
    if (front == -1)
    {
        printf("Queue is Empty.\n");
    }else{
        printf("--Queue--\n");
        for (int i = front; i <= rear; i++)
        {
            printf("| %d |\n", queue[i]);
        }
    }
    
}

int main()
{
    printf("--Queue Array Implementation--\n");
    enqueue(10);
    enqueue(20);
    enqueue(40);
    enqueue(60);
    enqueue(80);
    // enqueue(12);
    // enqueue(14);
    // enqueue(16);

    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();

    peek();

    display();
    return 0;
}