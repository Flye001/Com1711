#include "utils.h"

int main() {
    FILE* file = open_file("squares.dat", "r");

    float count = 0;
    float total = 0;

    int buffer_size = 10;
    char buffer[buffer_size];
    while (fgets(buffer, buffer_size, file) != NULL)
    {
        int num = atoi(buffer);
        total += num;
        count++;
    }
    float average = total / count;

    printf("The average is %.2f\n", average);

    return 0;
}