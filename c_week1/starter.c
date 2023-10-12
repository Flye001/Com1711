#include <stdio.h>

int main() {
    int num1, num2, res;
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter a number: ");
    scanf("%d", &num2);
    res = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, res);

    printf("\nNow tell me your favourite animal: ");
    char animal[20];
    scanf("%s", animal);
    printf("Woah, I love %s too!!\n", animal);

    return 0;
}

// Errors:
// scanf("%d", &num1)
// int answer = ...
// printf("...", num1, answer)