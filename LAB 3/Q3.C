#include <stdio.h>
#include <stdbool.h>
int unique(int a[], int n, int result[]) {
    int uniqueCount = 0;
    bool isUnique;

    for (int i = 0; i < n; i++) {
        isUnique = true;
        for (int j = 0; j < uniqueCount; j++) {
            if (a[i] == result[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            result[uniqueCount] = a[i];
            uniqueCount++;
        }
    }

    return uniqueCount;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int result[n]; 
    int uniqueCount = unique(a, n, result);

    printf("Unique elements: ");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
