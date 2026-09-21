#include <stdio.h>
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
        if (
            (pG->edges[e].u == u && pG->edges[e].v == v)     // kiểm tra có cung dạng (u, v)
            || (pG->edges[e].u == v && pG->edges[e].v == u)) // kiểm tra có cung dạng (v, u)
        {
            return 1;
        }
    }

    return 0;
}

// Đếm bậc của đỉnh u bất kỳ
int degree(Graph *pG, int u)
{
    int e, deg_u = 0;
    // Duyệt qua từng cung 0, 1, 2, …, m - 1
    for (e = 0; e < pG->m; e++)
    {
        // Nếu cung có dạng (u, -)
        if (pG->edges[e].u == u)
            deg_u++;
        // Nếu cung có dạng (-, u)
        if (pG->edges[e].v == u)
            deg_u++;
    }

    return deg_u;
}

int main(void)
{
    Graph G;
    int n, m, u, v, e;
    freopen("dt.txt", "r", stdin);

    // Đọc số đỉnh và số cung & khởi tạo đồ thị
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    // Đọc m cung và thêm vào đồ thị
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int u = 1; u <= G.n; u++)
    {
        printf("neighbors(%d) = ", u);
        for (int v = 1; v <= G.n; v++)
        {
            if (adjacent(&G, u, v))
            {
                printf("%d ", v);
            }
        }
        printf("\n");
    }

    for (int u = 1; u <= n; u++)
    {
        printf("deg(%d) = %d\n", u, degree(&G, u));
    }
    return 0;
}