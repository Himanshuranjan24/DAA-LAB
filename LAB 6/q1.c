/*Write a program to read the data from these files and store
them in a dynamically allocated array of struct person. Sort
arrays of struct person based on the height field using Heap Sort.
Plot the time taken and observe how they vary with the size of
the input.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swap(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct person arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].height > arr[largest].height)
        largest = left;

    if (right < n && arr[right].height > arr[largest].height)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(struct person arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    int size = 10;
    struct person *people = (struct person *)malloc(size * sizeof(struct person));
    FILE *file = fopen("dat10000.csv", "r");
    if (!file)
    {
        perror("File open error");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        char name[50];
        fscanf(file, "%d,%[^,],%d,%d,%d\n", &people[i].id, name, &people[i].age, &people[i].height, &people[i].weight);
        people[i].name = strdup(name);
    }

    fclose(file);
    start = clock();
    heapSort(people, size);
    start = clock() - start;

    cpu_time_used = ((double)(start)) / CLOCKS_PER_SEC;
    cpu_time_used = cpu_time_used * 1000000;
    printf("Input Size: %d, Time Taken: %.2f Microseconds\n", size, cpu_time_used);

    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("ID: %d, Name: %s, Age: %d, Height: %d, Weight: %d\n", people[i].id, people[i].name, people[i].age, people[i].height, people[i].weight);
    }

    for (int i = 0; i < size; i++)
    {
        free(people[i].name);
    }
    free(people);

    return 0;
}