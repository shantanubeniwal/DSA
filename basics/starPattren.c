#include<stdio.h>

void trianglePattern(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void reversedTriangularPattern(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int num;
    int choice;

    printf("which pattern do you want- Triangular Pattern(1) or Reversed Triangular Pattern(2):");
    scanf("%d", &choice);

    
    if (choice == 1){
        printf("Enter a number:");
        scanf("%d", &num);
        trianglePattern(num);
    }else if(choice == 2){
        printf("Enter a number:");
        scanf("%d", &num);
        reversedTriangularPattern(num);
    }else{
        printf("Wrong choice");
    }

    // call by refrence
    // int a = 7, b = 10;
    // printf("%d and %d\n", a, b);
    // swap(&a, &b);
    // printf("%d and %d", a, b);

    return 0;
}