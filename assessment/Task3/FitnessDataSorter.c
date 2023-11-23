#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <time.h>

// Define the struct for the fitness data
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FitnessData;

char filename[100];
int number_of_records = 0;
FILE *dataFile;

// Function to tokenize a record
int tokeniseRecord(const char *input, const char *delimiter,
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
    else return 1;

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }
    else return 1;

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }
    else return 1;

    // Free the duplicated string
    free(inputCopy);
    return 0;
}

FILE *open_file(char fname[], char mode[])
{
    FILE *file = fopen(fname, mode);
    if (file == NULL)
    {
        printf("Error: Could not find or open the file.\n");
        exit(1);
    }
    return file;
}

int check_file()
{
    rewind(dataFile);
    int buffer_size = 100;
    char buffer[buffer_size];
    int lines = 0;
    while (fgets(buffer, buffer_size, dataFile) != NULL)
    {
        int valid = 1;

        if (buffer[4] != '-' || buffer[7] != '-') valid = 0;
        else if (buffer[10] != ',' || buffer[16] != ',') valid = 0;
        else if (buffer[13] != ':') valid = 0;
        else if (buffer[17] == '\0' || buffer[17] == '\n') valid = 0;
        //printf("%d\n", buffer[14]);

        // char steps[10];
        // tokeniseRecord(buffer, ",", testRecord.date, testRecord.time, steps);
        // testRecord.steps = atoi(steps);

        if (! valid)
        {
            printf("Invalid data file!\n");
            exit(1);
        }
        lines++;
    }
    return lines;
}

void parse_data(FitnessData *data_array)
{
    rewind(dataFile);
    int buffer_size = 100;
    char buffer[buffer_size];
    int line = 0;
    while (fgets(buffer, buffer_size, dataFile) != NULL)
    {
        char steps[10];
        int res = tokeniseRecord(buffer, ",", data_array[line].date, data_array[line].time, steps);
        if (res != 0) {
            printf("Invalid data file!\n");
            exit(1);
        }
        data_array[line].steps = atoi(steps);

        // printf("%s %s: %d\n", data_array[line].date, data_array[line].time, data_array[line].steps);

        line++;
    }
}

void bubble_sort(FitnessData *data_array) {
    int passes = 0;
    // clock_t begin = clock();
    do {
        passes = 0;
        for (int i=0; i < number_of_records - 1; i++) {
            if (data_array[i].steps < data_array[i+1].steps) {
                FitnessData temp = data_array[i];
                data_array[i] = data_array[i+1];
                data_array[i+1] = temp;
                passes ++;
            }
        }
    }
    while (passes != 0);
    // clock_t end = clock();
    // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("Took %fs to sort!\n", time_spent);
}

void display_records(FitnessData *data_array) {
    for (int i =0; i < number_of_records; i++) {
        printf("%s-%s %d\n", data_array[i].date, data_array[i].time, data_array[i].steps);
    }
}

void save_to_tsv(FitnessData *data_array) {
    FILE *tsv_file = open_file(strcat(filename, ".tsv"), "w");

    for (int i = 0; i < number_of_records; i ++) {
        fprintf(tsv_file, "%s\t%s\t%d\n", data_array[i].date, data_array[i].time, data_array[i].steps);
    }

    fclose(tsv_file);

    printf("Data sorted and written to %s\n", filename);
}

int main()
{
    printf("Enter filename: ");
    scanf("%s", filename);
    dataFile = open_file(filename, "r");
    number_of_records = check_file();
    printf("Lines: %d\n", number_of_records);
    FitnessData data_array[number_of_records];
    parse_data(data_array);
    fclose(dataFile);

    bubble_sort(data_array);
    // display_records(data_array);
    save_to_tsv(data_array);

    return 0;
}