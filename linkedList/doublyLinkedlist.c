#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    struct node *A = (struct node *)malloc(sizeof(struct node));
    struct node *B = (struct node *)malloc(sizeof(struct node));
    struct node *C = (struct node *)malloc(sizeof(struct node));

    A->data = 58;
    A->next = B;
    A->prev = NULL;

    B->data = 29;
    B->next = C;
    B->prev = A;

    C->data = 99;
    C->next = NULL;
    C->prev = B;

    printf("--Walking forward--\n");
    struct node *ptr = A;
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    
    printf("--Walking backward--\n");
    struct node *end = C;
    while (end != NULL)
    {
        printf("%d \n", end->data);
        end = end->prev;
    }
    

    // insertion of an element
    struct node *X = (struct node *)malloc(sizeof(struct node));
    X->data = 88;

    A->next = X;
    X->prev = A;
    X->next = B;
    B->prev = X;

    printf("--Walking forward--\n");
    ptr = A;
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    
    printf("--Walking backward--\n");
    end = C;
    while (end != NULL)
    {
        printf("%d \n", end->data);
        end = end->prev;
    }
    
    return 0;
}