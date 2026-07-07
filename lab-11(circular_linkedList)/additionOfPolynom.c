// Write a program to perform addition of two polynomial equations using appropriate data structure.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int power;
    struct Node *link;
};

struct Node *createNode(int x, int y)
{
    struct Node *newnode = malloc(sizeof(*newnode));
    newnode->coeff = x;
    newnode->power = y;
    newnode->link = NULL;

    return newnode;
}

void insert(struct Node **first, int x, int y)
{
    struct Node *node = createNode(x, y);

    if (*first == NULL)
    {
        node->link = node;
        *first = node;
        return;
    }
    node->link = *first;
    *first = node;
}

void enterPolynomial(struct Node **first)
{
    int x, i, y, num;
    char more;
    printf("enter total number of terms :=");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        printf("enter co-efficient of term num %d ", i);
        scanf("%d", &x);
        printf("enter power of term num %d ", i);
        scanf("%d", &y);
        insert(first, x, y);
    }
    printf("do you want to add any more terms in expression?(y/n)");
    scanf("%c", &more);
    if (more == 'y')
    {
        printf("how many? :-");
        scanf("%d", &num);

        for (i = 1; i <= num; i++)
        {
            printf("enter co-efficient of term num %d ", i);
            scanf("%d", &x);
            printf("enter power of term num %d ", i);
            scanf("%d", &y);
            insert(first, x, y);
        }
    }
    else
    {}
}

char *addPolynomial(struct Node *first1, struct Node *first2)
{
    
    return;
}

void main()
{
    struct Node *first1 = NULL;
    struct Node *first2 = NULL;

    enterPolynomial(&first1);
    enterPolynomial(&first2);
    addPolynomial(first1, first2);
}