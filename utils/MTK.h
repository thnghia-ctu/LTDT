#pragma one
#include <stdio.h>

#define MAX_N 100
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
        for (int v = 1; u <= n; u++)
        {
            pG->A[u][v] = 0;
        }
    }
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v] += 1;
    if (u != v)
    {
        pG->A[v][u] += 1;
    }

    pG->m++;
}

int degree(Graph *pG, int u)
{
    int deg_u = 0;
    for (int v = 1; v <= pG->n; v++)
    {
        deg_u += pG->A[u][v];
    }

    return deg_u + pG->A[u][u];
}

int adjacent(Graph *pG, int u, int v)
{
    return pG->A[u][v] > 0;
}