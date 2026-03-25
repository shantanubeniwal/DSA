/*
If linear probing is a "step" and quadratic probing is a "jump," Double Hashing is a "teleport." 
It is widely considered the best open addressing technique because it virtually eliminates both primary and secondary clustering.

The distance between probes is determined by a second hash function.
This means even if two keys collide at the first index, they will likely have different "step sizes" and won't follow the same path.

h(k,i) = (h1​(k)+i⋅h2​(k)) mod m
where: 
    h1​(k): The primary hash function (e.g., kmodm). It decides the starting slot.
    h2​(k): The secondary hash function. It decides the step size.
    i: The probe number (0,1,2,…).

Two Golden Rules for h2​(k):
    Rule 1 It must never return 0. If the step size is 0, the probe stays in the same spot forever (infinite loop).
    Rule 2 It must search the whole table. To ensure every slot is reachable, h2​(k) and the table size m should be relatively prime (their only common divisor is 1). The easiest way to do this is to make m a prime number.

With Double Hashing:
    Key A might have a step size of 3. It checks: 5, 8, 11...
    Key B might have a step size of 7. It checks: 5, 12, 19...
*/


#include<stdio.h>
#include<stdlib.h>

#define tableSize 13
#define EMPTY -1

typedef struct 
{
    int capacity;
    int *slots;
} hashTable;

void initHashTable(hashTable* h){
    h->capacity = tableSize;
    h->slots = (int *)malloc(tableSize * sizeof(int));
    for (int i = 0; i < tableSize; i++)
    {
        h->slots[i] = EMPTY;
    }
}

// Primary Hash
int h1(hashTable* h, int key) {
    return abs(key) % h->capacity;
}

// Secondary Hash: Must be non-zero and relatively prime to Table_Size
int h2(int key) {
    // 7 is a prime smaller than 13
    return 7 - (abs(key) % 7);
}

void insert_double(hashTable* h, int key){
    int startSlot = h1(h, key);
    int stepSize = h2(key);

    for (int i = 0; i < h->capacity; i++)
    {
        int currentSlot = (startSlot + i * stepSize) % h->capacity;

        if (h->slots[currentSlot] == EMPTY)
        {
            h->slots[currentSlot] = key;
            printf("Inserted %d at slot %d (Step Size: %d)\n", key, currentSlot, stepSize);
            return;
        }
        
    }
    printf("Table Full!\n");
}

int main()
{
    hashTable *myHash = (hashTable *)malloc(sizeof(hashTable));
    initHashTable(myHash);

    insert_double(myHash, 5);  // h1: 5
    insert_double(myHash, 18); // h1: 5 (Collision!) -> h2 step kicks in
    insert_double(myHash, 31); // h1: 5 (Collision!) -> different h2 step

    return 0;
}