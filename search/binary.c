#include<stdio.h>

int binarySearch(int arr[], int low, int high, int target){
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 200;

    int resultIndex = binarySearch(arr, 0, size-1, target);

    if(resultIndex == -1){
        printf("--no match found--");
    }else{
        printf("found at %d index.", resultIndex);
    }
    return 0;
}