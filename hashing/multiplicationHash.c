#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>

#define Table_Size 13

// multiplication method
// the multiplication method works well with any table size.

// int multiplicationHash(int key){
//     // first multiply key k by a constant A knuth constant
//     float A = 0.6180339887;
//     int fractionalPart = (int)( (key * A) - (int)(key * A) );
//     return fractionalPart % Table_Size;
// }

int multiplicationHash(int key){
    // first multiply key k by a constant A knuth constant
    double A = 0.6180339887;
    double product = key * A;
    double fractionalPart = product - (long)product;
    int slot = (int)(Table_Size * fractionalPart);
    return slot;
}


int main(){

    printf("%d slot for %d key \n", multiplicationHash(678), 678);
    printf("%d slot for %d key \n", multiplicationHash(894), 894);
    printf("%d slot for %d key \n", multiplicationHash(3924), 3924);
    printf("%d slot for %d key \n", multiplicationHash(2819), 2819);
    return 0;
}