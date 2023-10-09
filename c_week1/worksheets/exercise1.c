#include <stdio.h>

int main() {
    float side1;
    float side2;
    float area;

    printf("Rectangle Calculator\n\n");

    printf("Enter the length of the first side: ");
    scanf("%f", &side1);
    printf("Enter the length of the second side: ");
    scanf("%f", &side2);

    area = side1 * side2;

    printf("The area is %.2f units squared!\n", area);
    return 0;
}