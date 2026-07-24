// You have an array A of integers of size N, an array B (initially empty) and a stack S (initially empty). You are allowed to do the following operations:
//  Take the first element of array A and push it into S and remove it from A.
//  Take the top element from stack S, append it to the end of array B and remove it from S.
// You have to tell if it possible to move all the elements of array A to array B using the above operations such that finally the array B is sorted in ascending order.
// Input Format :
//  First line will contain T, number of testcases. Then the testcases follow.
//  First line of each testcase contains a single integer N.
//  Second line of each testcase contains N distinct integers : A1,A2...AN.
// Output Format :
// For each testcase, if it possible to move all the elements of array A to array B using the above operations such that finally, the array B is sorted in ascending order, print "YES" (without quotes), else print "NO" (without quotes).

// Sample Example:
// Input:       Output:
// 2            YES
// 4            NO
// 1 2 4 3
// 4
// 1 3 4 2
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

void copyArray(int b[], int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
}
void sort(int a[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

char *isBSorted(int A[], int size)
{
    stack s;
    initialize(&s);
    int B[size];
    int i, j=0;
    int C[size];
    copyArray(C, A, size);
    sort(C, size);
    push(&s, A[i]);
    while (i < size)
    {
        if (s.array[s.top] == C[j])
        {
            B[i] = pop(&s);
            j++;
        }
        else
        {
            push(&s, A[i++]);
        }
    }
}
void main()
{
    int n, T;
    printf("enter the number of test case :=");
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        printf("enter the size of array:=\n");
        scanf("%d", &n);
        int *A = malloc(n * sizeof(int));
        printf("enter the array:=");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", (A + i));
        }
        printf("%s", isBSorted(A, n));
        free(A);
    }
}