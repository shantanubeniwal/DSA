#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Table_Size 10

// core structue
typedef struct node
{
    char* key;
    int value;
    struct node *next;
} Node;

typedef struct table
{
    Node *buckets[Table_Size];
} Hash_Table;

// hash function

/*
Start: value = 0

Char 'C': value = (0 * 31) + 67 → 67

Char 'a': value = (67 * 31) + 97 → 2174

Char 't': value = (2174 * 31) + 116 → 67510
*/
unsigned int hash(char* key){
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for (; i < key_len; ++i)
    {
        value = (value * 37) + key[i];
    }
    
    return value % Table_Size;
}

// create a new node
Node* createNode(char* key, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// insert a key-value pair
void insert(Hash_Table *table, char *key, int value){
    unsigned int slot = hash(key);
    Node *newNode = createNode(key, value);

    // collison handle
    // insert the newNode in the begning of the hash table slot
    newNode->next = table->buckets[slot];
    table->buckets[slot] = newNode;
}

// search any value by key
int search(Hash_Table *table, char *key){
    unsigned int slot = hash(key);
    Node *temp = table->buckets[slot];

    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Not Found
}

// helper function to print the hash table
void print_table(Hash_Table* table){
    for (int i = 0; i < Table_Size; i++)
    {
        printf("slot %d: ", i);
        Node *temp = table->buckets[i];
        while (temp != NULL)
        {
            printf("[%s: %d] ->", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    
}

int main() {
    Hash_Table table = {0};

    // Fruits & Trees
    insert(&table, "Apple", 101);
    insert(&table, "Banana", 102);
    insert(&table, "Cherry", 103);
    insert(&table, "Date", 104);
    insert(&table, "Elder", 105);
    insert(&table, "Fig", 106);
    insert(&table, "Grape", 107);
    insert(&table, "Hazel", 108);
    insert(&table, "Indigo", 109);
    insert(&table, "Maple", 110);

    // Office Gear
    insert(&table, "Table", 201);
    insert(&table, "Chair", 202);
    insert(&table, "Desk", 203);
    insert(&table, "Lamp", 204);
    insert(&table, "Phone", 205);
    insert(&table, "Laptop", 206);
    insert(&table, "Mouse", 207);
    insert(&table, "Screen", 208);
    insert(&table, "Cable", 209);
    insert(&table, "Brick", 210);

    // Space Objects
    insert(&table, "Solar", 301);
    insert(&table, "Lunar", 302);
    insert(&table, "Stellar", 303);
    insert(&table, "Galaxy", 304);
    insert(&table, "Comet", 305);
    insert(&table, "Orbit", 306);
    insert(&table, "Planet", 307);
    insert(&table, "Meteor", 308);
    insert(&table, "Nebula", 309);
    insert(&table, "Quasar", 310);

    print_table(&table);
    
    printf("\n--- Running Search Tests ---\n");
    
    char* test_keys[5] = {"Apple", "Quasar", "Laptop", "Banana", "Zebra"};
    
    for (int i = 0; i < 5; i++) {
        int result = search(&table, test_keys[i]);
        if (result != -1) {
            printf("Key: '%s' found! Value: %d\n", test_keys[i], result);
        } else {
            printf("Key: '%s' not found in table.\n", test_keys[i]);
        }
    }
    return 0;
}