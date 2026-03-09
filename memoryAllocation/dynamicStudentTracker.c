#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Dynamic Student Tracker
    int n;
    float sum = 0;

    // no of elements
    printf("how many students are present:");
    scanf("%d", &n);
    
    // memory allocation
    int *ptr;
    ptr = (int *)malloc(n * sizeof(int));

    // safety check
    if(ptr == NULL){
        printf("Memory allocation failed");
        return 1;
    }

    // enter the grade of each student
    for (int i = 0; i < n; i++)
    {
        printf("Enter the marks(out of 100) of student %d :", i + 1);
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }

    printf("%0.2f is the average marks of class.\n", (sum / n));

    // use of realloc for late students
    int m;
    printf("number of late arival students:");
    scanf("%d", &m);

    int *temp_ptr;
    temp_ptr = (int *)realloc(ptr, (n + m) * sizeof(int));

    // safety check
    if(temp_ptr == NULL){
        printf("Resizing failed");
        free(ptr);
        return 1;
    }

    ptr = temp_ptr;

    for (int i = n; i < (n+m); i++)
    {
        printf("Enter the marks of late student %d:", i+1);
        scanf("%d", &ptr[i]);

        sum += ptr[i];
    }

    printf("%0.2f is the new average marks of class.", (sum / (n + m)));

    free(ptr);
    return 0;
}