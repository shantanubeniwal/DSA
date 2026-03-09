#include<stdio.h>

float average1(int arr[]){
    float sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum + arr[i];
    }
    return (sum/4);
}

float average2(int* ptr){
    float sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum + *(ptr + i);
    }
    return (sum/4);
}

int main()
{
    // int strength;
    // char choice;
    // printf("\n--Welcome--\n");
    // printf("Enter number of students in your class:");
    // scanf("%d", &strength);
    // int marks[strength];

    // for (int i = 0; i < strength; i++)
    // {
    //     printf("Enter marks of roll number %d: ", i+1);
    //     scanf("%d", &marks[i]);
    // }

    // printf("\n");

    
    // printf("Do you want to print marks of any student(y/n):");
    // scanf(" %c", &choice);
    
    // if (choice == 'y' || choice == 'Y')
    // {
    //     for (int i = 0; i < strength; i++)
    //     {
    //         printf("marks of roll number %d is : %d\n", i + 1, marks[i]);
    //     }
    // }

    // printf("\n--Thankyou makrs stored--\n");

    int arr[] = {40, 55, 62, 77};
    float avg1 = average1(arr);
    printf("%f is the average value of the array.\n", avg1);
    
    float avg2 = average2(arr);
    printf("%f is the average value of the array.\n", avg2);
    
    return 0;
}