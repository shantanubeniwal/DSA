#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* top = NULL;

void push(int value){
    struct node *newNode = (struct node *)malloc(sizeof(struct node *));

    if(!newNode){
        printf("heap overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;

    top = newNode;
    printf("%d pushed to stack\n", value);
}

int pop(){
    if (top == NULL)
    {
        printf("stack is Empty.\n");
    }

    struct node *temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

void displayStack(){
    struct node *current = top;
    while (current != NULL)
    {
        printf("|  %d  |\n", current->data);
        current = current->next;
    }
    printf("| NULL |\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("poped value is %d\n",pop());
    displayStack();
    return 0;
}