#include <stdio.h>
#define MAX_N 100

#define MAX_M 500

// Cấu trúc Edge lưu dữ liệu của 1 cung
typedef struct
{
    int u, v;
} Edge;

// Khai báo cấu trúc dữ liệu Graph
typedef struct
{
    int n, m;
    Edge edges[MAX_M];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    // Đưa cung (u, v) vào edges
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    // Tăng số cung lên 1
    pG->m++;
}

int adjacent(Graph *pG, int u, int v)
{
    // Duyệt qua từng cung 0, 1, 2, …, m - 1
    for (int e = 0; e < pG->m; e++)
    {
        if ((pG->edges[e].u == u && pG->edges[e].v == v)) // kiểm tra có cung dạng (u, v)

        {
            return 1;
        }
    }

    return 0;
}

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

int min(int a, int b)
{
    return a < b ? a : b;
}

int count = 0;
int k;
int num[MAX_N];
int min_num[MAX_N];
Stack S;
int on_stack[MAX_N];
void SCC(Graph *pG, int u)
{
    num[u] = min_num[u] = k;
    k++;
    push(&S, u);
    on_stack[u] = 1;
    for (int v = 1; v <= pG->n; v++)
    {
        if (adjacent(pG, u, v))
        {
            if (num[v] < 0)
            {
                SCC(pG, v);
                min_num[u] = min(min_num[u], min_num[v]);
            }
            else if (on_stack[u])
            {
                min_num[u] = min(min_num[u], num[v]);
            }
        }
    }

    if (num[u] == min_num[u])
    {
        count++;
        int w;
        do
        {
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
        } while (w != u);
    }
}

int main(void)
{
    Graph G;
    int m, n, u, v, e;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    k = 1;
    make_null_stack(&S);
    for (u = 1; u <= G.n; u++)
    {
        num[u] = -1;
        min_num[u] = -1;
        on_stack[u] = 0;
    }

    for (u = 1; u <= G.n; u++)
    {
        if (num[u] == -1)
            SCC(&G, u);
    }

    printf("%d", count);

    return 0;
}
