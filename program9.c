#include <stdio.h>

// Simple recursive function to compute a^b
int power(int a, int b) {
    if(b == 0) return 1;       // base case
    return a * power(a, b-1);  // recursive case
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int result = power(a, b);
    printf("%d\n", result);

    return 0;
}