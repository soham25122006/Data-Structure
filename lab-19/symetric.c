// Write a program to check whether the given two trees are same or not.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int x)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(Node **root, int x)
{
    (*root) = createNode(x);
    if (*root == NULL)
    {
        (*root) = createNode(x);
    }
    else if ((*root)->data < x)
    {
        insert(&((*root)->right), x);
    }
    else
    {
        insert(&((*root)->left), x);
    }
}

int isSymmetric(Node *root1, Node *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1==NULL && root2==NULL && root1==root2;
    }
    return isSymmetric(root1->left, root2->right);
}
int main()
{
    Node *root1 = NULL;
    insert(&root1, 10);
    //left
    insert(&root1->left, 5);
    insert(&root1->left->left, 3);
    insert(&root1->left->right, 6);
    //right
    insert(&root1->right, 5);
    insert(&root1->right->right, 3);
    insert(&root1->right->left, 6);

    printf("%d", isSymmetric(root1,root1));

    return 0;
}