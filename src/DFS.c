#include <stdio.h>
#include "../utils/DSC.h"

int mark[MAX_N];
void DFS_recursive(Graph *pG, int u)
{
    mark[u] = 1;
    printf("%d\n", u);
    for (int v = 1; v <= pG->n; v++)
    {
        if (adjacent(pG, u, v) && mark[v] != 1)
        {
            DFS_recursive(pG, v);
        }
    }
}

int main()
{
    Graph G;
    int n, m, u, v;
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
        if (mark[u] != 1)
            DFS_recursive(&G, u);
    }

    return 0;
}