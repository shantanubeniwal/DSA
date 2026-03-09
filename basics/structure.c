#include<stdio.h>
#include<string.h>

struct student
{
    char enrollmentNumber[20];
    char name[27];
    float cgpa;
} s1, s2;

int main()
{
    // structure example.
    strcpy(s1.enrollmentNumber, "2023BMEC058");
    strcpy(s2.enrollmentNumber, "2023BMEC150");
    // printf("%s\n", s1.enrollmentNumber);
    // printf("%s\n", s2.enrollmentNumber);
    
    strcpy(s1.name, "Shantanu Beniwal");
    strcpy(s2.name, "Imaginary Singh");
    // printf("%s\n", s1.name);
    // printf("%s\n", s2.name);

    s1.cgpa = 8.1;
    s2.cgpa = 9.64;
    // printf("%0.2f\n", s1.cgpa);
    // printf("%0.2f\n", s2.cgpa);

    printf("%s having enrollment number %s got %0.2f cgpa in 5th sem.\n", s1.name, s1.enrollmentNumber, s1.cgpa);
    printf("%s having enrollment number %s got %0.2f cgpa in 5th sem.\n", s2.name, s2.enrollmentNumber, s2.cgpa);
    return 0;
}



// #include <stdio.h>
// #include <string.h>

// // 1. Define the template (the Structure)
// struct Student {
//     char name[50];
//     int roll_number;
//     float marks;
// };

// int main() {
//     int n;

//     printf("How many students do you want to add? ");
//     scanf("%d", &n);

//     while (getchar() != '\n');

//     // 2. Create an array of structures based on user input
//     struct Student group[n]; 

//     // 3. Loop to "add" data to each structure variable
//     for(int i = 0; i < n; i++) {
//         printf("\nEntering details for Student %d\n", i + 1);
        
//         printf("Enter Name: ");
//         fgets(group[i].name, sizeof(group[i].name), stdin); // Reading string

//         group[i].name[strcspn(group[i].name, "\n")] = 0;

//         printf("Enter Roll Number: ");
//         scanf("%d", &group[i].roll_number);
        
//         printf("Enter Marks: ");
//         scanf("%f", &group[i].marks);
//     }

//     // 4. Displaying the added variables
//     printf("\n--- Displaying Student Records ---\n");
//     for(int i = 0; i < n; i++) {
//         printf("Student %d: %s (Roll: %d) - Marks: %.2f\n", 
//                 i + 1, group[i].name, group[i].roll_number, group[i].marks);
//     }

//     return 0;
// }