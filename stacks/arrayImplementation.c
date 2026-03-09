// #include<stdio.h>
// #include<stdlib.h>

// #define MAX 5

// struct stack {
//     int arr[MAX];
//     int top;
// };

// void initStack(struct stack* s){
//     s->top = -1;
// }

// int isFull(struct stack* s){
//     return s->top == MAX-1;
// }

// int isEmpty(struct stack* s){
//     return s->top == -1;
// }

// void push(struct stack* s, int value){
//     if (isFull(s))
//     {
//         printf("Stack Overflow! Cannot push %d\n", value);
//     }else{
//         s->top++;
//         s->arr[s->top] = value;
//         printf("Pushed %d\n", value);
//     }
// }

// int pop(struct stack* s){
//     if (isEmpty(s))
//     {
//         printf("Stack Underflow! No elements to pop.\n");
//         return -1;
//     }else{
//         int poppedValue = s->arr[s->top];
//         s->top--;
//         return poppedValue;
//     }
// }

// int peek(struct stack* s) {
//     if (isEmpty(s)) {
//         return -1;
//     }
//     return s->arr[s->top];
// }

// int main()
// {
//     struct stack myStack;
//     initStack(&myStack);

//     push(&myStack, 89);
//     push(&myStack, 58);
//     push(&myStack, 19);
//     push(&myStack, 23);
//     push(&myStack, 45);

//     printf("Top element is: %d\n", peek(&myStack));
//     printf("Popped element: %d\n", pop(&myStack));
//     printf("New top element: %d\n", peek(&myStack));

//     return 0;
// }


#include<stdio.h>

#define max 5

struct stack{
    int marks[max];
    int top;
};

void initStack(struct stack* s){
    s->top = -1;
}

int isFull(struct stack* s){
    return s->top == (max - 1) ? 1 : 0;
}

int isEmpty(struct stack* s){
    return s->top == -1 ? 1 : 0;
}

void push(struct stack* s, int value){
    if (isFull(s))
    {
        printf("stack overflow cannot push %d.\n",value);
    }else{
        s->top++;
        s->marks[s->top] = value;
        printf("pushed %d.\n", value);
    }
}

void pop(struct stack* s){
    if (isEmpty(s))
    {
        printf("cannot pop stack is underflow.\n");
    }else{
        s->top--;
        printf("poped %d\n", s->marks[s->top + 1]);
    }
}

int peek(struct stack *s){
    if (isEmpty(s))
    {
        return -1;
    }else{
        return s->marks[s->top];
    }
}

int main()
{
    struct stack class;
    initStack(&class);

    push(&class, 2);
    push(&class, 4);
    push(&class, 6);
    // push(&class, 8);

    // pop(&class);

    int top = peek(&class);
    if (top == -1)
    {
        printf("stack is Empty.\n");
    }else{
        printf("top element is: %d\n", top);
    }
    
    printf("\n--STACK--\n");
    for (int i = class.top; i >=0 ;i--){
        printf("%d \n",class.marks[i]);
    }

    return 0;
}