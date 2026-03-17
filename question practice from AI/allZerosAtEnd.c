/*
The Challenge: Given an array of random numbers, push all the zeros of a given array to the end of the array while maintaining the relative order of the non-zero elements.

Input: arr[] = {1, 2, 0, 4, 3, 0, 5, 0}

Output: arr[] = {1, 2, 4, 3, 5, 0, 0, 0}

Constraint: Try to do this in-place (without creating a second array) to optimize space complexity to O(1).
*/

// shift approach is O(n^2)
// #include<stdio.h>

// void shift(int arr[], int arr_size, int index){
//     for (int i = index; i < arr_size - 1; i++)
//     {
//         arr[i] = arr[i + 1];
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);

//     int s;
//     for (int i = 0; i < arr_size; i++)
//     {
//         if (arr[i] == 0)
//         {
//             shift(arr, arr_size, i);
//         }else
//         {
//             continue;
//         }
//     }

//     for (int i = 0; i < arr_size; i++)
//     {
//         printf("%d, ", arr[i]);
//     }
//     return 0;
// }

// O(n) approach
#include<stdio.h>

//  fill zero seprately
// void moveZerosToEnd(int arr[], int n){
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != 0)
//         {
//             arr[count] = arr[i];
//             count++;
//         }
//     }
    
//     while (count != n)
//     {
//         arr[count] = 0;
//         count++;
//     }
// }

// fill zero simultaneously
void moveZerosToEnd(int arr[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;
            
            count++;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    moveZerosToEnd(arr, arr_size);
    
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}