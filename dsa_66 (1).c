#include <stdio.h>

#define N 3

int dfs(int v, int graph[N][N], int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;
    for(int i=0;i<N;i++) {
        if(graph[v][i]) {
            if(!visited[i] && dfs(i,graph,visited,recStack)) return 1;
            else if(recStack[i]) return 1;
        }
    }
    recStack[v] = 0;
    return 0;
}

int hasCycle(int graph[N][N]) {
    int visited[N]={0}, recStack[N]={0};
    for(int i=0;i<N;i++) {
        if(!visited[i] && dfs(i,graph,visited,recStack)) return 1;
    }
    return 0;
}

int main() {
    int graph[N][N]={{0,1,0},{0,0,1},{1,0,0}};
    printf(hasCycle(graph)?"YES\n":"NO\n");
    return 0;
}