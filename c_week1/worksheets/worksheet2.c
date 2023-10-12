#include <stdio.h>

int OutputArray(int array[5]) {
    for (int i = 0; i < 5; i++) {
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
    OutputArray(reversedArray);

}

int main() {
    ex2();
    return 0;
}

