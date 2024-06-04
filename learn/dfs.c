#include<stdio.h>

int i, visit[20], adj[20][20], n, topo[20];

void dfs(int v){
    visit[v] = 1;
    for(int w=1; w<=n; w++){
        if((adj[v][w] == 1 )&& (visit[w] == 0)){
            dfs(w);
        }
    }
    topo[i--] = v;
}
int main(int argc, char const *argv[])
{
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    printf("Enter the adj matric: ");
    for(int v=1; v<=n; v++){
        for(int j=1; j<=n; j++){
            scanf("%d", &adj[v][j]);
        }
    }
    for(int v = 1; v<=n; v++){
        visit[v] = 0;
    }
    i=n;
    for(int v=1; v<=n; v++){
        if(visit[v] == 0){
            dfs(v);
        }
    }
    printf("Topo_ord: ");
    for(int v=1; v<=n; v++){
        printf("v%d", topo[v]);
    }
    return 0;
}
