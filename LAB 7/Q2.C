#include <stdio.h>
#include <stdlib.h>
struct CHAR {
    char symbol;
    int frequency;
};
struct Node {
    struct CHAR data;
    struct Node* left;
    struct Node* right;
};
void swap(struct CHAR* a, struct CHAR* b) {
    struct CHAR temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(struct CHAR arr[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left].frequency < arr[smallest].frequency)
        smallest = left;

    if (right < size && arr[right].frequency < arr[smallest].frequency)
        smallest = right;

    if (smallest != index) {
        swap(&arr[index], &arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}
void buildMinHeap(struct CHAR arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(arr, size, i);
}
struct CHAR extractMin(struct CHAR arr[], int* size) {
    struct CHAR min = arr[0];
    arr[0] = arr[(*size) - 1];
    (*size)--;
    minHeapify(arr, *size, 0);
    return min;
}
struct Node* buildHuffmanTree(struct CHAR arr[], int size) {
    buildMinHeap(arr, size);
    
    while (size > 1) {
        struct Node* leftNode = (struct Node*)malloc(sizeof(struct Node));
        struct Node* rightNode = (struct Node*)malloc(sizeof(struct Node));
        
        leftNode->data = extractMin(arr, &size);
        rightNode->data = extractMin(arr, &size);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data.frequency = leftNode->data.frequency + rightNode->data.frequency;
        newNode->left = leftNode;
        newNode->right = rightNode;

        arr[size++] = newNode->data;
        buildMinHeap(arr, size);
    }
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = arr[0];
    root->left = NULL;
    root->right = NULL;

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->data.symbol);
        inOrderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct characters: ");
    scanf("%d", &n);

    struct CHAR characters[n];

    printf("Enter the characters: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &characters[i].symbol);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &characters[i].frequency);
    }

    struct Node* root = buildHuffmanTree(characters, n);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    
    return 0;
}