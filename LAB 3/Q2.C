#include <stdio.h>

int main() {
    long long low = -1e18; 
    long long high = 1e18; 

    printf("Think of an integer X.\n");

    while (low + 1 < high) {
        long long mid = low + (high - low) / 2; 

        printf("Is your number less than or equal to %lld? (yes/no): ", mid);
        
        char response[10];
        scanf("%s", response);

        if (response[0] == 'y' || response[0] == 'Y') {
            high = mid; 
        } else {
            low = mid;
        }
    }

    printf("Your number is %lld.\n", high);

    return 0;
}

