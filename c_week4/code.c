#include "utilities.h"

int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;

    // Read the data file into the array
    FILE *input = open_file(filename, "r");
    read_file(input, daily_readings, &counter);
    fclose(input);
    const int NUM_OF_RECORDS = counter;

    while (1)
    {
        printf("\nA: View all your blood iron levels\n");                     // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n')
            ;

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            display_records(daily_readings, NUM_OF_RECORDS);
            break;

        case 'B':
        case 'b':
            printf("\nYour average blood iron was %.2f\n", find_mean(daily_readings, NUM_OF_RECORDS));
            break;

        case 'C':
        case 'c':
            printf("\nYour lowest is %.2f!\n", find_lowest(daily_readings, NUM_OF_RECORDS));
            break;

        case 'D':
        case 'd':
            printf("\nYour highest is %.2f!\n", find_highest(daily_readings, NUM_OF_RECORDS));
            break;

        case 'E':
        case 'e':
            monthly_iron(daily_readings, NUM_OF_RECORDS);
            break;

        case 'F':
        case 'f':
            additional_stats(daily_readings, NUM_OF_RECORDS);
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}