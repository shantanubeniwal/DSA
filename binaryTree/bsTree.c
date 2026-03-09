#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right, *p;
};

struct node* createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->right = newNode->left = newNode->p = NULL;

    return newNode;
}

void insert(struct node* root, int value)
{
    struct node *x = root;
    struct node *y = NULL;

    while (x != NULL)
    {
        y = x;
        if (value < x->data)
        {
            x = x->left;
        }else{
            x = x->right;
        }
    }
    if (y == NULL)
    {
        root = createNode(value);
    }else if(value < y->data){
        y->left = createNode(value);
        y->left->p = y;
    }else{
        y->right = createNode(value);
        y->right->p = y;
    }
}

struct node* tree_search(struct node* root, int value)
{
    struct node *x = root;
    while (x != NULL && value != x->data)
    {
        if (value < x->data)
        {
            x = x->left;
        }else{
            x = x->right;
        }
    }

    return x;
}

struct node* tree_minimum(struct node* root)
{
    struct node *x = root;
    while (x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

struct node* tree_maximum(struct node* root)
{
    struct node *x = root;
    while (x->right != NULL)
    {
        x = x->right;
    }
    return x;
}

struct node* tree_successor(struct node* root, int value){
    struct node *x = tree_search(root, value);
    if (x->right != NULL)
    {
        return tree_minimum(x->right);
    }else{
        struct node *y = x->p;
        while (y != NULL && x == y->right)
        {
            x = y;
            y = y->p;
        }
        return y;
    }
    
}

struct node* tree_predeccessor(struct node* root, int value){
    struct node *x = tree_search(root, value);

    if (x->left != NULL)
    {
        return tree_maximum(x->left);
    }else{
        struct node *y = x->p;
        while (y != NULL && x == y->left)
        {
            x = y;
            y = y->p;
        }
        return y;
    }
    
}

void transplant(struct node **root, struct node *u, struct node *v) {
    if (u->p == NULL){
        *root = v;
    }else if (u == u->p->left){
        u->p->left = v;
    }else{
        u->p->right = v;
    }

    if (v != NULL)
    {
        v->p = u->p;
    }
}

struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    struct node *z = tree_search(root, value);
    if (z == NULL) {
        return root; 
    }
    if (z->left == NULL)
    {
        transplant(&root, z, z->right);
    }else if (z->right == NULL)
    {
        transplant(&root, z, z->left);
    }else
    {
        struct node* y = tree_minimum(z->right);
        if (y != z->right)
        {
            transplant(&root, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(&root, z, y);
        y->left = z->left;
        y->left->p = y;
    }

    free(z);

    return root;
}

void inInorder(struct node* root){
    if (root != NULL)
    {
        inInorder(root->left);
        printf("%d->", root->data);
        inInorder(root->right);
    }
    
}

int main()
{
    struct node *root1 = createNode(15);
    insert(root1,18);
    insert(root1,17);
    insert(root1,20);
    insert(root1,6);
    insert(root1,3);
    insert(root1,4);
    insert(root1,2);
    insert(root1,7);
    insert(root1,13);
    insert(root1,9);

    // struct node* search = tree_search(root1, 15);
    // if (search != NULL)
    // {
    //     printf("found %d!!\n",search->data);
    // }else{
    //     printf("not found!!\n");
    // }
    
    // printf("%d is minimum\n",tree_minimum(root1)->data);
    // printf("%d is maximum\n",tree_maximum(root1)->data);
    
    // printf("Successor of 15 is %d\n", tree_successor(root1, 15)->data);
    // printf("Successor of 13 is %d\n", tree_successor(root1, 13)->data);
    
    // printf("predeccessor of 6 is %d\n", tree_predeccessor(root1, 6)->data);
    // printf("predeccessor of 4 is %d\n", tree_predeccessor(root1, 4)->data);
    
    
    deleteNode(root1, 6);
    inInorder(root1);

    return 0;
}