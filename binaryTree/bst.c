// practice for BST 
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right, *parent;
};

// to handle many trees at once
struct binary_search_tree{
    struct node *root;
};

struct node* createNode(struct binary_search_tree* tree,int value){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->right = newNode->left = newNode->parent = NULL;
    return newNode;
}

void insert(struct binary_search_tree* tree, int value){
    struct node *newNode = createNode(tree, value);
    struct node *x = tree->root;
    struct node *y = NULL;
    // find the psition where is to enter the input value
    while (x != NULL)
    {
        y = x;
        if (value < x->data)
        {
            x = x->left;
        }else
        {
            x = x->right;
        }
    }
    if (y == NULL)
    {
        tree->root = newNode;
    }else if (value < y->data)
    {
        y->left = newNode;
        newNode->parent = y;
    }else
    {
        y->right = newNode;
        newNode->parent = y;
    }
}

struct node* treeSearch(struct binary_search_tree* tree, int value){
    struct node *x = tree->root;
    while (x != NULL)
    {
        if (value < x->data)
        {
            x = x->left;
        }else if(value > x->data)
        {
            x = x->right;
        }else{
            return x;  // find the matching node
        }
    }
    return NULL; // value not found
}

struct node* treeMinimum(struct binary_search_tree* tree){
    struct node *x = tree->root;
    while ((x != NULL) && (x->left != NULL))
    {
        x = x->left;
    }
    
    return x;
}

struct node* treeMaximum(struct binary_search_tree* tree){
    struct node *x = tree->root;
    while ((x != NULL) && (x->right != NULL))
    {
        x = x->right;
    }
    return x;
}

// helper function for successor
struct node* nodeMinimum(struct node* x) {
    while (x != NULL && x->left != NULL) {
        x = x->left;
    }
    return x;
}

struct node* treeSuccessor(struct binary_search_tree* tree, int value){
    struct node *x = treeSearch(tree, value);
    if (x == NULL)
    {
        return NULL;
    }
    // case 1: if x have right child
    // find successor for 50
    if(x->right != NULL)
    {
        return nodeMinimum(x->right);
    }
    // case 2: if x have no right child
    // find successor for 40
    struct node *y = x->parent;
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

// helper function for Predecessor
struct node* nodeMaximum(struct node* x){
    while (x != NULL && x->right != NULL)
    {
        x = x->right;
    }
    return x;
}

struct node* treePredecessor(struct binary_search_tree* tree, int value){
    struct node *x = treeSearch(tree, value);
    if(x == NULL){
        return NULL;
    }
    // case 1: if x have left child
    // find Predecessor of 50
    if (x->left != NULL)
    {
        return nodeMaximum(x->left);
    }
    // case 2: if x have no left child
    // find Predecessor of 60
    struct node *y = x->parent;
    while (y != NULL && x != y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

// practice to delte a node from BST


void inOrder(struct node* root){
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct binary_search_tree tree = {NULL};

    // Let's build a tree:
    //         50
    //       /    \
    //     30      70
    //    /  \    /  \
    //  20   40  60   80

    insert(&tree, 50);
    insert(&tree, 30);
    insert(&tree, 70);
    insert(&tree, 20);
    insert(&tree, 40);
    insert(&tree, 60);
    insert(&tree, 80);

    printf("In-order traversal: ");
    inOrder(tree.root); 
    printf("\n");
    
    // treeSearch(&tree, 8) ? printf("found") : printf("not found");
    struct node* result = treeSearch(&tree, 8);
    
    if (result) {
        printf("Found value: %d\n", result->data);
    } else {
        printf("Value 8 not found.\n");
    }

    // --- Testing Minimum ---
    struct node* minNode = treeMinimum(&tree);
    if (minNode != NULL) {
        printf("The minimum value in the tree is: %d\n", minNode->data);
    } else {
        printf("The tree is empty, no minimum found.\n");
    }

    // --- Testing Maximum ---
    struct node* maxNode = treeMaximum(&tree);
    if (maxNode != NULL) {
        printf("The maximum value in the tree is: %d\n", maxNode->data);
    } else {
        printf("The tree is empty, no maximum found.\n");
    } 

    struct node* succ1 = treeSuccessor(&tree, 30);
    if (succ1) printf("Successor of 30 is: %d\n", succ1->data);
    else printf("30 has no successor.\n");

    struct node* succ2 = treeSuccessor(&tree, 40);
    if (succ2) printf("Successor of 40 is: %d\n", succ2->data);
    else printf("40 has no successor.\n");
    
    struct node* succ3 = treeSuccessor(&tree, 80);
    if (succ3) printf("Successor of 80 is: %d\n", succ3->data);
    else printf("80 has no successor (it is the maximum).\n");
//  -----x------
    struct node* pred1 = treePredecessor(&tree, 50);
    if (pred1) printf("Predecessor of 50 is: %d\n", pred1->data);
    else printf("50 has no predecessor.\n");

    struct node* pred2 = treePredecessor(&tree, 60);
    if (pred2) printf("Predecessor of 60 is: %d\n", pred2->data);
    else printf("60 has no predecessor.\n");

    struct node* pred3 = treePredecessor(&tree, 20);
    if (pred3) printf("Predecessor of 20 is: %d\n", pred3->data);
    else printf("20 has no predecessor (it is the minimum).\n");

    return 0;
}