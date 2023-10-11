#include <stdio.h>

int ex1()
{
    printf("Hello world!\n");
}

int ex2()
{
    int int1;
    int int2;
    printf("Enter a number: ");
    scanf("%d", &int1);
    printf("Enter a number: ");
    scanf("%d", &int2);
    int sum = int1 + int2;
    printf("The sum of %d and %d is %d!\n", int1, int2, sum);
}

int ex3()
{
    printf("Max size of an int: %d\n", __INT_MAX__);
    printf("Max size of a float: %f\n", __FLT_MAX__);
    printf("Max size of a double: %f\n", __DBL_MAX__);
    printf("Max size of a char: %d\n", __SCHAR_MAX__);
}

int ex4()
{
    float radius;
    const float pi = 3.14159;
    printf("Enter the cirlce radius: ");
    scanf("%f", &radius);
    float area = pi * radius * radius;
    printf("The area is approximately %.2f units squared!\n", area);
}

int ex5()
{
    // Define initial vars
    int var1 = 5;
    int var2 = 7;
    // Swap vars
    int temp = var1;
    var1 = var2;
    var2 = temp;
}

int ex6()
{
    int num;
    printf("Enter a number please: ");
    scanf("%d", &num);
    int rem = num % 2;
    if (rem == 0)
    {
        printf("%d is even!\n", num);
    }
    else
    {
        printf("%d is odd!\n", num);
    }
}

int ex7()
{
    float fahrenheit;
    printf("Enter fahrenheit: ");
    scanf("%f", &fahrenheit);
    float cel = fahrenheit - 32;
    cel = cel / 1.8;
    printf("%.2f degrees F is %.2f degrees C\n", fahrenheit, cel);
}

int ex8()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = num;
    if (num == 0)
        result = 1;
    else
    {
        for (int i = num - 1; i > 0; i--)
        {
            result = result * i;
        }
    }
    printf("%d! = %d\n", num, result);
}

int ex9() {
    const long SpeedOfLight = 299792458; // Speed in m/s
    const long SecondsInDay = 86400;
    int days;
    printf("Enter the number of days: ");
    scanf("%d", &days);
    long distance = days * SecondsInDay * SpeedOfLight;
    printf("In %d days, light will travel %ld meters.\n", days, distance);
}

int ex10() {
    float initialBal, rate, years;
    printf("Enter your initial balance: ");
    scanf("%f", &initialBal);
    printf("Enter your interest rate: ");
    scanf("%f", &rate);
    printf("Enter the number of years: ");
    scanf("%f", &years);

    float finalVal = initialBal * rate * years;
    printf("Your £%.2f at %.3f%% after %.1f years will be worth £%.2f!\n", initialBal, rate, years, finalVal);
}

int main()
{
    ex10();

    return 0;
}
