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
    struct node* root;
    struct node* NIL; // Pointer to the shared sentinel
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

void leftRotate(struct RedBlackTree* tree, struct node* x){
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != tree->NIL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == tree->NIL)
    {
        tree->root = y;
    }else if (x == x->parent->left)
    {
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(struct RedBlackTree* tree, struct node* x){
    struct node *y = x->left;
    x->left = y->right;

    if (y->right != tree->NIL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    
    if (x->parent == tree->NIL)
    {
        tree->root = y;
    }else if (x == x->parent->left)
    {
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

void insertFixup(struct RedBlackTree* tree, struct node* newNode){
    struct node *u;  //UNCLE
    
    while (newNode->parent != tree->NIL && newNode->parent->color == RED)
    {
        struct node *p = newNode->parent;  //PARENT
        struct node *g = p->parent;  //GRAND-PARENT
        // Case A: Parent is the LEFT child of the Grandparent
        if (p == g->left)
        {
            u = g->right; //uncle is left child of grandparent

            //uncle is red
            if (u != tree->NIL && u->color == RED)
            {
                u->color = p->color = BLACK;
                g->color = RED;
                newNode = g;
            }
            // uncle is black
            else
            {
                // zig-zag formation
                if (newNode == p->right)
                {
                    newNode = p;
                    leftRotate(tree, newNode);
                    p = newNode->parent;
                    g = p->parent;
                }
                // straight line formation on g's left side
                g->color = RED;
                p->color = BLACK;
                rightRotate(tree, g);
            }
            

        }
        // Case B: Parent is the RIGHT child of the Grandparent
        else{
            u = g->left;  //uncle is right child of grandparent
            // uncle is red
            if (u != tree->NIL && u->color == RED)
            {
                u->color = p->color = BLACK;
                g->color = RED;
                newNode = g;
            }
            // uncle is black
            else
            {
                // zig-zag formationn
                if (newNode == p->left)
                {
                    newNode = p;
                    rightRotate(tree, newNode);
                    p = newNode->parent;
                    g = p->parent;
                }
                // straight line formation on g's right side
                p->color = BLACK;
                g->color = RED;
                leftRotate(tree, g);
            }
            
        }
        
    }
    tree->root->color = BLACK;
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

// Delete a node
// code is based on CLRS book pseudocode
// If the deleted node is Red: No properties are violated. We just remove it.
// If the deleted node is Black: We lose a black node on one specific path. This violates the Black Height Property

struct node* search(struct RedBlackTree* tree, int value){
    struct node *x = tree->root;
    while (x != tree->NIL)
    {
        if (value < x->data)
        {
            x = x->left;
        }else if (value > x->data)
        {
            x = x->right;
        }else
        {
            return x;
        }
    }
    return x;
}

struct node* node_minimum(struct RedBlackTree* tree ,struct node* node){
    struct node *x = node;
    struct node *y = NULL;
    while (x != tree->NIL)
    {
        y = x;
        x = x->left;
    }
    return y;
}

void RB_Transplant(struct RedBlackTree* tree, struct node* u, struct node* v){
    if (u->parent == tree->NIL)
    {
        tree->root = v;
    }else if (u == u->parent->left)
    {
        u->parent->left = v;
    }else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void delete(struct RedBlackTree* tree, int data){
    struct node *z = search(tree, data);
    struct node *y = z;
    struct node *x = NULL;
    int y_original_color = y->color;

    if (z == tree->NIL)
    {
        printf("no matching node is found to delete");
        return;
    }

    // if z have only one child or no child
    if (z->left == tree->NIL)
    {
        x = z->right;
        RB_Transplant(tree, z, z->right);
    }else if (z->right == tree->NIL)
    {
        x = z->left;
        RB_Transplant(tree, z, z->left);
    }else
    {
        // if z have two children
        y = node_minimum(tree, z->right);
        y_original_color = y->color;
        x = y->right;
        if (y != z->right)
        {
            // y is not direct child of z
            RB_Transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }else
        {
            // if y is direct child of z
            x->parent = y;
        }
        RB_Transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);
    if (y_original_color == BLACK)
    {
        RB_Delete_Fixup(tree, x);
    }
}

void RB_Delete_Fixup(struct RedBlackTree* tree, struct node* x){
    struct node *w = NULL;
    while (x != tree->NIL && x->color == BLACK)
    {
        // if x is left child
        if (x == x->parent->left)
        {
            w = x->parent->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(tree, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(tree, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(tree, x->parent);
                x = tree->root;
            }
        }else
        {
            w = x->parent->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(tree, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = BLACK;
}

// Helper function to print the tree in-order
void printInOrder(struct RedBlackTree* tree, struct node* root) {
    if (root != tree->NIL) {
        printInOrder(tree, root->left);
        
        // Print the node's data and its color
        printf("%d (%s) \n", root->data, root->color == RED ? "RED" : "BLACK");
        
        printInOrder(tree, root->right);
    }
}

int main()
{
    struct node sentinel;
    sentinel.color = BLACK;
    sentinel.data = 0;
    sentinel.left = NULL;
    sentinel.right = NULL;
    sentinel.parent = NULL;

    struct RedBlackTree tree;
    tree.NIL = &sentinel;
    tree.root = tree.NIL;

    insert(&tree, 10);
    insert(&tree, 20);
    insert(&tree, 30);

    insert(&tree, 15);
    insert(&tree, 75);
    insert(&tree, 45);
    insert(&tree, 65);

    printf("Tree after deletion of 20:\n");
    delete(&tree, 20);

    printf("Red-Black Tree In-Order Traversal:\n");
    printInOrder(&tree, tree.root);
    return 0;
}