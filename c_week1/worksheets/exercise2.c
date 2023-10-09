#include <stdio.h>

int main() {
    char name[12] = "Philip Organ";
    char reversed[12];

    for (int i = 0; i < 12; i++ ) {
        int pos = 11 - i;
        reversed[i] = name[pos];
    }

    printf("The reversed string:\n%s\n", reversed);

    return 0;
}