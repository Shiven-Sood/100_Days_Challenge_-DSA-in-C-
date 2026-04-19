#include <stdio.h>
int g[1001][1001],vis[1001],n;
void dfs(int x){
    vis[x]=1;
    for(int i=1;i<=n;i++) if(g[x][i]&&!vis[i]) dfs(i);
}
int main(){
    int m,u,v,c=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){scanf("%d%d",&u,&v);g[u][v]=g[v][u]=1;}
    for(int i=1;i<=n;i++) if(!vis[i]){dfs(i);c++;}
    printf("%d",c);
}