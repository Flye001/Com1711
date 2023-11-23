#include <stdio.h>
#include <stdlib.h>

int main() {
    int marks[4][5];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            marks[i][j] = rand() % 26;
        }
    }
}