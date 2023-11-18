#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent;
    int rank;
};
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
void kruskalMST(struct Edge edges[], int n, int m) {
    qsort(edges, m, sizeof(edges[0]), compare);

    struct Subset *subsets = (struct Subset *)malloc(n * sizeof(struct Subset));
    for (int i = 0; i < n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int selectedEdges = 0;
    int totalWeight = 0;

    printf("Edge Cost\n");

    for (int i = 0; i < m; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y) {
            printf("%d--%d %d\n", edges[i].src + 1, edges[i].dest + 1, edges[i].weight);
            totalWeight += edges[i].weight;
            Union(subsets, x, y);
            selectedEdges++;
        }

        if (selectedEdges == n - 1) {
            break;
        }
    }
    printf("\nTotal Weight of the Spanning Tree: %d\n", totalWeight);

    free(subsets);
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge *edges = (struct Edge *)malloc(m * sizeof(struct Edge));
    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        edges[i].src--;
        edges[i].dest--; 
    }
    kruskalMST(edges, n, m);

    free(edges);

    return 0;
}

