/*
Open addressing is a method for handling collisions in hash tables. Unlike Chaining (where each slot in the table points to a linked list of elements), in open addressing, all elements are stored directly within the hash table itself.

When a collision occurs—the system searches for the next available "open" slot according to a specific sequence.

The process of finding an empty slot is called probing.

h(k, i) = (h′(k) + f(i)) mod m

Where:

    k is the key.

    i is the probe number (0,1,2,…,m−1).

    h′(k) is the primary hash function.

    f(i) is the collision resolution function.

    m is the size of the table.

Common Probing Techniques:
1. Linear Probing:
    This is the simplest form. If a collision occurs at index x, the algorithm checks x+1,x+2,x+3, and so on.
    Formula: f(i)=i

2. Quadratic Probing:
    Instead of looking at the next immediate slot, the interval between probes increases quadratically.
    Formula: f(i)=c1​ i + c2 ​i^2

3. Double Hashing:
    This is one of the best methods for open addressing. It uses a second hash function to determine the step size for the probe.
    Formula: f(i) = i⋅h2​(k)
*/

#include<stdio.h>
#include<stdlib.h>

#define Table_Size 10

typedef struct table
{
    int capacity;
    int *slots;
} HashTable;

void init_hash_table(HashTable* h){
    h->capacity = Table_Size;
    h->slots = (int *)malloc(Table_Size * sizeof(int));

    for (int i = 0; i < Table_Size; i++)
    {
        h->slots[i] = -1;
    }
    
}

int hash(HashTable* h, int key){
    return key % h->capacity;
}

void insert(HashTable* h, int key){
    int start_slot = hash(h, key);
    
    for (int i = 0; i < h->capacity; i++)
    {
        int current_slot = (start_slot + i) % h->capacity;

        if (h->slots[current_slot] == -1)
        {
            h->slots[current_slot] = key;
            printf("Inserted %d at slot %d (Probes: %d)\n", key, current_slot, i);
            return;
        }
    }
    printf("Error: Hash Table is full, could not insert %d\n", key);
}

int main()
{
    HashTable *myHash = (HashTable*)malloc(sizeof(HashTable));
    init_hash_table(myHash);

    insert(myHash, 1);
    insert(myHash, 3);
    insert(myHash, 5);
    insert(myHash, 23);
    insert(myHash, 33);

    insert(myHash, 9);  // Fills slot 9
    insert(myHash, 19); // Hashes to 9, should wrap around to slot 0
    return 0;
}