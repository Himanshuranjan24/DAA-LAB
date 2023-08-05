#include <stdio.h>
#include <math.h>

double factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

double sine(double x, int d, int* nloop) {
    double result = 0.0;
    double term = x;
    *nloop = 0;

    for (int n = 1; ; n++) {
        result += term;
        term *= -x * x / ((2 * n) * (2 * n + 1));
        (*nloop)++; 

        double epsilon = pow(10, -d);
        if (fabs(term) < epsilon) {
            break; 
        }
    }

    return result;
}

int main() {
    double x;
    int d;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter decimal places: ");
    scanf("%d", &d);

    int nloop;
    double result = sine(x, d, &nloop);

    printf("Result: %.2lf\n", result);

    double c1 = log(nloop) / (d * d);

    printf("Estimated parameter c1: %.6lf\n", c1);

    return 0;
}
