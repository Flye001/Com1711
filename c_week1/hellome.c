#include <stdio.h>

int main() {
    char name[15];
    printf("Hello, please enter your name: ");
    scanf("%s", name);
    printf("Nice to meet you %s!\n", name);
    return 0;
}