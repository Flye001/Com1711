#include <stdio.h>

int main() {
    char name[15];
    int age;
    char lastInitial;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("What is the first letter of your last name? ");
    scanf("%c", &lastInitial);
    printf("You are %s %c and you are %d years old!\n", name, lastInitial, age);
}