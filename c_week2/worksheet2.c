#include <stdio.h>

// Function Declarations
float AreaOfCircle(float radius);
float VolumeOfSphere(float radius);
int StringLength(char* StrPtr);
int IsPrime(int* number);
void ConcatStrings(char string1[], char string2[], char* returnStr);
float Calculator(float* num1, float* num2, char* op);
void ReverseArray(int* arrayPtr, int arrayLen, int* reversedArrayPtr);

const float PI = 3.14159265359;

// Main Function
int main()
{
    // Program 1
    float radius;
    printf("Enter the radius: ");
    scanf("%f", &radius);
    printf("The area is %.2f units ^2!\n", AreaOfCircle(radius));

    // Program 2
    printf("The volume of a sphere with radius %.2f is %.2f units^3!\n", radius, VolumeOfSphere(radius));

    // Program 3
    printf("\nEnter a string: ");
    char myStr[20];
    scanf("%s", myStr);
    printf("Your string had %d characters!\n", StringLength(myStr));

    // Program 4
    printf("\nEnter a number: ");
    int num;
    scanf("%d", &num);
    int prime = IsPrime(&num);
    if (prime) {
        printf("%d is prime!!\n", num);
    }
    else {
        printf("%d is NOT prime :(\n", num);
    }

    // Program 5
    char string1[20];
    char string2[20];
    printf("\nEnter a string: ");
    scanf("%s", string1);
    printf("Enter a string: ");
    scanf("%s", string2);

    int length = StringLength(string1) + StringLength(string2);
    char string3[length];
    ConcatStrings(string1, string2, string3);
    printf("%s\n", string3);

    // Program 6
    float num1, num2, res;
    char op;
    printf("\nWelcome to the Calculator!\n");
    printf("First Number: ");
    scanf("%f", &num1);
    printf("Operator (+,-,*,/): ");
    scanf("%s", &op);
    printf("Second Number: ");
    scanf("%f", &num2);
    res = Calculator(&num1, &num2, &op);
    printf("%f %c %f = %f\n", num1, op, num2, res);

    // Program 7
    int myArray[7] = {1,2,3,4,5,6,7};
    int reversedArray[7];
    ReverseArray(myArray, 7, reversedArray);
    for (int i=0; i < 7; i++) {
        printf("%d ", reversedArray[i]);
    }
    printf("\n");
}

// Program 1
float AreaOfCircle(float radius)
{
    float area = PI * radius * radius;
    return area;
}

// Program 2
float VolumeOfSphere(float radius)
{
    float volume = (4 / 3.0) * PI * radius * radius * radius;
    return volume;
}

// Program 3
int StringLength(char *StrPtr) {
    char currentChar = *StrPtr;
    int length = 0;
    while (currentChar != '\0') {
        length ++;
        currentChar = *(StrPtr + length);
    }
    return length;
}

// Program 4
int IsPrime(int *number) {
    int prime = 1;
    for (int i = 2; i < *number; i++) {
        if (*number % i == 0) {
            prime = 0;
            break;
        }
    }
    return prime;
}

// Program 5
void ConcatStrings(char string1[], char string2[], char* returnStr) {
    int length = StringLength(string1) + StringLength(string2);
    for (int i = 0; i < StringLength(string1); i++) {
        returnStr[i] = string1[i];
    }
    for (int i = 0; i < StringLength(string2); i++) {
        returnStr[StringLength(string1) + i] = string2[i];
    }
}

// Program 6
float Calculator(float* num1, float* num2, char* op) {
    switch (*op) {
        case '+':
            return *num1 + *num2;
        case '-':
            return *num1 - *num2;
        case '*':
            return *num1 * *num2;
        case '/':
            return *num1 / *num2;
        default:
            return 0;
    }
}

// Program 7
void ReverseArray(int* arrayPtr, int arrayLen, int* reversedArrayPtr) {
    for (int i = 0; i < arrayLen; i++) {
        reversedArrayPtr[arrayLen - ( i + 1) ] = arrayPtr[i];
    }
}