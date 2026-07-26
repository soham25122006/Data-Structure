#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    int priority;
} PQ;
typedef struct
{
    int front;
    int rear;
    int size;
    PQ *array;
} priorityQueue;

void initialize(priorityQueue *pq, int size)
{
    pq->front = -1;
    pq->rear = -1;
    pq->size = size;
    pq->array = malloc(sizeof(PQ));
}
void enQueue(priorityQueue *q, int x, int p)
{
    if (q->rear >= q->size - 1)
    {
        printf("overflow!!\n");
        return;
    }
    q->rear++;

    if (q->front == -1)
        q->front = 0;

    q->array[q->rear].data = x;
    q->array[q->rear].priority = p;
}
PQ deQueue(priorityQueue *q)
{
    PQ x;
    if (q->rear==-1)
    {
        printf("underflow!!\n");
        x.data = -1;
        x.priority = -1;
        return x;
    }
    int i, maxp = 0;
    for (i = 1; i <= q->rear; i++)
    {
        if (q->array[maxp].priority < q->array[i].priority)
            maxp = i;
    }
    x = q->array[maxp];
    for (i = maxp; i <= q->rear; i++)
    {
        q->array[i] = q->array[i + 1];
    }
    q->rear--;

    return x;
}
void display(priorityQueue q)
{
    if(q.rear==-1)
    {
        printf("Priority Queue is empty!!\n");
        return;
    }
    printf("\n-data |-priority\n");
    for (int i=q.front;i<=q.rear;i++)
    {
        printf("\n-%d    |-%d\n",q.array[i].data,q.array[i].priority);
    }
}
void main()
{
    priorityQueue pq;
    int size;
    printf("enter the size of array:= ");
    scanf("%d", &size);
    initialize(&pq, size);
    int ele, choice, p;
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
            printf("enter the element and it's priority(comma separated):= ");
            scanf("%d,%d", &ele, &p);
            enQueue(&pq, ele, p);
            break;
        case 2:
            PQ q = deQueue(&pq);
            if (q.priority == -1)
                ;
            else
                printf("\n%d is deleted(priority : %d)\n", q.data, q.priority);
            break;
        case 3:
            display(pq);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice");
            break;
        }
    }
}