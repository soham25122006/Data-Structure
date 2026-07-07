// Write a menu driven program to implement following operations on the circular linked list.
// - Insert a node at the front of the linked list.
// - Delete a node from specified position.
// - Insert a node at the end of the linked list.
// - Display all nodes.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};

struct Node *createNode(int x)
{
    struct Node *newnode = malloc(sizeof(*newnode));
    newnode->info = x;
    newnode->link = NULL;

    return newnode;
}
void insert(struct Node **first, struct Node **last, int x)
{
    struct Node *node = createNode(x);
    if (*first == NULL)
    {
        node->link = node;
        (*first) = node;
        (*last) = node;
        return;
    }
    node->link = *first;
    (*last)->link = node;
    *first = node;
}
void insend(struct Node **first, struct Node **last, int x)
{
    struct Node *node = createNode(x);
    if(*first==NULL)
    {
        node->link=*first;
        *first=node;
        *last=node;
        return;
    }
    node->link=*first;
    (*last)->link=node;
    *last=node;
}

int delete(struct Node **first, struct Node **last, int x)
{
    if (*first == NULL)
    {
        printf("underflow!!");
        return -1;
    }
    struct Node *pred = NULL;
    struct Node *save = *first;
    while (save->info != x && save != *last)
    {
        pred = save;
        save = save->link;
    }
    if (save->info != x)
    {
        printf("element Not found!");
        return 404;
    }
    else if (*first == *last)
    {
        *first = NULL;
        *last = NULL;
    }
    else if (x == (*first)->info)
    {
        (*last)->link = (*first)->link;
        *first = (*first)->link;
    }
    else
    {
        pred->link = save->link;
        if (x == (*last)->info)
        {
            *last=pred;
        }
    }
    int value=save->info;
    free(save);
    return value;
}

void printlist(struct Node *first, struct Node *last)
{
    struct Node *save = first;
    while (save != last)
    {
        printf("%d   ", save->info);
        save = save->link;
    }
    printf("%d\n\n", save->info);
}

void main()
{
    struct Node *first1 = NULL;
    struct Node *last1 = NULL;
    //insert node at starting 
    insert(&first1, &last1, 102);
    insert(&first1, &last1, 200);
    insert(&first1, &last1, 33);
    insert(&first1, &last1, 6);
    insert(&first1, &last1, 1);
    insert(&first1, &last1, 40);

    //displaying all nodes 
    printlist(first1, last1);

    //deleting specific node
    printf("%d is deleted node\n\n",delete(&first1, &last1,33));

    //displaying all nodes anfter deleting node
    printlist(first1, last1);

    //insert node at ending
    insend(&first1, &last1, 55);
    insend(&first1, &last1, 66);

    //displaying all nodes after inserting a node in the end
    printlist(first1, last1);
}