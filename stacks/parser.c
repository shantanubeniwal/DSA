#include <stdio.h>
#include <string.h>

#define MAX 100

// We use a char array for the stack since we are storing characters
char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[] = "SRINAGAR"; // Example string
    int length = strlen(str);

    printf("Original String: %s\n", str);

    // 1. PUSH: Putting the string into the stack
    for (int i = 0; i < length; i++) {
        push(str[i]);
    }

    

    printf("Reversed String: ");
    
    // 2. POP: Taking them out (they come out backwards!)
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}