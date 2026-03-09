#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int detectLoop(struct node* head){
    struct node *tortoise = head;
    struct node *hare = head;

    while (hare != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare)
        {
            return 1;
        }
        
    }
    
    return 0;
}

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
    E->next = NULL;
    
    if(detectLoop(A)){
        printf("--Loop Found--");
    }else{
        printf("--No Loop Found--");
    }

    return 0;
} 