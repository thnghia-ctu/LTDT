#include <stdio.h>
#include "../utils/MTK.h"

int main(void)
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

    return 0;
}