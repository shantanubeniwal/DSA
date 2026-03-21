#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>

#define Table_Size 1024

// multiply shift method
// the Multiplication Method and the Multiply-Shift Method are mathematically the same thing, just implemented differently for the computer.
// best for - Power of 2 table sizes

int multiplyShiftHash(uint32_t key){
    // table size is 2 power 10 so r = 10
    const uint32_t KNUTH_A = 2654435769U;

    uint32_t product = key * KNUTH_A;

    // shift by w - r
    // w = 32 architecture
    // r is 2's power
    int slot = (int)(product >> (32 - 10));
    return slot;
}



int main(){

    printf("%d slot for %d key \n", multiplyShiftHash(678), 678);
    printf("%d slot for %d key \n", multiplyShiftHash(894), 894);
    printf("%d slot for %d key \n", multiplyShiftHash(3924), 3924);
    printf("%d slot for %d key \n", multiplyShiftHash(2819), 2819);
    return 0;
}