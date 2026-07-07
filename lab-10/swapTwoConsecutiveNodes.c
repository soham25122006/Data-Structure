// Write a program to swap two consecutive nodes in the linked list. Don’t change the values of nodes, implement by changing the link of the nodes.
// Input:- 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
// Output:- 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *createNewnode(int x)
{
    struct Node *newnode = malloc(sizeof *newnode);
    newnode->info = x;
    newnode->link = NULL;

    return newnode;
}
void insert(struct Node **first, int x)
{
    struct Node *node = createNewnode(x);
    node->link = *first;
    *first = node;
}
void swapnodes(struct Node **first)
{
    if (*first == NULL)
    {
        printf("underflow!!");
        return;
    }
    else if ((*first)->link == NULL)
    {
        printf("only node can't swap");
        return;
    }
    else
    {}

    struct Node *temp = *first;
    struct Node *pred = NULL;

    while (temp != NULL && temp->link != NULL)
    {
        struct Node *second = temp->link;

        ( pred == NULL ) ? ( *first = second ) : ( pred->link = second );

        temp->link = second->link;
        second->link = temp;

        pred = temp;
        temp = second->link->link;
    }
}
void displayNodes(struct Node *save)
{
    if (save == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (save != NULL)
        {
            printf(" %d ", save->info);
            save = save->link;
        }
    }
    printf("\n");
}
void main()
{
    struct Node *list1 = NULL;

    insert(&list1, 1);
    insert(&list1, 2);
    insert(&list1, 3);
    insert(&list1, 4);
    insert(&list1, 5);
    insert(&list1, 6);
    insert(&list1, 7);
    insert(&list1, 8);

    swapnodes(&list1);
    displayNodes(list1);
}