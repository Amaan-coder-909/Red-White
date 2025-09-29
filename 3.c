#include<stdio.h>

int main(){
    int i, j;

    for(i = 0; i < 5; i++){
        // Print leading spaces (for right alignment)
        for(j = i; j <= 5; j++){
            printf(" ");
        }

        // Print numbers starting from (5 - i) up to 5
        for(j = 5 - i; j <= 5; j++){
            printf("%d", j);
        }

        // Move to next line
        printf("\n");
    }
}
