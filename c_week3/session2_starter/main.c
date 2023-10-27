#include "utils.h"

int main() {
    FILE *file = open_file("input.txt", "r");

    // Read file
    int numbers[200];
    int count = 0;
    
    int buffer_size = 35;
    char buffer[buffer_size];
    while (fgets(buffer, buffer_size, file) != NULL) {
        numbers[count] = atoi(buffer);
        count++;
    }
    fclose(file);

    int overTwoK = 0;
    for (int i = 0; i < 200; i++) {
        printf("%d\n", numbers[i]);
        if (numbers[i] > 1000) overTwoK++;
    }
    printf("There are %d numbers >1000!\n", overTwoK);

    int found = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (numbers[i] + numbers[j] == 2020) {
                printf("%d + %d = 2020!\n", numbers[i], numbers[j]);
                found = 1;
                break;
            }
        }
        if (found == 1) break;
    }

    return 0;
}