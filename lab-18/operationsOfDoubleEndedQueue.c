// Write a menu driven program to implement following operations on the Doubled Ended Queue using an Array
// - Insert at front end, Insert at rear end
// - Delete from front end, Delete from rear end
// - Display all elements of the queue
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int front;
    int rear;
    int size;
    int *array;
} DEQueue;
void initialize(DEQueue *q, int size)
{
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->array = malloc(size * sizeof(int));
}
// enqueue
void DQinsert_rear(DEQueue *q, int x)
{
    if (q->rear >= q->size - 1)
    {
        printf("overflow!!");
        return;
    }
    q->rear++;

    if (q->front == -1)
        q->front = 0;

    q->array[q->rear] = x;
}
void DQinsert_front(DEQueue *q, int x)
{
    if (q->front == 0)
    {
        printf("overflow!!");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
        q->front--;

    q->array[q->front] = x;
}
// dequeue
int DQdelete_front(DEQueue *q)
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
int DQdelete_rear(DEQueue *q)
{
    if (q->rear == -1)
    {
        printf("underflow");
        return -1;
    }

    int x = q->array[q->rear];

    if (q->front == q->rear)
        q->front = q->rear = 0;
    else
        q->rear--;

    return x;
}
void display(DEQueue q)
{
    if(q.front==-1)
    {
        printf("queue is empty");
        return;
    }
    int i;
    printf("\n");
    for(i=q.front;i<q.rear;i++)
    {
        printf(" %d ",q.array[i]);
    }
    printf(" %d ",q.array[i]);
    printf("\n");
}
void main()
{
    DEQueue q;
    int size;
    printf("enter the size of array:= ");
    scanf("%d", &size);
    initialize(&q, size);
    int choice, ele;

    while (1)
    {
        printf("Menu:\n");
        printf("1. DQinsert_rear\n");
        printf("2. DQinsert_front\n");
        printf("3. DQdelete_front\n");
        printf("4. DQdelete_rear\n");
        printf("5. display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the element:= ");
            scanf("%d", &ele);
            DQinsert_rear(&q, ele);
            break;
        case 2:
            printf("enter the element:= ");
            scanf("%d", &ele);
            DQinsert_front(&q, ele);
            break;
        case 3:
            DQdelete_front(&q);
            break;
        case 4:
            DQdelete_rear(&q);
            break;
        case 5:
            display(q);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
}