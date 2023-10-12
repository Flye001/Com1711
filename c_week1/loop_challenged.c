#include <stdio.h>

int NumberGuesser() {
    int numberToGuess = 23;
    int guess = 0;
    printf("Welcome to the number guesser! The number is between 1 and 25\n");

    while (guess != numberToGuess) {
        printf("\nGuess a number: ");
        scanf("%d", &guess);
        if (guess > numberToGuess)
            printf("Too high!");
        else if (guess < numberToGuess)
            printf("Too low!");
    }

    printf("Congrats, you guessed correctly! it was %d!\n", numberToGuess);
}

int TimesTable() {
    for (int x = 1; x <= 12; x++) {
        printf("\nThe %d times table:\n", x);
        for (int y = 1; y <= 12; y++) {
            printf("%d * %d = %d\n", x, y, x*y);
        }
    }
}

int main() {
    TimesTable();

    return 1;
}