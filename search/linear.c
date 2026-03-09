#include<stdio.h>

int linearSearch(int arr[], int size, int target){
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 25, 30, 35, 60, 65, 78, 94, 61};
    int size = 10;
    int target = 20;

    int resultIndex = linearSearch(arr, size, target);

    if (resultIndex != -1) {
        printf("Found at %d index\n", resultIndex);
    } else {
        printf("No matching found\n");
    }

    return 0;
}