#include "utils.h"

float GetAverageFromFile(FILE *file, int *newLine)
{
    float count = 0;
    float total = 0;

    int buffer_size = 10;
    char buffer[buffer_size];
    while (fgets(buffer, buffer_size, file) != NULL)
    {
        float num = atof(buffer);
        total += num;
        count++;
    }
    // Check for newline at end of last line
    char currentChar;
    *newLine = 1;
    for (int i = 0; i < buffer_size; i++)
    {
        currentChar = buffer[i];
        if (currentChar == '\n')
        {
            *newLine = 0;
            printf("There is a newline!\n");
            break;
        }
        else if (currentChar == '\0')
            break;
    }

    printf("%f %f\n", total, count);
    float average = total / count;
    return average;
}

int main()
{
    // Open and read the file
    FILE *file = open_file("numbers.dat", "a+");

    // Get the average
    int newLine;
    float average = GetAverageFromFile(file, &newLine);
    printf("Average is: %f\n", average);

    // Append the average
    if (newLine == 0)
    {
        fprintf(file, "%f\n", average);
    }
    else
    {
        fprintf(file, "\n%f\n", average);
    }

    // Close the file
    fclose(file);

    return 0;
}