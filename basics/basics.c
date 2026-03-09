#include<stdio.h>

// #define pi 3.14
int main()
{
    // int a = 7;
    // int *ptra = &a;
    // printf("The value of 'a' using %%d is %d \n", a);
    // printf("The value of 'a' using pointer is %d \n", *ptra);

    // printf("Address of ponter is %x \n", &ptra);
    // printf("Address of 'a' using & is %x \n", &a);
    // printf("Address of 'a' is %x \n", ptra);


    // Question 1: Write a program to calculate the area and perimeter of a circle where the radius is taken as user input. Use a #define constant for the value of pi.
    // solution

    // float radius;
    // float area;
    // printf("Enter the radius :");
    // scanf("%f", &radius);
    // area = pi * radius * radius;
    // printf("Area of the circle : %f",area);

    // Question 2: Create a simple calculator using scanf that takes two numbers and an operator ($+$, $-$, $*$, $/$) and prints the result.
    // solution

    // float a, b, result;
    // char op;
    // char choice;
    // do
    // {
    //     printf("\n--- Simple Calculator ---\n");
    //     printf("Enter first number: ");
    //     scanf("%f", &a);
    //     printf("Enter operator (+, -, *, /): ");
    //     scanf(" %c", &op);
    //     printf("Enter second number: ");
    //     scanf("%f", &b);

    //     switch (op)
    //     {
    //     case '+':
    //         result = a + b;
    //         printf("Result: %.2f %c %.2f = %.2f \n", a, op, b, result);
    //         break;
    //     case '-':
    //         result = a - b;
    //         printf("Result: %.2f %c %.2f = %.2f \n", a, op, b, result);
    //         break;
    //     case '*':
    //         result = a * b;
    //         printf("Result: %.2f %c %.2f = %.2f \n", a, op, b, result);
    //         break;
    //     case '/':
    //         if(b != 0){
    //             result = a / b;
    //             printf("Result: %.2f %c %.2f = %.2f \n", a, op, b, result);
    //         }else{
    //             printf("dividing by 0 is not defined\n");
    //         }
    //         break;
        
    //     default:
    //         printf("wrong operator");
    //         break;
    //     }

    //     printf("Do you want to perform another calculation? (y/n): ");
    //     scanf(" %c", &choice);
    // } while (choice == 'y' || choice == 'Y');

    // printf("Exiting... Goodbye!");

    // int a;
    // printf("enter a number :");
    // scanf("%d", &a);

    // for (int i = 1;i <= 10;i++){
    //     printf("%d X %d = %d\n", a, i, a * i);
    // }

    // int age;
    // printf("enter your age: ");
    // scanf("%d", &age);
    // printf("you entered %d as your age.\n", age);
    // if (age>=18){
    //     printf("you can vote!!");
    // }else if(age>0 && age<18){
    //     if(age>0 && age <14){
    //         printf("Dont think about vote!");
    //     }else{
    //         printf("you cannot vote!!");
    //     }
    // }else{
    //     printf("Enter a valid age.");
    // }

    // int a = 7;
    // printf("\n--START--\n\n");
    // switch (a)
    // {
    // case 3:
    //     printf(" a = 3 ");
    //     break;
    // case 7:
    //     printf(" a = 7 ");
    //     break;
    // case 9:
    //     printf(" a = 9 ");
    //     break;
    // default:
    //     printf("no one case is matched");
    // }

    // // if(a == 3){
    // //     printf("a = 3 ");
    // // }else if ( a == 7 ){
    // //     printf("a = 7 ");
    // // }

    // printf("\n\n--END--\n");

    // int marks;
    // printf("\nEnter your marks: ");
    // scanf("%d", &marks);

    // if(marks>=40){
    //     printf("\nPASS with %d marks.\n\n", marks);
    // }else{
    //     printf("\nFAIL\n\n");
    // }

    // int category, choice;

    // printf("--- Beverage Machine ---\n");
    // printf("1. Coffee\n2. Tea\n");
    // printf("Select category (1-2): ");
    // scanf("%d", &category);

    // switch (category) {
    //     case 1: // Coffee Category
    //         printf("\n--- Coffee Menu ---\n");
    //         printf("1. Espresso\n2. Cappuccino\n");
    //         printf("Select your coffee (1-2): ");
    //         scanf("%d", &choice);

    //         switch (choice) {
    //             case 1:
    //                 printf("Dispensing a hot Espresso. Enjoy!\n");
    //                 break;
    //             case 2:
    //                 printf("Dispensing a frothy Cappuccino. Enjoy!\n");
    //                 break;
    //             default:
    //                 printf("Invalid coffee selection.\n");
    //         }
    //         break;

    //     case 2: // Tea Category
    //         printf("\n--- Tea Menu ---\n");
    //         printf("1. Green Tea\n2. Earl Grey\n");
    //         printf("Select your tea (1-2): ");
    //         scanf("%d", &choice);

    //         switch (choice) {
    //             case 1:
    //                 printf("Brewing Green Tea. Stay healthy!\n");
    //                 break;
    //             case 2:
    //                 printf("Brewing Earl Grey. Stay classy!\n");
    //                 break;
    //             default:
    //                 printf("Invalid tea selection.\n");
    //         }
    //         break;

    //     default:
    //         printf("Category not recognized. Please restart.\n");
    // }

    
    // LOOPS
    // do while loop

    // int i = 1; 
    // do{
    //     printf("%d\n",i);
    //     i += 1;
    // } while (i <= 10);

    // char choice = 'y';
    // do{
    //     printf("loop starts\n");
    //     printf("enter your choice:");
    //     scanf(" %c", &choice);
    // } while (choice == 'y' || choice == 'Y');


    // while loop

    // printf("hello world");

    // int num;
    // int j = 1;

    // printf("Enter a number: ");
    // fflush(stdout); // FORCE the prompt to show up instantly

    // if (scanf("%d", &num) != 1) return 1;

    // while(j <= num) {
    //     // Using a space instead of \n is 10x faster for the terminal to render
    //     printf("%d ", j); 
        
    //     // Every 10 numbers, we can print a newline to keep it readable
    //     if (j % 10 == 0) printf("\n");
        
    //     j += 1;
    // }

    // printf("\nDone!\n");

    // int i = 0;
    // while (i<50)
    // {
    //     printf("%d\n", i+1);
    //     i += 1;
    // }
    

    // for loop
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\n", i + 1);
    // }

    printf("hello world");
    return 0;
}