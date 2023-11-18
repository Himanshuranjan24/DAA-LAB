#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}
void printMST(int parent[], int **graph, int n) {
    printf("\nMinimum Spanning Tree Cost Adjacency Matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int totalWeight = 0;
    printf("\nTotal Weight of the Spanning Tree: ");

    for (int i = 1; i < n; i++) {
        printf("%d", graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];

        if (i < n - 1) {
            printf(" + ");
        }
    }

    printf(" = %d\n", totalWeight);
}
void primMST(int **graph, int n, int startVertex) {
    int parent[n]; 
    int key[n];    

    int mstSet[n]; 
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[startVertex] = 0;
    parent[startVertex] = -1; 
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, n);
}

int main() {
    int n;
    printf("Number of Vertices: ");
    scanf("%d", &n);
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Starting Vertex: ");
    scanf("%d", &startVertex);
    primMST(graph, n, startVertex - 1);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

