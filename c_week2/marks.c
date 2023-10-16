#include <stdio.h>
#include <stdlib.h>

int main() {
    int marks;
    // int *marksp = &marks;
    // printf("%p\n", marksp);
    // printf("%p\n", &marks);
    printf("Enter the marks scored: ");
    scanf("%d", &marks);

    if (marks == 0) {
        printf("You got 0 marks :/\n");
    }
    else if (marks < 40) {
        printf("You failed!\n");
    }
    else {
        printf("You passed :D\n");
    }
}