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
    Node *save;
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

int sameOrNot(Node *root1, Node *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }
    return root1->data == root2->data && sameOrNot(root1->left, root1->left) && sameOrNot(root1->right, root2->right);
}
int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    insert(&root1, 10);
    insert(&root1, 20);
    insert(&root1, 30);
    insert(&root1, 9);
    insert(&root1, 23);

    insert(&root2, 10);
    insert(&root2, 20);
    insert(&root2, 30);
    insert(&root2, 9);
    insert(&root2, 2);

    printf("%d", sameOrNot(root1, root2));

    return 0;
}