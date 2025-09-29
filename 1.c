#include<stdio.h>

int main(){
    int i, j;

    // Outer loop runs from 0 to 5 (6 iterations total)
    for(i = 0; i <= 5; i++){

        // Inner loop: j starts at 41 and goes up to (41 + i)
        for(j = 41; j <= 41 + i; j++){
            printf("%d ", j); // Print the current value of j followed by a space
        }

        printf("\n"); // Move to the next line after each row
    }
}
