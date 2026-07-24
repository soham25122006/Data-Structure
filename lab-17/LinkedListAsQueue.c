// Write a program to implement queue using singly linked list.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int info;
    struct Node *link;
} Node;
typedef struct
{
    Node *front;
    Node *rear;
} Queue;
void initialize(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}
Node *createNode(int x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->info = x;
    newNode->link = NULL;
    return newNode;
}
void enQueue(Queue *q, int x)
{
    Node *node = createNode(x);
    if (q->front == NULL)
    {
        q->front = node;
        q->rear = node;
        return;
    }
    q->rear->link = node;
    q->rear = node;
}
int deQueue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty!!");
        return -1;
    }
    Node *save = q->front;
    int ele = save->info;
    if (q->front == q->rear)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
        q->front = q->front->link;

    free(save);
    return ele;
}
void display(Queue q)
{
    Node *save = q.front;
    while (save != q.rear)
    {
        printf("%d ", save->info);
        save = save->link;
    }
    printf("%d ", save->info);
    printf("\n");
}
void main()
{
    Queue q;
    initialize(&q);

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
            printf("\ndeleted element is %d\n",deQueue(&q));
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