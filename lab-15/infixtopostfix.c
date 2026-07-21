// Write a program to convert infix notation to postfix notation using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int top;
    int size;
    char *array;
} stack;
int IPF(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 9;
    }
    else if (x == ')')
    {
        return 0;
    }
    else
    {
        return 7;
    }
}
int SPF(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5;
    }
    else if (x == '(')
    {
        return 0;
    }
    else if (x == ')')
    {
        return 0;
    }
    else
    {
        return 8;
    }
}
int R(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    {
        return -1;
    }
    else if (x == '(' || x == ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void initialize(stack *s)
{
    int n = 50;
    s->top = -1;
    s->size = n;
    s->array = malloc(n * sizeof(char));
}
void push(stack *s, char x)
{
    if (s->top >= s->size - 1)
    {
        printf("\noverflow!\n");
        return;
    }
    s->top++;
    s->array[s->top] = x;
}
char pop(stack *s)
{
    if (s->top < 0)
    {
        printf("\nunderflow!\n");
        return -1;
    }
    s->top--;
    return s->array[s->top + 1];
}

int i = 0;
char nextChar(char str[])
{
    return str[i++];
}
char *infixToPostfix(stack *s, char str[], int length)
{
    s->top = 0;
    s->array[s->top] = '(';
    char *polish = calloc(length + 1, sizeof(char));
    char next = nextChar(str), temp;
    int i = 0, rank = 0;
    while (next != '\0')
    {
        if (s->top < 0)
        {
            printf("1Invalid");
            exit(0);
        }
        while (SPF(s->array[s->top]) > IPF(next))
        {
            temp = pop(s);
            polish[i++] = temp;
            rank = rank + R(temp);
            if (rank < 1)
            {
                printf("Invalid");
                exit(0);
            }
        }
        if (SPF(s->array[s->top]) != IPF(next))
        {
            push(s, next);
        }
        else
        {
            pop(s);
        }
        next = nextChar(str);
    }
    if (s->top != -1 || rank != 1)
    {
        printf("2Invalid");
        exit(0);
    }
    else
    {
        return polish;
    }
}
void main()
{
    stack s;
    initialize(&s);
    int n;
    printf("enter the size of string :=");
    scanf("%d", &n);
    getchar();
    char str[n];
    printf("enter the string:=");
    fgets(str, n, stdin);
    str[strcspn(str, "\n")] = ')';
    char polish[n];
    strcpy(polish, infixToPostfix(&s, str, strlen(str)));
    printf("%s", polish);
}