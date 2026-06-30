#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};
struct Node *first = NULL;
struct Node *save = NULL;
struct Node *pred = NULL;

void insert(int x)
{
    struct Node *newNode = malloc(sizeof *newNode);

    newNode->info = x;
    newNode->link = first;

    first = newNode;
}

void insend(int x)
{
    struct Node *newNode = malloc(sizeof *newNode);

    newNode->info = x;
    newNode->link = NULL;

    save = first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newNode;
}

void displayNode()
{
    save = first;
    if (first == NULL)
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

int removefirst()
{

    if (first == NULL)
    {
        printf("underFlow");
        return -1;
    }
    else
    {
        save = first;
        pred = save;
        first = first->link;
        int ele = save->info;
        struct Node *temp = malloc(sizeof *temp);
        free(save);
        return ele;
    }
}

int removelast()
{
    if (first == NULL)
    {
        printf("Underflow\n");
        return -1;
    }

    save = first;
    pred = NULL;

    if (first->link == NULL)
    {
        int ele = first->info;
        free(first);
        first = NULL;
        return ele;
    }

    while (save->link != NULL)
    {
        pred = save;
        save = save->link;
    }

    int ele = save->info;
    pred->link = NULL;
    free(save);
    return ele;
}

int delete(int x)
{
    if (first == NULL)
    {
        printf("Underflow\n");
        return -1;
    }

    save = first;
    pred = NULL;

    while (save != NULL && save->info != x)
    {
        pred = save;
        save = save->link;
    }

    if (save == NULL)
    {
        printf("Element not found\n");
        return -1;
    }

    if (save == first)
    {
        first = first->link;
    }
    else
    {
        pred->link = save->link;
    }

    int ele = save->info;
    free(save);
    return ele;
}

int countnode()
{
    int c = 0;
    save = first;
    while (save != NULL)
    {
        save = save->link;
        c++;
    }
    return c;
}

void main()
{
    //-----------inserting ele at first--------------
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    //-----------inserting ele at last---------------
    insend(10);
    insend(20);

    //-----------displaying elements-----------------
    displayNode();

    //-----------deleting first elements-------------
    int ele;

    ele = removefirst();
    printf("\n after removing first element = %d\n", ele);
    displayNode();

    //-----------deleting last elements--------------
    ele = removelast();
    printf("\n after removing last element = %d\n", ele);
    displayNode();

    //-----------deleting specific elements----------
    ele = delete(3);
    printf("\n after removing specific element = %d\n", ele);
    displayNode();
    //-----------couting total elements--------------
    ele = countnode();
    printf("\n total number of nodes are %d\n", ele);
}
/*
int i=0

void change()
{
    i=10;
}
void printchange()
{
    printf("%d",i);
}

void main()
{
    change();
    printchange();
    printf("%d",i);
}*/