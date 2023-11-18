#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct Edge {
    int src_2252, dest_2252, weight_2252;
};
int find_2252(int parent_2252[], int i_2252) {
    if (parent_2252[i_2252] == -1)
        return i_2252;
    return find_2252(parent_2252, parent_2252[i_2252]);
}

void unionSets_2252(int parent_2252[], int x_2252, int y_2252) {
    int xroot_2252 = find_2252(parent_2252, x_2252);
    int yroot_2252 = find_2252(parent_2252, y_2252);
    parent_2252[xroot_2252] = yroot_2252;
}

int compareEdges_2252(const void *a_2252, const void *b_2252) {
    return ((struct Edge *)a_2252)->weight_2252 - ((struct Edge *)b_2252)->weight_2252;
}

void kruskalMST_2252(int cost_2252[MAX][MAX]) {
    struct Edge result_2252[MAX];
    int e_2252 = 0;

    struct Edge edges_2252[MAX * MAX];
    int edgeCount_2252 = 0;
    for (int i_2252 = 0; i_2252 < MAX; i_2252++) {
        for (int j_2252 = i_2252 + 1; j_2252 < MAX; j_2252++) {
            if (cost_2252[i_2252][j_2252] != 0) {
                edges_2252[edgeCount_2252].src_2252 = i_2252;
                edges_2252[edgeCount_2252].dest_2252 = j_2252;
                edges_2252[edgeCount_2252].weight_2252 = cost_2252[i_2252][j_2252];
                edgeCount_2252++;
            }
        }
    }
    qsort(edges_2252, edgeCount_2252, sizeof(struct Edge), compareEdges_2252);

    int parent_2252[MAX];
    for (int i_2252 = 0; i_2252 < MAX; i_2252++)
        parent_2252[i_2252] = -1;

    printf("Edge Cost\n");
    for (int i_2252 = 0; i_2252 < edgeCount_2252; i_2252++) {
        int x_2252 = find_2252(parent_2252, edges_2252[i_2252].src_2252);
        int y_2252 = find_2252(parent_2252, edges_2252[i_2252].dest_2252);

        if (x_2252 != y_2252) {
            result_2252[e_2252++] = edges_2252[i_2252];
            unionSets_2252(parent_2252, x_2252, y_2252);
        }
    }
    for (int i_2252 = 0; i_2252 < e_2252; i_2252++) {
        printf("(%d, %d) %d\n", result_2252[i_2252].src_2252 + 1, result_2252[i_2252].dest_2252 + 1, result_2252[i_2252].weight_2252);
    }
}

int main() {
    int n_2252 = 10;
    int cost_2252[MAX][MAX];
    for (int i_2252 = 0; i_2252 < n_2252; i_2252++) {
        for (int j_2252 = 0; j_2252 < n_2252; j_2252++) {
            if ((j_2252 == i_2252 + 1) || (i_2252 > 0 && j_2252 % i_2252 == 0)) {
                cost_2252[i_2252][j_2252] = (i_2252 + j_2252) * (i_2252 + j_2252) % 100;
                cost_2252[j_2252][i_2252] = cost_2252[i_2252][j_2252];  
            } else {
                cost_2252[i_2252][j_2252] = 0; 
            }
        }
    }
    printf("Cost-adjacency matrix:\n");
    for (int i_2252 = 0; i_2252 < n_2252; i_2252++) {
        for (int j_2252 = 0; j_2252 < n_2252; j_2252++) {
            printf("%4d ", cost_2252[i_2252][j_2252]);
        }
        printf("\n");
    }
    printf("\nMinimum-cost spanning tree (Kruskal's algorithm): \n");
    kruskalMST_2252(cost_2252);

    return 0;
}
