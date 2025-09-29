#include <stdio.h>

int main() {
    int i, j, n = 5;

    for(i = 0; i < n; i++) {
        // Print leading spaces
        for(j = 0; j < i; j++) {
            printf(" ");
        }

        // Print alternating 1s and 0s
        for(j = 0; j < n - i; j++) {
            printf("%d", j % 2 == 0 ? 1 : 0);
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}