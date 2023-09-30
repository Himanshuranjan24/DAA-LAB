#include <stdio.h>
#include <stdlib.h>
struct CHAR {
    char symbol;
    int frequency;
};
struct Node {
    struct CHAR data;
    struct Node *left;
    struct Node *right;
};
struct MinPriorityQueue {
    int size;
    struct Node **array;
};
struct Node* createNode(struct CHAR character) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = character;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct MinPriorityQueue* createMinPriorityQueue(int capacity) {
    struct MinPriorityQueue* queue = (struct MinPriorityQueue*)malloc(sizeof(struct MinPriorityQueue));
    queue->size = 0;
    queue->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return queue;
}
void swapNodes(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinPriorityQueue* queue, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < queue->size && queue->array[left]->data.frequency < queue->array[smallest]->data.frequency)
        smallest = left;

    if (right < queue->size && queue->array[right]->data.frequency < queue->array[smallest]->data.frequency)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&queue->array[idx], &queue->array[smallest]);
        minHeapify(queue, smallest);
    }
}
int isEmpty(struct MinPriorityQueue* queue) {
    return queue->size == 0;
}
struct Node* extractMin(struct MinPriorityQueue* queue) {
    struct Node* minNode = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    --queue->size;
    minHeapify(queue, 0);
    return minNode;
}
void insert(struct MinPriorityQueue* queue, struct Node* node) {
    ++queue->size;
    int i = queue->size - 1;
    while (i > 0 && node->data.frequency < queue->array[(i - 1) / 2]->data.frequency) {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}
struct Node* buildHuffmanTree(struct CHAR characters[], int n) {
    struct Node *left, *right, *top;
    struct MinPriorityQueue* queue = createMinPriorityQueue(n);

    for (int i = 0; i < n; ++i) {
        insert(queue, createNode(characters[i]));
    }

    while (!isEmpty(queue)) {
        left = extractMin(queue);
        right = extractMin(queue);

        top = createNode((struct CHAR){'$', left->data.frequency + right->data.frequency});
        top->left = left;
        top->right = right;

        insert(queue, top);
    }
    return extractMin(queue);
}
void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%c", root->data.symbol);
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct characters: ");
    scanf("%d", &n);

    struct CHAR characters[n];

    printf("Enter the characters: ");
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &characters[i].symbol);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &characters[i].frequency);
    }

    struct Node* root = buildHuffmanTree(characters, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);

    return 0;
}
