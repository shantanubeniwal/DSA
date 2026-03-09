#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    int age;
    // Two different paths
    struct Student *nextById;
    struct Student *nextByAge;
};

int main() { 
    // 1. Allocate memory for 3 students
    struct Student *s1 = (struct Student*)malloc(sizeof(struct Student));
    struct Student *s2 = (struct Student*)malloc(sizeof(struct Student));
    struct Student *s3 = (struct Student*)malloc(sizeof(struct Student));

    // Data for Student 1
    s1->id = 301; s1->age = 20;
    
    // Data for Student 2
    s2->id = 101; s2->age = 25;
    
    // Data for Student 3
    s3->id = 201; s3->age = 18;

    // --- PATH 1: Link by ID (101 -> 201 -> 301) ---
    struct Student *headById = s2; // 101 is smallest ID
    s2->nextById = s3;             // 201 is next
    s3->nextById = s1;             // 301 is last
    s1->nextById = NULL;

    // --- PATH 2: Link by Age (18 -> 20 -> 25) ---
    struct Student *headByAge = s3; // 18 is youngest
    s3->nextByAge = s1;             // 20 is next
    s1->nextByAge = s2;             // 25 is oldest
    s2->nextByAge = NULL;

    // 2. Traverse by ID
    printf("--- Students Sorted by ID ---\n");
    struct Student *ptr = headById;
    while(ptr != NULL) {
        printf("ID: %d (Age: %d)\n", ptr->id, ptr->age);
        ptr = ptr->nextById;
    }

    // 3. Traverse by Age
    printf("\n--- Students Sorted by Age ---\n");
    ptr = headByAge;
    while(ptr != NULL) {
        printf("Age: %d (ID: %d)\n", ptr->age, ptr->id);
        ptr = ptr->nextByAge;
    }

    return 0;
}