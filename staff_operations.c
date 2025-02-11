#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "staff_operations.h"

// This function adds a staff profile.
void add_staff_profile()
{

    printf("\n\n"); // To add a stlying.

    char x;
    int n; // This variable is use to calculate the ascii value of [Yes & No].

    // Open file in append mode
    FILE *file = fopen("database/staff_data.csv", "a+");
    if (file == NULL)
    {
        printf("404 Error opening file!\n");
        return; // Exit function if file opening fails
    }

    char staff_name[50];
    char staff_position[50];
    char staff_department_name[50];
    char staff_school_name[50];
    char staff_id[50];

Again:
    // Take input from the user
    printf("Enter The Staff Name: ");
    scanf(" %[^\n]", staff_name);
    getchar(); // Consume newline

    printf("Enter The Staff ID: ");
    scanf(" %[^\n]", staff_id);
    getchar(); // Consume newline

    printf("Enter His/Her Position: ");
    scanf(" %[^\n]", staff_position);
    getchar(); // Consume newline

    printf("Enter The Department Name: ");
    scanf(" %[^\n]", staff_department_name);
    getchar(); // Consume newline

    printf("Enter The School Name: ");
    scanf(" %[^\n]", staff_school_name);
    getchar(); // Consume newline

    // Write to CSV file
    fprintf(file, "%s,%s,%s,%s,%s\n", staff_name, staff_position,
            staff_department_name, staff_school_name, staff_id);

    fflush(file); // Force the data to be written immediately.

    printf("\n");
    printf("Staff Added Successfully! (Record saved in database)\n"); // This is the messege after recording the informations.
    printf("\n");

    // Close file
    fclose(file);

    printf("Press [Y/N] to add more Profile or Stop Here: "); // Here we take option from user that he want to countiniue or not.
    scanf(" %c", &x);

    n = (int)x; // here we typecast the char value from int value.

    if (n == 121 || n == 89)
    {
        goto Again;
    }
    else if (n == 78 || n == 110)
    {
        main();
    }
}

// Function to delete a staff profile
void delete_staff_profile()
{

    printf("\n\n"); // Just adding some basic styling.

    char id[50], staff_name[50], staff_id[50], staff_position[50], staff_department[50], staff_school[50];
    char x;
    int found = 0;
    int n;

    printf("Enter The Staff ID to Delete: ");
    scanf("%s", id);

    FILE *file = fopen("database/staff_data.csv", "r"); // Open original file in read mode
    if (file == NULL)
    {
        printf("Error: Unable to open database file.\n");
        return;
    }

    FILE *temp = fopen("database/temp.csv", "w"); // Open temp file in write mode
    if (temp == NULL)
    {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    char line[500];

    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Extract staff details from line
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", staff_name, staff_position, staff_department, staff_school, staff_id);

        // If ID matches, do NOT write this line (skip deletion)
        if (strcmp(id, staff_id) == 0)
        {
            found = 1;
            continue;
        }
        fprintf(temp, "%s", line); // Write all other records to temp file
    }

    fclose(file);
    fclose(temp);

    // Remove old file & rename temp file as original file
    if (found)
    {
        remove("database/staff_data.csv");
        rename("database/temp.csv", "database/staff_data.csv");
        printf("Staff ID %s deleted successfully!\n", id);
    }
    else
    {
        remove("database/temp.csv"); // Delete temp file if no match found
        printf("Staff ID not found!\n");
    }

    printf("\n");
    printf("Press [Y] for go to Main Menu: "); // Here we take option from user that he want to countiniue or not.
    scanf(" %c", &x);

    n = (int)x; // here we typecast the char value from int value.

    if (n == 121 || n == 89)
    {
        main();
    }

    printf("\n\n"); // Just adding some basic styling
}

// Function to search for a particular staff profile
void search_staff_profile()
{

    printf("\n\n"); // Just adding some basic styling.

    char x;
    int n;
    char id[50];
    char staff_name[50], staff_id[50], staff_position[50], staff_department[50], staff_school[50];

    printf("Enter The Staff ID: ");
    scanf("%s", id); // Taking ID as input

    FILE *file = fopen("database/staff_data.csv", "r"); // Open file in read mode
    if (file == NULL)
    {
        printf("Error: Unable to open the database file.\n");
        return;
    }

    char line[500]; // Buffer to store each line
    int found = 0;  // Flag to check if record is found

    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Extracting data from the line
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", staff_name, staff_position, staff_department, staff_school, staff_id);

        if (strcmp(id, staff_id) == 0)
        { // Compare user input with file data
            printf("\nStaff Found!\n");
            printf("-------------------------------------------------------------------------------\n");
            printf("| %-20s | %-15s | %-10s | %-10s | %-8s |\n",
                   "STAFF NAME", "DESIGNATION", "DEPARTMENT", "SCHOOL", "STAFF ID");
            printf("-------------------------------------------------------------------------------\n");
            printf("| %-20s | %-15s | %-10s | %-10s | %-8s |\n",
                   staff_name, staff_position, staff_department, staff_school, staff_id);
            found = 1;
            break; // Stop searching after finding the record
        }
    }

    if (!found)
    {
        printf("\nStaff ID not found!\n");
    }

    fclose(file); // Close file

    printf("\n");
    printf("Press [Y] for go to Main Menu: "); // Here we take option from user that he want to countiniue or not.
    scanf(" %c", &x);

    n = (int)x; // here we typecast the char value from int value.

    if (n == 121 || n == 89)
    {
        main();
    }
    printf("\n\n"); // Just adding some basic styling
}

// Function to show all staff profiles
void show_all_staff_profile()
{

    printf("\n\n"); // Just adding some basic styling.

    char x;
    int n; // This variable is use to calculate the ascii value of [Yes & No].

    FILE *file = fopen("database/staff_data.csv", "r"); // Open the file in read mode
    if (file == NULL)
    {
        printf("Error: Unable to open the database file.\n");
        return;
    }

    char line[5000]; // Buffer to store each line from the file
    printf("-------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-15s | %-15s | %-8s \n",
           "STAFF NAME", "DESIGNATION", "DEPARTMENT", "SCHOOL NAME", "STAFF ID");
    printf("-------------------------------------------------------------------------------------------\n");
    int count = 0; // To check if there are records
    while (fgets(line, sizeof(line), file))
    {
        char staff_name[50], staff_id[50], staff_position[50], staff_department[50], staff_school[50];

        // Extract values from CSV format
        if (sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", staff_name, staff_position, staff_department, staff_school, staff_id) == 5)
        {
            printf("| %-20s | %-15s | %-15s | %-15s | %-8s  \n", staff_name, staff_position, staff_department, staff_school, staff_id);
            count++;
        }
    }

    fclose(file); // Close the file

    printf("\n");
    printf("Press [Y] for go to Main Menu: "); // Here we take option from user that he want to countiniue or not.
    scanf(" %c", &x);

    n = (int)x; // here we typecast the char value from int value.

    if (n == 121 || n == 89)
    {
        main();
    }
}
