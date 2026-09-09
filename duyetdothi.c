#include <stdio.h>
#define MAX_M 100
#define MAX_N 500

// Đồ thị (danh sách cung)
typedef struct
{
    int u, v;
} Edge;

typedef struct
{
    int m, n;
    Edge edges[MAX_N];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int adjacent(Graph *pG, int u, int v)
{
    for (int e = 0; e < pG->m; e++)
    {
        if ((pG->edges[e].u == u && pG->edges[e].v == v) || (pG->edges[e].u == v && pG->edges[e].v == u))
            return 1;
    }
    return 0;
}

// Cấu trúc dữ liệu
typedef int ElementType;
#define MAX_SIZE 100
// * Queue *
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

int empty_queue(Queue *pQ)
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

// * Stack *
typedef struct
{
    ElementType data[MAX_SIZE];
    int top_idx;
} Stack;

void make_null_stack(Stack *pS)
{
    pS->top_idx = -1;
}

int empty_stack(Stack *pS)
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

// Duyệt đồ thị
int mark[MAX_N];

void BFS(Graph *pG, int s)
{
    Queue Q;
    make_null_queue(&Q);
    enqueue(&Q, s);
    while (!empty_queue(&Q))
    {
        int u = front(&Q);
        dequeue(&Q);
        if (mark[u])
            continue;
        printf("%d\n", u);
        mark[u] = 1;
        for (int v = 1; v <= pG->n; v++)
        {
            if (adjacent(pG, u, v))
            {
                enqueue(&Q, v);
            }
        }
    }
}

void DFS(Graph *pG, int s)
{
    Stack S;
    make_null_stack(&S);
    push(&S, s);
    while (!empty_stack(&S))
    {
        int u = top(&S);
        pop(&S);
        if (mark[u])
            continue;
        mark[u] = 1;
        for (int v = 1; v <= pG->n; v++)
        {
            if (adjacent(pG, u, v))
            {
                push(&S, v);
            }
        }
    }
}

void DFS_recursive(Graph *pG, int u)
{
    mark[u] = 1;
    for (int v = 1; v <= pG->n; v++)
    {
        if (adjacent(pG, u, v))
            DFS_recursive(pG, v);
    }
}

int main()
{
    int n, m, u, v;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    Graph G;
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    BFS(&G, 1);
    return 0;
}