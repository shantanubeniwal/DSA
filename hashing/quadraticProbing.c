/*
Linear probing is easy, but it has a major weakness: Primary Clustering. This happens when several keys hash to nearby slots, creating a long "block" of occupied spaces. Any new key that hashes into this block has to probe through the entire cluster, making the table very slow.

Quadratic Probing fixes this by increasing the gap between probes as you go.

Why this helps:

If you have a collision at index 5, you don't just check 6, 7, and 8. You check:

    (5+1^2)=6

    (5+2^2)=9

    (5+3^2)=14...

It's better to use a prime number (number of slots) for Quadratic Probing

If the table size is not a prime number, quadratic probing might actually skip over empty slots and fail to find them even if the table isn't full.

Rule of Thumb: Always keep your table size a prime number and try to keep it less than 50% full when using quadratic probing.

"jump" pattern (1,4,9,16…)
*/


#include<stdio.h>
#include<stdlib.h>

#define tableSize 11
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

int hash(hashTable* h, int key){
    return abs(key) % h->capacity;
}

void insert_quadratic(hashTable* h, int key){
    int startSlot = hash(h, key);

    for (int i = 0; i < h->capacity; i++)
    {
        int currentSlot = (startSlot + (i * i)) % h->capacity;

        if (h->slots[currentSlot] == EMPTY)
        {
            h->slots[currentSlot] = key;
            printf("Inserted %d at slot %d (Attempt %d)\n", key, currentSlot, i);
            return;
        }
    }
    printf("Table Full or failed to find a slot!\n");
}

int main()
{
    hashTable *myHash = (hashTable*)malloc(sizeof(hashTable));
    initHashTable(myHash);

    // These would normally cause a long cluster in linear probing
    insert_quadratic(myHash, 5); 
    insert_quadratic(myHash, 16); // 16 % 11 = 5 (Collision!)
    insert_quadratic(myHash, 27); // 27 % 11 = 5 (Collision!)
    return 0;
}