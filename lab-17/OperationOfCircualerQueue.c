#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int first;
    int rear;
    int size;
    int *array;
} Queue;
void initialize(Queue *q, int size)
{
    q->first = q->rear = -1;
    q->size = size;
    q->array = malloc(size * sizeof(int));
}
void enQueue(Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->first)
    {
        printf("overFlow!!");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->array[q->rear] = x;

    if (q->first == -1)
        q->first = 0;
}
int deQueue(Queue *q)
{
    if (q->first == -1)
    {
        printf("Queue underflow!!");
        return -1;
    }
    int x = q->array[q->first];
    if (q->first == q->rear)
    {
        q->first = q->rear = -1;
        return x;
    }
    q->first = (q->first + 1) % q->size;
    return x;
}
void display(Queue q)
{
    if (q.first == -1)
    {
        printf("underflow!!");
        return;
    }
    int i = q.first;
    while (i != q.rear)
    {
        printf("%d ", q.array[i]);
        i = (i + 1) % q.size;
    }
    printf("%d\n", q.array[i]);
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