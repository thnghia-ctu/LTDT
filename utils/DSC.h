#pragma once

#include <stdio.h>
#define MAX_M 100
#define MAX_N 500

typedef struct
{
    int u, v;
} Edge;

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
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;

    pG->m++;
}

int adjacent(Graph *pG, int u, int v)
{
    for (int e = 0; e < pG->m; e++)
    {
        if ((pG->edges[e].u == u && pG->edges[e].v == v) || (pG->edges[e].u == v && pG->edges[e].v == u))
        {
            return 1;
        }
    }

    return 0;
}