#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char SOURCE_FILENAME[100] = "FitnessData_2023.csv";
FILE *dataFile;
int size;

// Source: https://stackoverflow.com/questions/31298732/rounding-float-to-nearest-integer-in-c
int round_near(float b)
{
    if ((b - (int)b) < 0.5)
        return (int)b;
    else
        return (int)b + 1;
}

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

void open_file(char mode[])
{
    FILE *file = fopen(SOURCE_FILENAME, mode);
    if (file == NULL)
    {
        printf("Error: Could not find or open the file.\n");
        exit(1);
    }
    dataFile = file;
}

// Parse fitness data from a file
void parse_fitness_data(FITNESS_DATA recordsArray[])
{
    // Read the file line by line
    int buffer_size = 100;
    char buffer[buffer_size];
    int line = 0;
    while (fgets(buffer, buffer_size, dataFile) != NULL)
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

// Get number of lines
int number_of_lines()
{
    // Read the file line by line and increment lines count after each line
    int buffer_size = 100;
    char buffer[buffer_size];
    int lines = 0;
    while (fgets(buffer, buffer_size, dataFile) != NULL)
    {
        lines++;
    }
    return lines;
}

// Print record with largest steps
void largest_steps()
{
    open_file("r");
    size = number_of_lines();
    rewind(dataFile);
    FITNESS_DATA records[size];
    parse_fitness_data(records);
    fclose(dataFile);

    FITNESS_DATA largest = {"", "", -10};
    for (int i = 0; i < size; i++)
    {
        if (records[i].steps > largest.steps)
        {
            largest = records[i];
        }
    }

    printf("Largest steps: %s %s\n", largest.date, largest.time);
}

// Print record with smallest steps
void smallest_steps()
{
    open_file("r");
    size = number_of_lines();
    rewind(dataFile);
    FITNESS_DATA records[size];
    parse_fitness_data(records);
    fclose(dataFile);

    FITNESS_DATA smallest = {"", "", 10000};
    for (int i = 0; i < size; i++)
    {
        if (records[i].steps < smallest.steps)
        {
            smallest = records[i];
        }
    }

    printf("Fewest steps: %s %s\n", smallest.date, smallest.time);
}

void mean_steps()
{
    open_file("r");
    size = number_of_lines();
    rewind(dataFile);
    FITNESS_DATA records[size];
    parse_fitness_data(records);
    fclose(dataFile);

    float step_sum = 0;
    for (int i = 0; i < size; i++)
    {
        step_sum += records[i].steps;
    }
    float mean = step_sum / size;
    // mean = 11.9;
    int output = round_near(mean);

    printf("Mean step count: %d\n", output);
}

void longest_period()
{
    open_file("r");
    size = number_of_lines();
    rewind(dataFile);
    FITNESS_DATA records[size];
    parse_fitness_data(records);
    fclose(dataFile);

    int current_start = 0;
    int current_length = 0;
    int currently_over_500 = 0;

    int longest_start = 0;
    int longest_length = 0;

    // printf("Size: %d\n", size); // DEBUG

    for (int i = 0; i < size; i++)
    {
        // printf("Steps: %d\n", records[i].steps); // DEBUG
        // Record has over 500 steps
        if (records[i].steps > 500)
        {
            // Currently in a period of over 500
            if (currently_over_500 == 1)
            {
                current_length++;
                // printf("Streak is %d\n", current_length);
            }
            // Start a new period of over 500
            else
            {
                // printf("Starting new period of 500 at: %s %s\n", records[i].date, records[i].time); // Debug
                current_start = i;
                current_length = 0;
                currently_over_500 = 1;
            }
        }
        // Record has under 500 steps
        else
        {
            // Was in a period of over 500
            if (currently_over_500 == 1)
            {
                if (current_length > longest_length)
                {
                    longest_start = current_start;
                    longest_length = current_length;
                }
                current_start = 0;
                current_length = 0;
                currently_over_500 = 0;
            }
            // Was not in a period of over 500
            // DO nothing
        }
    }
    if (currently_over_500 == 1)
    {
        if (current_length > longest_length)
        {
            longest_start = current_start;
            longest_length = current_length;
        }
        current_start = 0;
        current_length = 0;
        currently_over_500 = 0;
    }
    // longest_length -= 1;
    printf("Longest period start: %s %s\n", records[longest_start].date, records[longest_start].time);
    printf("Longest period end: %s %s\n", records[longest_start + longest_length].date, records[longest_start + longest_length].time);
}

void display_menu()
{
    printf("Menu Options:\n"
           "A: Specify the filename to be imported\n"
           "B: Display the total number of records in the file\n"
           "C: Find the date and time of the timeslot with the fewest steps\n"
           "D: Find the date and time of the timeslot with the largest number of steps\n"
           "E: Find the mean step count of all the records in the file\n"
           "F: Find the longest continuous period where the step count is above 500 steps\n"
           "Q: Quit\n"
           "Enter choice: ");

    char choice[100];
    scanf("%s", choice);
    switch (choice[0])
    {
    case 'A':
        printf("Input filename: ");
        scanf("%s", SOURCE_FILENAME);
        open_file("r");
        fclose(dataFile);
        printf("File successfully loaded.\n");
        break;
    case 'B':
        open_file("r");
        size = number_of_lines();
        fclose(dataFile);
        printf("Total records: %d\n", size);
        break;
    case 'C':
        smallest_steps();
        break;
    case 'D':
        largest_steps();
        break;
    case 'E':
        mean_steps();
        break;
    case 'F':
        longest_period();
        break;
    case 'Q':
        exit(0);
    default:
        printf("Invalid choice. Try again.\n");
        break;
    }
    display_menu();
}

// Complete the main function
int main()
{
    display_menu();
}
