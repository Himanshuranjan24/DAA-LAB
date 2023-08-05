#include <stdio.h>

typedef unsigned long long ull;

ull gcd(ull a, ull b, int* nloop) {
    *nloop = 0;
    while (b != 0) {
        *nloop += 1; 
        ull temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ull fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    ull fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int k;
    printf("Enter k: ");
    scanf("%d", &k);

    ull fib_k = fibonacci(k);
    ull fib_k1 = fibonacci(k + 1);

    printf("%dth and %dth Fibonacci numbers: %llu, %llu\n", k, k + 1, fib_k, fib_k1);

    int nloop;
    ull result = gcd(fib_k, fib_k1, &nloop);

    printf("GCD: %llu\n", result);

    double c1 = (double)nloop / k;

    printf("Estimated parameter c1: %.6lf\n", c1);

    return 0;
}
