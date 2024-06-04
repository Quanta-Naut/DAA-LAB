#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define V 5

int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_ind;
    for(int i = 0; i<V; i++){
        if(mstSet[i] == false && key[i] < min){
            min = key[i];
            min_ind = i;
        }
    }
    return min_ind;
}
void printMst(int parent[], int graph[V][V]){
    printf("The MST is: ");
    for(int i = 0; i<V; i++){
        printf("%d--->%d == %d\n", parent[i], i, graph[i][parent[i]]);
    }
}
void prims(int graph[V][V]){
    int parent[V] = {0}, key[V];
    bool mstSet[V];
    for(int i = 0; i<V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i = 0; i< V-1; i++){
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for(int v = 0; v<V; v++){
            if(!mstSet[v] && graph[u][v] && graph[u][v]<key[v]){
                parent[v] = u;                                   //You froget to metion this like remember prims -> parent
                key[v] = graph[u][v];
            }
        }
    }
    printMst(parent, graph);
}
int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Print the solution
	prims(graph);

	return 0;
}
