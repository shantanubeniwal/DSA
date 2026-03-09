#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// int isFull(){
//     if ((front == 0 && rear == MAX-1) || (front == rear + 1))
//     {
//         return 1;
//     }else{
//         return 0;
//     }
// }

// AI generated
int isFull() {
    return (rear + 1) % MAX == front;
}
// This single line covers both conditions you wrote out! If rear is 4 and front is 0, (4+1)%5=0 (True).
// If rear is 2 and front is 3, (2+1)%5=3 (True).

int isEmpty(){
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int value){
    if (isFull())
    {
        printf("Queue Overflow cannot add %d\n", value);
    }else{
        if (front == -1) front = 0;  // for first element
        
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Added %d\n", value);
    }
}

void dequeue(){
    if (front == -1)
    {
        printf("Queue is Empty.\n");
    }else{
        printf("Dequeued element %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }else{
            front = (front + 1) % MAX;
        }
    }
}

void peek(){
    if (isEmpty())
    {
        printf("Queue is empty nothing to peek.\n");
    }else{
        printf("Top element is: %d\n", queue[front]);
    }
}

void display(){
    if (isEmpty())
    {
        printf("Queue is Empty.\n");
    }else{
        printf("--Queue--\n");
        int i = front;
        while (1)
        {
            printf("| %d |\n", queue[i]);
            if(i == rear)
                break;
            i = (i + 1) % MAX;
        }
        
    }
    
}

int main()
{
    printf("--Circular Queue--\n");
    enqueue(10);
    enqueue(20);
    enqueue(40);
    enqueue(60);
    enqueue(80);

    display();
    
    peek();
    dequeue();
    dequeue();
    dequeue();
    
    peek();
    display();
    
    enqueue(12);
    enqueue(14);
    enqueue(16);
    
    display();
    peek();

    return 0;
}