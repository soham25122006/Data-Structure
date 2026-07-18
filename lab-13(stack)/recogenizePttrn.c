// How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a program to solve the above problem.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct
{
    int top;
    int size;
    char *array;
} stack;

void initializestack(stack *s)
{
    int n = 50;
    (*s).top = -1;
    (*s).size = n;
    (*s).array = malloc(n * sizeof(char));
}

void push(stack *s, char x)
{
    if (s->top >= s->size - 1)
    {
        printf(" overflow ");
        return;
    }
    s->top++;
    s->array[s->top] = x;
}

char pop(stack *s)
{
    if (s->top < 0)
    {
        printf(" underflow! ");
        return -1;
    }
    (s->top)--;
    return s->array[s->top + 1];
}

bool checkpattern(stack *s, char p[])
{
    int i = 0;
    while (p[i] != 'c')
    {
        push(s, p[i]);
        i++;
    }
    s->top++;
    i++;
    while (s->top != -1 && p[i] != ' ')
    {
        if (pop(s) != 'a' && p[i] != 'b')
        {
            return false;
        }
        i++;
    }
    if (s->top == -1 && p[i] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printstack(stack s)
{
    if (s.top < 0)
    {
        printf("stack is empty\n");
        return;
    }
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d\n", s.array[i]);
    }
    printf("\n");
}

void main()
{
    stack s;
    initializestack(&s);

    char pttrn[50];
    printf("enter the pattern :=");
    fgets(pttrn, 50, stdin);
    printf("%s", pttrn);
    pttrn[strlen(pttrn)] = ' ';
    if (checkpattern(&s, pttrn))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}