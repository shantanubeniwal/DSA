#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>

#define Table_Size 13

// division method
// works best when Table_Size is a prime number

int divideHash(char* key){
    int asciiValue = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        asciiValue += key[i];
    }
    int slot = asciiValue % Table_Size;
    return slot;
} 

/*
problems occured while this approach

1. The "Permutation" Problem
divideHash("abc") → 97+98+99=294

divideHash("cba") → 99+98+97=294

divideHash("bac") → 98+97+99=294

2. calling strlen repeadly making code slow
*/

// improved divideHash function for strings input
// int divideHash(char *key){
//     unsigned int hashValue;
//     int i = 0;
//     while (key[i] != '\0')
//     {
//         hashValue = (hashValue * 31) + key[i];
//         i++;
//     }
//     return hashValue % Table_Size;
// }

// improved divideHash function for strings input
// int divideHash(int key){
//     return key % Table_Size;
// }


int main(){
    printf("slot %d for happy\n", divideHash("happy"));
    printf("slot %d for rahul\n", divideHash("rahul"));
    printf("slot %d for ram\n", divideHash("ram"));
    return 0;
}