#include <stdio.h>

int linearSearchFirstPosition(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter element to be searched: ");
    scanf("%d", &target);

    int position = linearSearchFirstPosition(arr, size, target);

    if (position != -1) {
        printf("%d found at position %d\n", target, position + 1);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}
