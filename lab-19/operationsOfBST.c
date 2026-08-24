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

void insert(Node **root, int x)
{
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
Node *inOrderSucessor()
{

}
Node *delete(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data < x)
    {
        return delete(root->right, x);
    }
    else if (root->data > x)
    {
        return delete(root->left, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp=root->right;
            free(root);
            return temp;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp=root->left;
            free(root);
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            Node *in=inOrderSucessor(root->right);
            in->
            free(root);
        }
    }
}

void inOrderTreverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        inOrderTreverse(root->left);
    }
    printf(" %d ", root->data);
    if (root->right != NULL)
    {
        inOrderTreverse(root->right);
    }
}
void preOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ", root->data);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}
void postOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
    printf(" %d ", root->data);
}

int main()
{
    Node *root = NULL;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 9);
    insert(&root, 23);
    printf("preOrderTraverse(root):=\n");
    preOrderTraverse(root);
    printf("\n\n");
    printf("inOrderTreverse(root):=\n");
    inOrderTreverse(root);
    printf("\n\n");
    printf("postOrderTreverse(root):=\n");
    postOrderTraverse(root);
    printf("%d node is deleted ", delete(&root, 20));
    return 0;
}