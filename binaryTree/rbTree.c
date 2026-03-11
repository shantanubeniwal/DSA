#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define BLACK 1

struct node{
    int data;
    int color;
    struct node *left, *right, *parent;
};

struct redBlackTRee {
    struct node *root;
    struct node *NIL;
};

struct node* creatNode(struct redBlackTRee* tree, int value){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->color = RED;
    newNode->left = tree->NIL;
    newNode->right = tree->NIL;
    newNode->parent = NULL;

    return newNode;
}

void leftRotate(struct redBlackTRee* tree, struct node* x){
    struct node *y = x->right;
    x->right = y->left;
    if(y->left != tree->NIL){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == tree->NIL){
        tree->root = y;
    }else{
        if (x == x->parent->left){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(struct redBlackTRee* tree, struct node* x){
    struct node *y = x->left;
    x->left = y->right;
    if (y->right != tree->NIL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == tree->NIL){
        tree->root = y;
    }else{
        if(x == x->parent->left){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
    }
    y->right = x;
    x->parent = y;
}

void insertFixup(struct redBlackTRee* tree, struct node* newNode){
    struct node *U;
    while (newNode->parent->color == RED)
    {
        struct node *P = newNode->parent;
        struct node *G = P->parent;
        // case A: if P is left child of the G
        // case A-1: uncle is black
        // case A-2: uncle is red and in zigzag positon
        // case A-3: uncle is red and in straight line
        
        // case B: if P is rihgt child of the G
        // case B-1: uncle is black
        // case B-2: uncle is red and in zigzag positon
        // case B-3: uncle is red and in straight line
    }
    
}

void insert(struct redBlackTRee* tree, int value){
    struct node *newNode = creatNode(tree, value);
    struct node *x = tree->root;
    struct node *y;
    while (x != tree->NIL)
    {
        y = x;
        if (value < x->data){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    newNode->parent = y;
    if(y == tree->NIL){
        tree->root = newNode;
    }else if(value < y->data){
        y->left = newNode;
    }else{
        y->right = newNode;
    }

    insertFixup(tree, newNode);
}

int main()
{
    struct node* sential = (struct node *)malloc(sizeof(struct node));
    sential->color = BLACK;
    sential->data = 0;
    sential->left = NULL;
    sential->right = NULL;
    sential->parent = NULL;

    struct redBlackTRee* tree = (struct redBlackTRee *)malloc(sizeof(struct redBlackTRee));
    tree->NIL = sential;
    tree->root = tree->NIL;


    return 0;
}