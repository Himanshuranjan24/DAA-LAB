#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void find_second_smallest_largest(int arr[], int n, int *second_smallest, int *second_largest) {
    if (n < 2) {
        *second_smallest = *second_largest = -1; 
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    *second_smallest = arr[1];
    *second_largest = arr[n - 2];
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int min_range, max_range;
    printf("Enter the minimum value for random generation: ");
    scanf("%d", &min_range);
    printf("Enter the maximum value for random generation: ");
    scanf("%d", &max_range);

    if (min_range >= max_range) {
        printf("Invalid range.\n");
        return 1;
    }

    srand(time(NULL)); 

    int random_array[n];
    for (int i = 0; i < n; i++) {
        random_array[i] = rand() % (max_range - min_range + 1) + min_range;
    }

    printf("Generated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", random_array[i]);
    }
    printf("\n");

    int second_smallest, second_largest;
    find_second_smallest_largest(random_array, n, &second_smallest, &second_largest);

    if (second_smallest != -1 && second_largest != -1) {
        printf("Second Smallest: %d\n", second_smallest);
        printf("Second Largest: %d\n", second_largest);
    } else {
        printf("Array doesn't have enough distinct elements to find the second smallest and second largest.\n");
    }

    return 0;
}

