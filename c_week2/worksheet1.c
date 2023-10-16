#include <stdio.h>

int ex1()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Negative number :o\n");
    }
    else if (number == 0)
    {
        printf("zero.. nothing.. the absence of number\n");
    }
    else
    {
        printf("Good ol' positive number :D\n");
    }
}

int ex2()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number % 4 == 0 && number % 5 == 0)
    {
        printf("%d is divisible by 4 and 5\n", number);
    }
    else if (number % 4 == 0)
    {
        printf("%d is only divisible by 4, not 5.\n", number);
    }
    else if (number % 5 == 0)
    {
        printf("%d is only divisible by 5, not 4.\n", number);
    }
    else
    {
        printf("%d is neither dividible by 4 or 5 :(\n", number);
    }
}

int ex3()
{
    int number;
    printf("Enter the marks: ");
    scanf("%d", &number);

    if (number >= 70)
        printf("Distinction, well done!!\n");
    else if (number >= 50)
        printf("Pass, not bad :)\n");
    else
        printf("Fail, whoops!\n");
}

int ex4()
{
    float temp;
    printf("Enter the temperature: ");
    scanf("%f", &temp);
    if (temp <= 40 && temp >= -10)
        printf("Valid\n");
    else
        printf("Don't believe you!\n");
}

int ex5()
{
    int choice;
    int *choicePointer = &choice;
    printf("Welcome to the restaraunt. My name is CeCe, and I'll be taking your order!\n");
    printf("Here are today's specials:\n\n");
    printf("1. Chicken Nuggets\n2. Fish Fingers\n3. Lasagna\n4. Pasta\n5. Pizza\n\n");
    printf("Select an option: ");
    scanf("%d", choicePointer);

    switch (choice)
    {
    case 1:
        printf("Enjoy your nuggets!\n");
        break;
    case 2:
        printf("Fresh fish fingers, coming up!\n");
        break;
    case 3:
        printf("Italy's finest lasagna, good choice!\n");
        break;
    case 4:
        printf("Sorry we're all out of pasta :(\n");
        break;
    case 5:
        printf("Can't go wrong with a pizza!\n");
        break;
    default:
        printf("Well that's just not a valid option now is it... no food for you then\n");
        break;
    }
}

void ex6() {
    int number = 0;
    while (number != -1) {
        printf("Enter a number: ");
        scanf("%d", &number);

        if (number >=0 && number <= 100) {
            printf("Valid number :)\n");
        }
        else if (number == -1) {
            printf("Oh so you've had enough? Okay, bye!\n");
        }
        else {
            printf("Invalid number, try again!\n");
        }
    }
}

int main()
{
    ex6();

    return 0;
}