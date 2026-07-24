// Write a menu driven program to implement following operations on the Queue using an Array
// - ENQUEUE
// - DEQUEUE
// - DISPLAY
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int front;
    int rear;
    int size;
    int *array;
} Queue;
void initialize(Queue *q, int size)
{
    q->front = q->rear = -1;
    q->size = size;
    q->array = malloc(size * sizeof(int));
}
void enQueue(Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue Overflow");
        return;
    }
    q->rear++;

    if (q->front == -1)
        q->front = 0;

    q->array[q->rear] = x;
}
int deQueue(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue underflow!!");
        return -1;
    }
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return q->array[q->front - 1];
}
void display(Queue q)
{
    if (q.front == -1)
    {
        printf("underflow!!");
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.array[i]);
    }
    printf("\n");
}
void main()
{
    Queue q;
    int size;
    printf("enter the size of array:= ");
    scanf("%d", &size);
    initialize(&q, size);
    int choice, ele;

    while (1)
    {
        printf("Menu:\n");
        printf("1. EnQueue\n");
        printf("2. deQueue\n");
        printf("3. display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the element:= ");
            scanf("%d", &ele);
            enQueue(&q, ele);
            break;
        case 2:
            deQueue(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
}