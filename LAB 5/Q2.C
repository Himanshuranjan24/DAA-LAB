#include <stdio.h>

void merge(int arr[], int left, int mid, int right, int *comparisons) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0; 
    j = 0; 
    k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*comparisons)++; 
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, int *comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        
        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);

        
        merge(arr, left, mid, right, comparisons);
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int comparisons = 0;
    mergeSort(arr, 0, n - 1, &comparisons);

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n%d comparisons\n", comparisons);

    return 0;
}

