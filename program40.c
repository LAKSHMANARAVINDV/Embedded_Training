#include <stdio.h>
#define SIZE 5

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return (q->front == -1);
}

int isFull(Queue *q)
{
    return ((q->rear + 1) % SIZE == q->front);
}

void enqueue(Queue *q, int val)
{
    if(isFull(q)) {
        printf("Queue is Full\n");
        return;
    }

    if(isEmpty(q))
        q->front = 0;

    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = val;
}

int dequeue(Queue *q)
{
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    int val = q->arr[q->front];

    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % SIZE;

    return val;
}

void display(Queue *q)
{
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }

    int i = q->front;
    printf("Queue: ");
    while(1) {
        printf("%d ", q->arr[i]);
        if(i == q->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    display(&q);

    enqueue(&q, 50);
    enqueue(&q, 60);   
    display(&q);

    return 0;
}