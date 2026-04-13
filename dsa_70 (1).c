#include <stdio.h>

#define INF 99999

typedef struct {
    int u, v, w;
} Edge;

void bellmanFord(Edge edges[], int n, int m, int src) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Shortest distance from %d to %d = %d\n", src, i, dist[i]);
    }
}

int main() {
    int n = 5;
    int m = 8;
    Edge edges[] = {
        {0,1,-1}, {0,2,4},
        {1,2,3},  {1,3,2}, {1,4,2},
        {3,2,5},  {3,1,1}, {4,3,-3}
    };

    bellmanFord(edges, n, m, 0);
    return 0;
}