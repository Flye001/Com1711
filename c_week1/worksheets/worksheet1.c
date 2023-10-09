#include <stdio.h>

int ex1() {
    printf("Hello world!\n");
}

int ex2() {
    int int1;
    int int2;
    printf("Enter a number: ");
    scanf("%d", &int1);
    printf("Enter a number: ");
    scanf("%d", &int2);
    int sum = int1 + int2;
    printf("The sum of %d and %d is %d!\n", int1, int2, sum);
}

int ex3() {
    printf("Max size of an int: %d\n", __INT_MAX__);
    printf("Max size of a float: %f\n", __FLT_MAX__);
    printf("Max size of a double: %f\n", __DBL_MAX__);
    printf("Max size of a char: %d\n", __SCHAR_MAX__);
}

int ex4() {
    float radius;
    const float pi = 3.14159;
    printf("Enter the cirlce radius: ");
    scanf("%f", &radius);
    float area = pi * radius * radius;
    printf("The area is approximately %.2f units squared!\n", area);
}

int ex5() {
    // Define initial vars
    int var1 = 5;
    int var2 = 7;
    // Swap vars
    int temp = var1;
    var1 = var2;
    var2 = temp;
}

int ex6() {
    int num;
    printf("Enter a number please: ");
    scanf("%d", &num);
    int rem = num % 2;
    if (rem == 0) {
        printf("%d is even!\n", num);
    }
    else {
        printf("%d is odd!\n", num);
    }
}

int main() {
    ex6();

    return 0;
}

