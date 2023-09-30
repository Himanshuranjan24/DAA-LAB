#include <stdio.h>
#include <stdlib.h>
struct Item {
    float value;
    float weight;
};
int compare(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    float ratioA = itemA->value / itemA->weight;
    float ratioB = itemB->value / itemB->weight;
    return (ratioB > ratioA) ? 1 : -1;
}
void fractionalKnapsack(struct Item items[], int n, float capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    float totalValue = 0.0; 
    float totalWeight = 0.0; 

    printf("Item No  Value  Weight  Amount to be taken\n");

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity)
         {
            printf("%d\t%.6f\t%.6f\t%.6f\n", i + 1, items[i].value, items[i].weight, 1.0);
            totalValue += items[i].value;
            totalWeight += items[i].weight;
        } else {
            
            float fraction = (capacity - totalWeight) / items[i].weight;
            printf("%d\t%.6f\t%.6f\t%.6f\n", i + 1, items[i].value, items[i].weight, fraction);
            totalValue += (items[i].value * fraction);
            break;
        }
    }

    printf("Maximum profit: %.6f\n", totalValue);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the Value of item %d: ", i + 1);
        scanf("%f", &items[i].value);
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%f", &items[i].weight);
    }

    float capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    fractionalKnapsack(items, n, capacity);

    return 0;
}

