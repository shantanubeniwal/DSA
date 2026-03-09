#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[50];
    float salary;
} Employee;

int main()
{
    // for single employee
    // Employee *emp = (Employee *)malloc(sizeof(Employee));

    // if(emp == NULL){
    //     printf("Memory allocation failed");
    //     return 1;
    // }

    // strcpy(emp->name, "Shantanu Beniwal");
    // emp->salary = 70000.50;

    // printf("Employee %s have %.2f salary per month.", emp->name, emp->salary);

    // free(emp);


    // for N employee
    int n;

    printf("Enter the nummber of employee:");
    scanf("%d", &n);

    Employee *list = (Employee *)malloc(n * sizeof(Employee));

    if(list == NULL){
        printf("Memory allocation failed...");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of %d employee:",i+1);
        scanf(" %[^\n]s", list[i].name);

        printf("Enter the salary of %d employee:",i+1);
        scanf("%f", &list[i].salary);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s have %.3f salary per month.\n", list[i].name, list[i].salary);
    }
    

    free(list);

    return 0;
}