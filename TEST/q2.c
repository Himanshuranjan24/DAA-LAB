#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10 // Number of vertices in the graph (1 to 10)

// Function to calculate the weight of an edge between vertices i and j
int calculateWeight(int i, int j) {
    return ((i + j) * (i + j)) % 100;
}

// Function to find the vertex with the minimum key value
int findMinKey(int key[], bool mstSet[]) {
    int min = 101, min_index;

    for (int v = 1; v <= MAX_VERTICES; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the cost-adjacency list representation of the minimum-cost spanning tree
void printMinimumCostSpanningTree(int parent[], int graph[MAX_VERTICES + 1][MAX_VERTICES + 1]) {
    printf("Minimum-Cost Spanning Tree (Cost-Adjacency List Representation):\n");
    printf("Edge \t\tWeight\n");
    for (int i = 2; i <= MAX_VERTICES; i++) {
        printf("%d - %d \t\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to perform Prim's algorithm to find the minimum-cost spanning tree
void primMST(int graph[MAX_VERTICES + 1][MAX_VERTICES + 1]) {
    int parent[MAX_VERTICES + 1]; // Array to store constructed MST
    int key[MAX_VERTICES + 1];    // Key values used to pick minimum weight edge
    bool mstSet[MAX_VERTICES + 1]; // To represent set of vertices included in MST

    // Initialize all keys as infinite
    for (int i = 1; i <= MAX_VERTICES; i++) {
        key[i] = 101; // Initialize with a value greater than any possible edge weight (as per given constraints)
        mstSet[i] = false;
    }

    // Always include vertex 1 as the first vertex
    key[1] = 0;
    parent[1] = -1; // No parent of the first node

    // Construct the MST with MAX_VERTICES - 1 vertices
    for (int count = 1; count <= MAX_VERTICES - 1; count++) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        // Update key values of adjacent vertices of the picked vertex
        for (int v = 1; v <= MAX_VERTICES; v++) {
            // Update key[v] only if it is not in the MST, there is an edge from u to v,
            // and the weight of the edge is smaller than the current key value of v
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the minimum-cost spanning tree
    printMinimumCostSpanningTree(parent, graph);
}

int main() {
    // Create the cost-adjacency matrix representation of the graph
    int graph[MAX_VERTICES + 1][MAX_VERTICES + 1];

    // Initialize the graph with edge weights
    for (int i = 1; i <= MAX_VERTICES; i++) {
        for (int j = 1; j <= MAX_VERTICES; j++) {
            if ((i < j && j % i == 0) || (j == i + 1)) {
                graph[i][j] = calculateWeight(i, j);
                graph[j][i] = calculateWeight(i, j); // Undirected graph
            } else {
                graph[i][j] = 0; // No edge between vertices i and j
            }
        }
    }

    // Perform Prim's algorithm to find the minimum-cost spanning tree
    printf("Finding Minimum-Cost Spanning Tree using Prim's Algorithm:\n");
    primMST(graph);

    return 0;
}