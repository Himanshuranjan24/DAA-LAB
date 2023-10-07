/*Create a heap, which will follow the max-heap and min-heap
properties at each alternative level. Assume the root node will
follow the min-heap property. For
example: At level 0 (root node) will follow the min-heap property, and level 1 will follow the
max-heap property and so on in C language*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 2; i >= 0; i--)
    {
        minHeapify(arr, 3, i);
    }
    int i = 3, j = 0;
    while (i < n)
    {
        j = i;
        if (j <= j * 2)
        {
            minHeapify(arr, n, i);
            j++;
        }
        else
        {
            maxHeapify(arr, n, i);
            j++;
        }
        i++;
    }

    printf("Output: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}