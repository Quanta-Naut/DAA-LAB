#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 9

int minDist(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_ind;
    for (int i = 0; i < V; i++)
    {
        if (sptSet[i] == false && dist[i] <= min)
        { // forgot <= near min
            min = dist[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void printSol(int dist[])
{
    printf("Distance from source is: \n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

void dijk(int source, int graph[V][V])
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[source] = 0; // forgot to metion source
    for (int i = 0; i < V - 1; i++)
    {
        int u = minDist(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v]; // take care of u's and v's
        }
    }
    printSol(dist);
}
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    // Function call
    dijk(1, graph);

    return 0;
}
