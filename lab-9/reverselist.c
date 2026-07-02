// Write a program to reverse a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *createNewNode(int x)
{
    struct Node *newnode = malloc(sizeof *newnode);

    newnode->info = x;
    newnode->link = NULL;

    return newnode;
}

void insert(struct Node **first, int x)
{
    struct Node *newnode = createNode(x);
    newnode->link = *first;
    *first = newnode;
}

void insend(struct Node **first, int x)
{
    struct Node *newnode = createNode(x);

    if (*first == NULL)
    {
        *first = newnode;
        return;
    }

    struct Node *save = *first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newnode;
}

struct Node *reverselist(struct Node **rlist, struct Node *list)
{
    while(list!=NULL)
    {
        insert(rlist,list->info);
        list=list->link;
    }

    return *rlist;
}
void printlist(struct Node *list)
{
    while (list != NULL)
    {
        printf("%d ", list->info);
        list = list->link;
    }
    printf("\n");
}
void main()
{
    struct Node *l1 = NULL;
    struct Node *l2 = NULL;

    insert(&l1, 1);
    insert(&l1, 2);
    insert(&l1, 3);
    insert(&l1, 4);

    l2 = reverselist(&l2, l1);

    printlist(l2);
}