#include<stdio.h>

int main() {
    int i, j;

    // Loop through each row (total 5 rows)
    for(i = 0; i < 5; i++) {

        // Print the first star at the start of each row
        printf(" *");

        // Print the middle part of the pattern
        for(j = 0; j < 4; j++) {
            // For row 0 and row 2, print stars (forming horizontal bars of 'P')
            if(i == 0 || i == 2) {
                printf("*");
            } else {
                // For other rows, print space (inside of 'P')
                printf(" ");
            }
        }

        // Print the ending star for rows 0, 1, and 2 (vertical bar of 'P')
        if(i == 0 || i == 1 || i == 2) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
