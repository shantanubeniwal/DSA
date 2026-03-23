#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>
#include<time.h>

#define PRIME 2147483647
#define TABLE_SIZE 100

typedef struct {
    uint32_t a;
    uint32_t b;
    int m; // Table size
} UniversalHash;

void init_universal_hash(UniversalHash *uh, int table_size) {
    srand(time(NULL));
    uh->m = table_size;
    
    // a must be in range [1, PRIME-1]
    uh->a = (rand() % (PRIME - 1)) + 1;
    
    // b must be in range [0, PRIME-1]
    uh->b = rand() % PRIME;
    
    printf("Randomly selected: a = %u, b = %u\n", uh->a, uh->b);
}

// Random hashing
// h(k) = ((ak +b)mod p) mod m
// m is number of slots in your table
// p is a large prime number
// It is random from the perspective of an attacker or the input data, but deterministic for the program while it's running.

// Run #1: The program picks a=3,b=7. All searches and inserts use these values.
// Run #2: The program restarts and picks a=19,b=2. Now all searches and inserts use these new values.

// Even if an attacker knows a set of keys that collide for a=3,b=7, those same keys likely won't collide when the program restarts and picks a=19,b=2.

// cryptographically secure random number generators (CSPRNGs)
// If you use a simple linear congruential generator (the standard rand() in C), an attacker who sees a few hashed outputs could indeed reverse-engineer the "seed" and predict your a and b values.
// To keep your hash table truly secure, you need to ensure the "randomness" is unpredictable.

int hash_key(UniversalHash *uh, uint32_t k) {
    // We use uint64_t for the intermediate product to prevent overflow before the first modulo PRIME operation.
    uint64_t intermediate = ((uint64_t)uh->a * k) + uh->b;
    return (int)((intermediate % PRIME) % uh->m);
}


int main()
{
    UniversalHash myHash;
    init_universal_hash(&myHash, TABLE_SIZE);
    
    uint32_t key = 12345;
    int index = hash_key(&myHash, key);
    
    printf("Key %u maps to slot: %d\n", key, index);
    
    return 0;
}