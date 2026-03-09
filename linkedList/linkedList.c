#include<stdio.h>
#include<stdlib.h>

struct student
{
    int marks;  // 4 bytes
    struct student *next; // depends upon architecture- 32 bit = 4 bytes || 64 bit = 8 bytes
    // next = This is just the name of the variable. We call it "next" because it leads us to the next item in the chain.
};

int main() 
{
    struct student *happy = (struct student *)malloc(sizeof(struct student));
    happy->next = NULL;
    struct student *shantanu = (struct student *)malloc(sizeof(struct student));
    shantanu->next = NULL;

    happy->marks = 80;
    happy->next = shantanu;

    shantanu->marks = 90;

    // print the linked list
    struct student *ptr = happy;
    while (ptr != NULL)
    {
        printf("%d \n", ptr->marks);
        ptr = ptr->next;
    }

    free(happy);
    free(shantanu);

    return 0;
}
