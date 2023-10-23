#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// FILE *open_file(char filename[], char mode[]);

int main()
{
    char filename[] = "data.txt";
    FILE *file = open_file(filename, "r");

    int buffer_size = 50;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}

// FILE *open_file(char filename[], char mode[])
// {
//     FILE *file = fopen(filename, mode);
//     if (file == NULL)
//     {
//         perror("");
//         exit(1);
//     }
//     return file;
// }