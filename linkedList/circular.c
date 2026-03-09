#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *A = (struct node*)malloc(sizeof(struct node));
    struct node *B = (struct node*)malloc(sizeof(struct node));
    struct node *C = (struct node*)malloc(sizeof(struct node));
    struct node *D = (struct node*)malloc(sizeof(struct node));
    struct node *E = (struct node*)malloc(sizeof(struct node));

    A->data = 89;
    A->next = B;

    B->data = 68;
    B->next = C;

    C->data = 37;
    C->next = D;

    D->data = 27;
    D->next = E;

    E->data = 40;
    E->next = A;

    struct node *ptr = A;

    printf("--- Circular List ---\n");
    do{
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != A);

    int count = 0;
    do
    {
        count += 1;
        ptr = ptr->next;
    } while (ptr!=A);
    
    printf("Total nodes in circle: %d\n", count);

    struct node *current = A;
    struct node *nextNode;

    // 1. Break the circle to prevent infinite looping during free
    E->next = NULL; 
    
    // 2. Standard Singly Linked List deletion
    while (current != NULL) {
        nextNode = current->next; // Save the next address
        printf("Freeing node with data: %d\n", current->data);
        free(current);             // Delete the current node
        current = nextNode;        // Move to the saved address
    }
    
    A = B = C = D = E = NULL; // Good practice: wipe the pointers
    
    return 0;
} 