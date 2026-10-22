#include <stdio.h>
#define MAX_N 100

#include "../utils/DSC.h"
#include "../utils/Stack.h"

int mark[MAX_N];
int parent[MAX_N];

void DFS(Graph *pG, int s)
{
    Stack S;
    make_null_stack(&S);

    ElementType pair;
    pair.u = s;
    pair.p = -1;
    push(&S, pair);

    while (!empty(&S))
    {
        ElementType pair = top(&S);
        pop(&S);
        int u = pair.u, p = pair.p;
        if (mark[u] != 0)
        {
            continue;
        }
        mark[u] = 1;
        parent[u] = p;
        printf("%d\n", u);
        for (int v = 1; v <= pG->n; v++)
        {
            if (adjacent(pG, u, v))
            {
                ElementType pair;
                pair.u = v;
                pair.p = u;
                push(&S, pair);
            }
        }
    }
}

int main(void)
{
    Graph G;
    int u, v, m, n;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (u = 1; u <= n; u++)
    {
        mark[u] = 0;
        parent[u] = -1;
    }

    for (u = 1; u <= G.n; u++)
    {
        if (mark[u] == 0)
            DFS(&G, u);
    }

    for (u = 1; u <= G.n; u++)
    {
        printf("%d %d\n", u, parent[u]);
    }

    return 0;
}