// Write a menu driven program to implement Binary Search Tree (BST) & perform following operations:
//  Insert a node
//  Delete a node
//  Search a node
//  Preorder Traversal
//  Postorder Traversal
//  Inorder Traversal
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
void insert(Node **root)
{
    int choice,x;
    printf("enter 1 if you want to enter a value \n enter 2 if you want to set the value to NULL value\n");
    scanf("%d", &choice);
    if(choice==2)
    {
        return NULL;
    }
    scanf("%d",&x);
    if (*root == NULL)
    {
        (*root) = createNode(x);
    }

}
int main()
{
    Node *root = NULL;
    insert(&root);
    return 0;
}