#include <stdio.h>
#define INFINITY 999

int min(int i, int j)
{
    if (i < j)
        return i;
    else
        return j;
}
void floyd(int n, int p[10][10])
{
    int i, j, k;
// #pragma omp parallel for private(i, j, k) shared(p)
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
int main()
{
    int i, j, n, a[10][10], d[10][10], source;

    printf("Enter the no.of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);


    floyd(n, a);


    printf("\n\nThe distance matrix is \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    return 0;
}