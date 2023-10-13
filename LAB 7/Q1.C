#include <stdio.h>
#include <stdlib.h>
struct ITEM {
    double value;
    double weight;
};

void maxHeapify(struct ITEM items[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && (items[left].value / items[left].weight) > (items[largest].value / items[largest].weight))
        largest = left;

    if (right < n && (items[right].value / items[right].weight) > (items[largest].value / items[largest].weight))
        largest = right;

    if (largest != i) {
        struct ITEM temp = items[i];
        items[i] = items[largest];
        items[largest] = temp;
        maxHeapify(items, n, largest);
    }
}
void heapSort(struct ITEM items[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(items, n, i);

    for (int i = n - 1; i >= 0; i--) {
        struct ITEM temp = items[0];
        items[0] = items[i];
        items[i] = temp;
        maxHeapify(items, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM items[n];

    printf("Enter the Value and Weight of items:\n");
    for (int i = 0; i < n; ++i) {
        printf("Item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of knapsack: ");
    double capacity;
    scanf("%lf", &capacity);
    
    heapSort(items, n);

    printf("Item No\tValue\tWeight\tAmount to be taken\n");

    double totalValue = 0.0;
    for (int i = 0; i < n; ++i) {
        if (items[i].weight <= capacity) {
            printf("%d\t%.6lf\t%.6lf\t1.000000\n", i + 1, items[i].value, items[i].weight);
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            double fraction = capacity / items[i].weight;
            printf("%d\t%.6lf\t%.6lf\t%.6lf\n", i + 1, items[i].value, items[i].weight, fraction);
            totalValue += items[i].value * fraction;
            break;
        }
    }

    printf("Maximum profit: %.6lf\n", totalValue);

    return 0;
}
