#include <stdio.h>
#include <stdlib.h> // For exit(0)

#define MAX 5  // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function Prototypes
void push(int val);
void pop();
void peek();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter your choice: ");
        
        // Handling non-integer input to prevent infinite loops
        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number.\n");
            while(getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// --- FUNCTION DEFINITIONS ---

void push(int val) {
    if (top == MAX - 1) {
        printf("Error: Stack Overflow! Cannot push %d\n", val);
    } else {
        top++;                // Increment top index
        stack[top] = val;     // Store value at the new top
        printf("Success: Pushed %d\n", val);
    }
}

void pop() {
    if (top == -1) {
        printf("Error: Stack Underflow! Nothing to pop.\n");
    } else {
        printf("Success: Popped element %d\n", stack[top]);
        top--;                // Decrement top (Logical removal)
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("\nStack Status (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf(" ---- \n");
    }
}