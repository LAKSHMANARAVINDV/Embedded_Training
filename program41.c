#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct
{
    int arr[max];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

int isFull(Stack *s) { return s->top == (max - 1); }

void push(Stack *s, int ele)
{
    if(isFull(s))
    {
        printf("Stack is full\n");
        return;
    }
    s->arr[++(s->top)] = ele;
}

int pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(Stack* s)
{
    if(isEmpty(s)) return -1;
    return s->arr[s->top];
}

typedef struct
{
    Stack s1, s2;
}Queue;


void intiq(Queue *Q)
{
    init(&Q->s1);
    init(&Q->s2);
}

void enqueue(Queue *q, int x)
{
    push(&q->s1, x);
}

int dequeue(Queue *q)
{
    if (isEmpty(&q->s2))
    {
        while (!isEmpty(&q->s1))
        {
            push(&q->s2, pop(&q->s1));
        }
    }

    if (isEmpty(&q->s2))
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return pop(&q->s2);
}

int front(Queue *q)
{
    if (isEmpty(&q->s2))
    {
        while (!isEmpty(&q->s1))
        {
            push(&q->s2, pop(&q->s1));
        }
    }

    return peek(&q->s2);
}

int main()
{
    Queue q;
    intiq(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Front: %d\n", front(&q));

    return 0;
}