// WAP to delete alternate nodes of a doubly linked list.
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
    *first = (*first)->l;
}

void deleteAlternate(struct Node *first)
{
    struct Node *save = first;
    struct Node *next = first->r;
    if (first == NULL && first->r == NULL)
    {
        printf("can't perform operation !!");
        return;
    }
    while (save != NULL && save->r != NULL)
    {
        if (save->r == NULL)
        {
            save->l->r = NULL;
            free(save);
        }
        else
        {
            struct Node *next = save->r;
            save->r = next->r;
            next->r->l = next->l;
            free(next);
        }
        save=save->r;
    }
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
    insert(&list1, 30);
    insert(&list1, 40);
    insert(&list1, 50);
    printlist(list1);

    deleteAlternate(list1);
    printlist(list1);
}