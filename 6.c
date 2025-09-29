#include <stdio.h>

int main() {
    int i, j;

    // Loop through rows (from 1 to 5)
    for(i = 1; i < 6; i++) {

        // Print increasing numbers from 1 to i
        for(j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Print spaces (double space "  ") for alignment between two number sets
        for(j = i; j < 5; j++) {
            printf("  ");
        }

        // Print decreasing numbers forming the right half of the pattern
        for(j = 0; j >= 1 - i; j--) {
            printf("%d", j + i);
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}
