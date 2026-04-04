#include <stdio.h>

int main() {
    int n, m, directed;
    scanf("%d %d %d", &n, &m, &directed);

    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if (!directed) adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
    return 0;
}