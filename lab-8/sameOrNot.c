//WAP to check whether 2 singly linked lists are same or not.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int info;
    struct Node *link;
};

struct Node *createnode(int x)
{
    struct Node *node = malloc(sizeof *node);
    node->info = x;
    node->link = NULL;

    return node;
}

void insert(struct Node **first, int x)
{
    struct Node *newnode = createnode(x);
    newnode->info = x;
    newnode->link = *first;
    *first = newnode;
}
void insend(struct Node **first, int x)
{
    struct Node *newnode = createnode(x);
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

bool similar_or_not(struct Node *first1,struct Node *first2)
{
    while(first1!=NULL && first2!=NULL)
    {
        if(first1->info != first2->info)
        {
            return false;
        }
        else
        {
            first1 =first1->link;
            first2 =first2->link;
        }
    }
    return true;
}
void main()
{
    struct Node *l1=NULL;
    struct Node *l2=NULL;

    insert(&l1,10);
    insert(&l1,20);
    // insert(&l1,30);

    insert(&l2,10);
    insert(&l2,20);
    insert(&l2,30);

    if(similar_or_not(l1,l2))
    {
        printf("same");
    }
    else
    {
        printf("not same");
    }
}