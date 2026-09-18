#pragma once
#include <stdio.h>

#define MAX_SIZE 100
typedef int ElementType;
typedef struct
{
    ElementType data[MAX_SIZE];
    int top_idx;
} Stack;

void make_null_stack(Stack *pS)
{
    pS->top_idx = -1;
}

int empty(Stack *pS)
{
    return pS->top_idx == -1;
}

void push(Stack *pS, ElementType x)
{
    pS->top_idx++;
    pS->data[pS->top_idx] = x;
}

ElementType top(Stack *pS)
{
    return pS->data[pS->top_idx];
}

void pop(Stack *pS)
{
    pS->top_idx--;
}