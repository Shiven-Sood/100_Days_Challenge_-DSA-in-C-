#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
int adj[MAX][MAX], visited[MAX], n;

int dfs(int v, int parent) {
    visited[v] = 1;
    for (int u = 0; u < n; u++) {
        if (adj[v][u]) {
            if (!visited[u]) {
                if (dfs(u, v)) return 1;
            } else if (u != parent) return 1;
        }
    }
    return 0;
}

int main() {
    int e, x, y;
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &x, &y);
        adj[x][y] = adj[y][x] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, -1)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}