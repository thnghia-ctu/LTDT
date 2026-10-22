#include <stdio.h>

#define MAX_N 100
// Lưu ý NO_EDGE = -1, không phải là 0 như MTK trước đây
#define NO_EDGE -1
#define oo 999999
typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            pG->A[u][v] = NO_EDGE;
        }
    }
}

// Đây là hàm duy nhất cần thay đổi so với MTK cơ bản
void add_edge(Graph *pG, int u, int v, int w)
{
    pG->A[u][v] = w;
    if (u != v)
    {
        pG->A[v][u] = w;
    }

    pG->m++;
}

// Thuật toán chỉ xét các nút u có mark[u]==0
int mark[MAX_N];
int p[MAX_N];
int pi[MAX_N];
void MooreDijkstra(Graph *pG, int s)
{
    int it, u, v;
    for (u = 1; u <= pG->n; u++)
    {
        mark[u] = 0;
        p[u] = -1;
        pi[u] = oo;
    }

    pi[s] = 0;
    p[s] = -1;

    for (it = 1; it < pG->n; it++)
    {
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++)
        {
            if (mark[j] == 0 && min_pi > pi[j])
            {
                min_pi = pi[j];
                u = j;
            }
        }
        mark[u] = 1;

        for (v = 1; v <= pG->n; v++)
        {
            if (pG->A[u][v] != NO_EDGE && mark[v] == 0)
            {
                if (pi[u] + pG->A[u][v] < pi[v])
                {
                    pi[v] = pi[u] + pG->A[u][v];
                    p[v] = u;
                }
            }
        }
    }
}

void path(int t)
{
    int path[MAX_N], k = 0, current = t;
    while (current != -1)
    {
        path[k] = current;
        k++;
        current = p[current];
    }
    printf("%d", path[k - 1]);
    for (int i = k - 2; i >= 0; i--)
    {
        printf(" -> %d", path[i]);
    }
}

void path_recursive(int u)
{
    if (p[u] == -1)
    {
        printf("%d", u);
    }
    else
    {
        path_recursive(p[u]);
        printf(" -> %d", u);
    }
}

int main(void)
{
    Graph G;
    int u, v, w, m, n, s, t;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    scanf("%d%d", &s, &t);
    MooreDijkstra(&G, s);
    path_recursive(t);

    return 0;
}

/* Nhập đồ thị từ ma trận trọng số m hàng x n cột

init_graph(&G, n * m);
    v = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &w);
            if (j > 1)
                add_edge(&G, v - 1, v, w);
            if (j < n)
                add_edge(&G, v + 1, v, w);
            if (i > 1)
                add_edge(&G, v - n, v, w);
            if (i < m)
                add_edge(&G, v + n, v, w);

            v++;
        }
    }
*/