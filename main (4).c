#include <stdio.h>

unsigned long long factorial(unsigned int n);

int main() {
    unsigned int num;
    printf("Enter a non-negative integer: ");
    scanf("%u", &num);

    if (num < 20) { // Check to prevent overflow for large numbers
        unsigned long long fact = factorial(num);
        printf("Factorial of %u = %llu\n", num, fact);
    } else {
        printf("Input value is too large to calculate factorial.\n");
    }

    return 0;
}

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
