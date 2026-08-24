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
int insert(Node **root)
{
    int choice, x;

    printf("Enter 1 to insert a value\n");
    printf("Enter 2 to set pointer value to NULL\n");
    printf("Enter 3 to stop: ");
    scanf("%d", &choice);

    if (choice == 3)
    {
        return 1;
    }
    if(choice == 1)
    {
        if (*root == NULL)
        {
            printf("Enter the value: ");
            scanf("%d", &x);
    
            *root = createNode(x);
        }
    }

    if (insert(&(*root)->left) == 1)
        return 1;

    if (insert(&(*root)->right) == 1)
        return 1;

    return 0;
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
int main()
{
    Node *root = NULL;
    insert(&root);
    inOrderTreverse(root);
    return 0;
}