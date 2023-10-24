#include <stdio.h>
#include "utils.h"

int ReadNumber() {
    int num;
    printf("Hello world!\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    return num;
}

int main() {
    int num = ReadNumber();
    FILE* file = open_file("squares.dat", "w");

    for (int i = 1; i <= num; i++) {
        int square = i * i;
        fprintf(file, "%d\n", square);
    }

    fclose(file);

    return 0;
}