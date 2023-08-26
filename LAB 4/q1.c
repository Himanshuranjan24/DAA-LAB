#include <stdio.h>

int binarySearchFirstPosition(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int position = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            position = mid;
            right = mid - 1;  
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return position;
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

    int position = binarySearchFirstPosition(arr, size, target);

    if (position != -1) {
        printf("%d found at position %d\n", target, position + 1); 
    } else {
        printf("%d not found in the array\n", target);
    }

    return 0;
}
