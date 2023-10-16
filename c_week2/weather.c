#include <stdio.h>

int main() {
    int temperature = 7;
    const int COLD_THRESHOLD = 6;

    if (temperature <= COLD_THRESHOLD) {
        printf("Its cold, put a jacket on!\n");
    }
    else {
        printf("Its very warm today, no need for a jacket!\n");
    }

    return 0;
}