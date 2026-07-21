// Write a program for evaluation of postfix Expression using Stack.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct
{
    int top;
    int size;
    int *array;
} stack;
void initialize(stack *s)
{
    int n = 50;
    s->top = -1;
    s->size = n;
    s->array = malloc(n * sizeof(char));
}
void push(stack *s, int x)
{
    if (s->top >= s->size - 1)
    {
        printf("\noverflow!\n");
        return;
    }
    s->top++;
    s->array[s->top] = x;
}
int pop(stack *s)
{
    if (s->top < 0)
    {
        printf("\nunderflow!\n");
        return -1;
    }
    s->top--;
    return s->array[s->top + 1];
}

int operation(int op1, int op2, char operator)
{
    if (operator == '+')
    {
        return op1 + op2;
    }
    else if (operator == '-')
    {
        return op1 - op2;
    }
    else if (operator == '/')
    {
        return op1 / op2;
    }
    else if (operator == '*')
    {
        return op1 * op2;
    }
}

int evaluatePrefixExp(stack *s, char str[], int length)
{
    int value = 0, op1, op2;
    char temp;
    for (int i = length-1; i >= 0; i--)
    {
        if (isdigit(str[i]))
        {
            push(s, str[i] - '0');
        }
        else
        {
            op1 = pop(s);
            op2 = pop(s);

            value = operation(op2, op1, str[i]);

            push(s, value);
        }
    }

    return pop(s);
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
    scanf(" %[^\n]", str);
    printf("%d", evaluatePrefixExp(&s, str, strlen(str)));
}