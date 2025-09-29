#include<stdio.h>

int main() {
    int i, j;

    // Loop through each row (total 5 rows: i = 0 to 4)
    for(i = 0; i < 5; i++) {

        // Print leading spaces to align the pattern to the right
        for(j = i; j < 4; j++) {
            printf(" ");
        }

        // Print increasing numbers from (5 - i) to 5
        for(j = 5 - i; j <= 5; j++) {
            printf("%d", j);
        }

        // Print decreasing numbers from 4 down to (5 - i)
        for(j = 4; j >= 5 - i; j--) {
            printf("%d", j);
        }

        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}
