#include <stdio.h>
#define MAX_N 100

#include "../utils/DSC.h"
#include "../utils/Queue.h"

int mark[MAX_N];
int parent[MAX_N];

void BFS(Graph *pG, int s)
{
    Queue Q;
    make_null_queue(&Q);

    ElementType pair;
    pair.u = s;
    pair.p = -1;
    enqueue(&Q, pair);

    while (!empty(&Q))
    {
        ElementType pair = front(&Q);
        dequeue(&Q);
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
                enqueue(&Q, pair);
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
            BFS(&G, u);
    }

    for (u = 1; u <= G.n; u++)
    {
        printf("%d %d\n", u, parent[u]);
    }

    return 0;
}