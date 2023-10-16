#include <stdio.h>

int OutputArray(int size, int array[size]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int ex1() {
    int myArray[5] = {1,3,6,4,7};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += myArray[i];
    }
    printf("The sum is %d\n", sum);
}

int ex2() {
    int myArray[5] = {1,3,6,4,7};
    int reversedArray[5];

    for (int i = 4; i >= 0; i--) {
        reversedArray[4-i] = myArray[i];
    }
    OutputArray(5, reversedArray);
}

int ex3() {
    int myArray[5] = {1,3,6,4,7};
    int largestElement = 0;
    int largestElementPos = 0;

    for (int i = 0; i < 5; i++) {
        if (myArray[i] > largestElement) {
            largestElement = myArray[i];
            largestElementPos = i;
        }
    }
    printf("The largest element is %d at index %d!\n", largestElement, largestElementPos);
}

int ex4() {
    int myArray[5] = {1,3,6,4,7};
    int rotatedArray[5];

    for (int i = 0; i < 5; i++) {
        rotatedArray[(i+1)%5] = myArray[i];
    }
    OutputArray(5, rotatedArray);
}

int ex5() {
    int myArray[5] = {6,3,6,4,6};
    int uniqueElements[5];
    int uniqueElementsStart = 0;
    int duplicateElements[5];
    int duplicateElementsStart = 0;
    int duplicateIndexes[5];

    for (int i = 0; i < 5; i++) {
        int unique = 1; // Set unique to true by default
        for (int j = 0; j < uniqueElementsStart; j++) {
            if (myArray[i] == uniqueElements[j]) {
                unique = 0;
            }
        }
        if (unique == 0) { // Element is not unique
            printf("Element %d at index %d is a duplicate!\n", myArray[i], i);
            duplicateElements[duplicateElementsStart] = myArray[i];
            duplicateIndexes[duplicateElementsStart] = i;
            duplicateElementsStart++;
        }
        else { // Element is unique
            uniqueElements[uniqueElementsStart] = myArray[i];
            uniqueElementsStart++;
        }
    }
    if (duplicateElementsStart != 0) {
        printf("\nAll Duplicate Elements:\n");
        for (int i = 0; i < duplicateElementsStart; i++) {
            printf("MyArray[%d] = %d\n", duplicateIndexes[i], duplicateElements[i]);
        }
    }
}

int ex6() {
    int array1[3] = {5, 7, 2};
    int array2[3] = {8, 1, 0};
    int array3[6];

    for (int i = 0; i < 3; i++) {
        array3[i] = array1[i];
    }
    for (int i = 0; i < 3; i++) {
        array3[i+3] = array2[i];
    }
    OutputArray(6, array3);
}

int main() {
    ex6();
    return 0;
}

