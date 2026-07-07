// WAP to split a circular linked list into two halves.

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

void separatetwolists(struct Node *first, struct Node *last,struct Node **lastforfirstlist, struct Node **firstforsecondlist)
{
    struct Node *mid=first;
    struct Node *full=first;

    while(full->link->link!=first && full->link!=first)
    {
        full=full->link->link;
        mid=mid->link;
    }
    last->link=mid->link;
    (*firstforsecondlist)=mid->link;
    last->link=*firstforsecondlist;

    *lastforfirstlist=mid;
    (*lastforfirstlist)->link=first;
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
    struct Node *lastforfirstlist=NULL;
    struct Node *firstforlastlist=NULL;
    
    //insert node at starting 
    insert(&first1, &last1, 102);
    insert(&first1, &last1, 101);
    insert(&first1, &last1, 200);
    insert(&first1, &last1, 33);
    insert(&first1, &last1, 6);
    insert(&first1, &last1, 1);
    // insert(&first1, &last1, 40);

    separatetwolists(first1,last1,&lastforfirstlist,&firstforlastlist);

    printlist(first1,lastforfirstlist);
    printlist(firstforlastlist,last1);
}