#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h> 

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
        i += 6;
    }
    return true;
}

int* generatePrimes(int n, int* count) {
    int* primes = (int*)malloc(n * sizeof(int));
    *count = 0;
    for (int num = 2; num <= n; num++) {
        if (is_prime(num)) {
            primes[*count] = num;
            (*count)++;
        }
    }
    return primes;
}

void count_loops(int n, int* outer_count, int* inner_count) {
    *outer_count = 0;
    *inner_count = 0;

    for (int num = 2; num <= n; num++) {
        (*outer_count)++;
        for (int i = 2; i <= sqrt(num); i++) {
            (*inner_count)++;
        }
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int prime_count;
    int* primes = generatePrimes(n, &prime_count);
    printf("Generated prime numbers: ");
    for (int i = 0; i < prime_count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    int outer_counts[6];
    int inner_counts[6];

    int input_sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    int num_sizes = sizeof(input_sizes) / sizeof(input_sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int outer_count, inner_count;
        count_loops(input_sizes[i], &outer_count, &inner_count);
        outer_counts[i] = outer_count;
        inner_counts[i] = inner_count;
        double c1 = (double)outer_count / input_sizes[i];
        double c2 = (double)inner_count / input_sizes[i];
        printf("For input size %d:\n", input_sizes[i]);
        printf("Estimated parameter c1: %lf\n", c1);
        printf("Estimated parameter c2: %lf\n", c2);
        printf("--------\n");
    }

    printf("Outer loop counts: ");
    for (int i = 0; i < num_sizes; i++) {
        printf("%d ", outer_counts[i]);
    }
    printf("\n");

    printf("Inner loop counts: ");
    for (int i = 0; i < num_sizes; i++) {
        printf("%d ", inner_counts[i]);
    }
    printf("\n");

    free(primes);

    return 0;
}
