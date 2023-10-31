#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Define any additional variables here
char SOURCE_FILENAME[] = "FitnessData_2023.csv";

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// Open a file
FILE *open_file(char filename[], char mode[])
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        perror("");
        exit(1);
    }
    return file;
}

// Get number of lines
int number_of_lines(FILE *file)
{
    // Read the file line by line and increment lines count after each line
    int buffer_size = 100;
    char buffer[buffer_size];
    int lines = 0;
    while (fgets(buffer, buffer_size, file) != NULL)
    {
        lines++;
    }
    return lines;
}

// Parse fitness data from a file
void parse_fitness_data(FILE *file, FITNESS_DATA recordsArray[])
{
    // Read the file line by line
    int buffer_size = 100;
    char buffer[buffer_size];
    int line = 0;
    while (fgets(buffer, buffer_size, file) != NULL)
    {
        // Tokanise the current line  and store in the array
        char steps[10];
        tokeniseRecord(buffer, ",", recordsArray[line].date, recordsArray[line].time, steps);
        recordsArray[line].steps = atoi(steps);

        // Debugging:
        // printf("Current Record: %s", buffer);
        // printf("Date: %s | Time: %s | Steps: %d\n\n", recordsArray[line].date, recordsArray[line].time, recordsArray[line].steps);

        line++;
    }
}

// Complete the main function
int main()
{
    // Open the file and get the number of records
    FILE *fitnessDataFile = open_file(SOURCE_FILENAME, "r");
    int records = number_of_lines(fitnessDataFile);
    fclose(fitnessDataFile);

    // Create an array and store the fitness records
    FITNESS_DATA fitnessRecords[records];
    fitnessDataFile = open_file(SOURCE_FILENAME, "r");
    parse_fitness_data(fitnessDataFile, fitnessRecords);
    fclose(fitnessDataFile);

    // Output required data
    printf("Number of records in file: %d\n", records);
    for (int i = 0; i < 3; i++)
    {
        FITNESS_DATA outData = fitnessRecords[i];
        printf("%s/%s/%d\n", outData.date, outData.time, outData.steps);
    }

    return 0;
}