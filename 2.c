#include<stdio.h>

int main() {
    int i, j, n = 11;

    // Outer loop: controls the number of rows (0 to 3 → 4 rows total)
    for(i = 0; i <= 3; i++) {

        // Inner loop: controls how many numbers to print on each row
        for(j = 0; j <= i; j++) {
            printf("%d ", n); // Print the current value of n followed by a space
            n++;              // Increment n for the next number
        }

        printf("\n"); // Move to the next line after each row
    }
}
