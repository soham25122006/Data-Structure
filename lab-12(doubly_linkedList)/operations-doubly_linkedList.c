// Write a menu driven program to implement following operations on the doubly linked list.
//  Insert a node at the front of the linked list.
//  Delete a node from specified position.
//  Insert a node at the end of the linked list. (Home Work)
//  Display all nodes. (Home Work)

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *l;
    struct Node *r;
};

struct Node *createNode(int x)
{
    struct Node *newnode = malloc(sizeof *newnode);
    newnode->info = x;
    newnode->l = NULL;
    newnode->r = NULL;
    return newnode;
}

void insert(struct Node **first, int x)
{
    struct Node *node = createNode(x);
    if (*first == NULL)
    {
        *first = node;
        return;
    }
    node->r = *first;
    (*first)->l = node;
    *first = node;
}

void insend(struct Node *save, int x)
{
    struct Node *node=createNode(x);
    while (save->r != NULL)
    {
        save = save->r;
    }
    save->r=node;
    node->l=save;
}


int deletekThNode(struct Node **first, int x)
{
    int i, value;
    struct Node *save = *first;
    struct Node *pred = save;
    if (x == 1)
    {
        *first = (*first)->r;
        (*first)->l = NULL;
        value = save->info;
        free(save);
        return value;
    }
    for (i = 1; i < x;)
    {
        pred = save;
        save = save->r;
        i++;
    }
    if (save->r == NULL)
    {
        pred->r = NULL;
        value = save->info;
        free(save);
    }
    else
    {
        pred->r = save->r;
        save->r->l = save->l;
        value = save->info;
        free(save);
    }
    return value;
}

void printlist(struct Node *save)
{
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->r;
    }
    printf("\n");
}

void main()
{
    struct Node *list1 = NULL;

    insert(&list1, 10);
    insert(&list1, 20);
    insert(&list1, 3);
    insert(&list1, 1);

    printlist(list1);

    printf("deleted Node is %d \n", deletekThNode(&list1, 2));

    insend(list1,23);
    printlist(list1);
}
