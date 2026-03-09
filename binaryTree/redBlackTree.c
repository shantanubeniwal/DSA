#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define BLACK 1

struct node{
    int data;
    int color;
    struct node *left, *right, *parent;
};

struct RedBlackTree {
    struct Node* root;
    struct Node* NIL; // Pointer to the shared sentinel
};

struct node* createNode(struct RedBlackTree* tree, int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = tree->NIL;
    newNode->right = tree->NIL;
    newNode->color = RED;

    return newNode;
}

void leftRotate(struct RedBlackTree tree, struct node* x){
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != tree.NIL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == tree.NIL)
    {
        tree.root = y;
    }else if (x == x->parent->left)
    {
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

void rightRotate(struct RedBlackTree tree, struct node* x){
    struct node *y = x->left;
    x->left = y->right;

    if (y->right != tree.NIL)
    {
        y->right->parent = x;
    }
    
    if (x->parent == tree.NIL)
    {
        tree.root = y;
    }else if (x == x->parent->left)
    {
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

void insertFixup(struct RedBlackTree* tree, struct node* z){
    while (z->parent->color == RED)
    {
        
    }
    
}

// Insert a node into the red-black tree
void insert(struct RedBlackTree* tree, int data){
    struct node *newNode = createNode(tree, data);
    struct node *y = tree->NIL;
    struct node *x = tree->root;

    while (x != tree->NIL)
    {
        y = x;
        if (data < x->data)
        {
            x = x->left;
        }else{
            x = x->right;
        }
    }

    newNode->parent = y;
    if (y == tree->NIL)
    {
        tree->root = newNode;
    }else if (data < y->data)
    {
        y->left = newNode;
    }else{
        y->right = newNode;
    }

    insertFixup(tree, newNode);
}

    int main()
{
    struct node sentinel;
    sentinel.color = BLACK;
    sentinel.data = 0;
    sentinel.left = NULL;
    sentinel.right = NULL;

    struct RedBlackTree tree;
    tree.NIL = &sentinel;
    tree.root = tree.NIL;
    return 0;
}