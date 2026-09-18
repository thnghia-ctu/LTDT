#pragma once
#include <stdio.h>

#define MAX_SIZE 100
typedef int ElementType;
typedef struct
{
    ElementType data[MAX_SIZE];
    int front, rear;
} Queue;

void make_null_queue(Queue *pQ)
{
    pQ->front = 0;
    pQ->rear = -1;
}

int empty(Queue *pQ)
{
    return pQ->front > pQ->rear;
}

void enqueue(Queue *pQ, ElementType x)
{
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

ElementType front(Queue *pQ)
{
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ)
{
    pQ->front++;
}