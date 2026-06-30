// Write a program to copy a linked list.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};

struct Node *createNode(int x)
{
    struct Node *node = malloc(sizeof(*node));
    node->info = x;
    node->link = NULL;
    return node;
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

struct Node *copyList(struct Node **copylist, struct Node *save)
{
    while (save != NULL)
    {
        insert(copylist, save->info);
        save = save->link;
    }
    return *copylist;
}


void printlist(struct Node *list)
{
    struct Node *save = list;
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->link;
    }
    printf("\n");
}

void main()
{
    struct Node *list = NULL;
    struct Node *clist = NULL;

    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    insert(&list, 40);

    clist = copyList(&clist, list);
    printlist(clist);
}