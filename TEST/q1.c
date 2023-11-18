#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 9 // Number of vertices in the graph (2 to 10)

// Structure for a node in adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct Graph {
    struct Node* adjList[MAX_VERTICES + 1]; // Adjacency list representation (+1 to accommodate vertices 2 to 10)
};

// Function to initialize a new graph
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 2; i <= MAX_VERTICES; ++i) {
        graph->adjList[i] = NULL; // Initialize all adjacency lists as empty
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    // Add edge from dest to src (undirected graph)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function for Breadth-First Search (BFS)
void BFS(struct Graph* graph, int start) {
    bool visited[MAX_VERTICES + 1]; // Array to keep track of visited vertices
    int distance[MAX_VERTICES + 1]; // Array to store distances from start vertex
    int predecessor[MAX_VERTICES + 1]; // Array to store predecessor vertices

    // Initialize arrays
    for (int i = 2; i <= MAX_VERTICES; ++i) {
        visited[i] = false;
        distance[i] = -1;
        predecessor[i] = -1;
    }

    // Initialize BFS from start vertex
    visited[start] = true;
    distance[start] = 0;
    predecessor[start] = -1;

    // BFS traversal using a queue
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = start;

    while (front < rear) {
        int currentVertex = queue[front++];
        struct Node* temp = graph->adjList[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                distance[adjVertex] = distance[currentVertex] + 1;
                predecessor[adjVertex] = currentVertex;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    // Print d[v] (distance) and π[v] (predecessor) for all vertices
    printf("Vertex\tDistance\tPredecessor\n");
    for (int i = 2; i <= MAX_VERTICES; ++i) {
        printf("%d\t%d\t\t%d\n", i, distance[i], predecessor[i]);
    }
}

int main() {
    // Create the graph
    struct Graph* graph = createGraph();

    // Add edges based on the given conditions
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 8);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 10);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 9);
    addEdge(graph, 9, 10);

    // Perform BFS starting from vertex 2
    printf("BFS starting from vertex 2:\n");
    BFS(graph, 2);

    return 0;
}