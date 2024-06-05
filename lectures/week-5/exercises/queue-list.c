#include <stdio.h>

#define CAPACITY 10

typedef struct _queue
{
    int array[CAPACITY];
    int front;
    int size;
} queue;

void enqueue(queue *q, int data);

int main(void)
{
    queue q;
    q.front = 0;
    q.size = 0;

    enqueue(&q, 28);
    enqueue(&q, 33);
    enqueue(&q, 19);

    printf("%d", q.array[q.size - 1]);
}

void enqueue(queue *q, int data)
{
    q->array[q->size] = data;
    q->size += 1;
}

void dequeue(queue *q)
{
    q->front += 1;
    q->size -= 1;
}