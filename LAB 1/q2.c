#include <stdio.h>

void product_except_self(int nums[], int n) {
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= nums[i];
    }
    for (int i = 0; i < n; i++) {
        int result = product / nums[i];
        printf("%d ", result);
    }
}

int main() {
    int input_array[] = {3, 4, 5, 1, 2};
    int n = sizeof(input_array) / sizeof(input_array[0]);

    product_except_self(input_array, n);

    return 0;
}

