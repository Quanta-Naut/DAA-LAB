#include<stdio.h>

int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}

int floyd(int n, int p[10][10]){
    int i,j,k;
    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter nodes: ");
    scanf("%d", &n);
    printf("Enter adj matrix: ");
    int adj[10][10];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }
    floyd(n, adj);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d  ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
