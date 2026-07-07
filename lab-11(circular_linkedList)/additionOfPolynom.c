// Write a program to perform addition of two polynomial equations using appropriate data structure.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    int coeff;
    int power;
    struct Node *link;
};

struct Node *createNode(int coeff, int power)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->link = NULL;
    return newnode;
}

void insend(struct Node **first, int coeff, int power)
{
    struct Node *node = createNode(coeff, power);

    if (*first == NULL)
    {
        *first = node;
        return;
    }

    struct Node *temp = *first;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = node;
}

void joinlists(struct Node **result, int coeff, int power)
{
    struct Node *temp = *result;

    while (temp != NULL)
    {
        if (temp->power == power)
        {
            temp->coeff += coeff;
            return;
        }
        temp = temp->link;
    }

    insend(result, coeff, power);
}

char *addPolynomial(struct Node *first1, struct Node *first2)
{
    struct Node *result = NULL;
    struct Node *temp = NULL;

    temp = first1;
    while (temp != NULL)
    {
        joinlists(&result, temp->coeff, temp->power);
        temp = temp->link;
    }

    temp = first2;
    while (temp != NULL)
    {
        joinlists(&result, temp->coeff, temp->power);
        temp = temp->link;
    }

    char *str = malloc(1000 * sizeof(char));
    if (str == NULL)
    {
        return NULL;
    }

    str[0] = '\0';
    temp = result;
    bool firstTerm = true;

    while (temp != NULL)
    {
        if (temp->coeff != 0)
        {
            char term[100];
            sprintf(term, "%d x^%d", temp->coeff, temp->power);

            if (!firstTerm)
            {
                strcat(str, " + ");

                firstTerm = false;
            }

            strcat(str, term);
        }
        temp = temp->link;
    }

    return str;
}

void displayPolynomial(struct Node *first)
{
    struct Node *temp = first;

    while (temp != NULL)
    {
        printf("%d x^%d", temp->coeff, temp->power);
        if (temp->link != NULL)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

void inputPolynomial(struct Node **first)
{
    int num, i, coeff, power;

    printf("ENTER TOTAL NUMBERS OF TERMS IN THIS EXPRESSION := ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("enter (coeff) and (power of the variable) space separated := ");
        scanf("%d", &coeff);
        scanf("%d", &power);
        insend(first, coeff, power);
    }
}

void main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    inputPolynomial(&list1);
    inputPolynomial(&list2);

    printf("Poly 1: ");
    displayPolynomial(list1);

    printf("Poly 2: ");
    displayPolynomial(list2);

    char *expression = addPolynomial(list1, list2);

    printf("result is := %s\n", expression);

    free(expression);
}