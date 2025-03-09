#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "staff_operations.h"

// Adding the structure layout for better memory management process.
struct staff_operations
{
    char staff_name[50];
    char staff_position[50];
    char staff_department_name[50];
    char staff_school_name[50];
    char staff_id[50];
    char id[50];
    char line[5000]; // Buffer to store each line from the file
};

// This function adds a staff profile.
void add_staff_profile()
{
    struct staff_operations fun_1; // in this structure the object is [info].
    printf("\n\n");                // To add a stlying.

    char x;
    int n; // This variable is use to calculate the ascii value of [Yes & No].

    // Open file in append mode
    FILE *file = fopen("database/staff_data.csv", "a+");
    if (file == NULL)
    {
        printf("404 Error opening file!\n");
        return; // Exit function if file opening fails
    }

Again:
    // Take input from the user
    printf("Enter The Staff Name: ");
    scanf(" %[^\n]", fun_1.staff_name);
    getchar(); // Consume newline

    printf("Enter The Staff ID: ");
    scanf(" %[^\n]", fun_1.staff_id);
    getchar(); // Consume newline

    printf("Enter His/Her Position: ");
    scanf(" %[^\n]", fun_1.staff_position);
    getchar(); // Consume newline

    printf("Enter The Department Name: ");
    scanf(" %[^\n]", fun_1.staff_department_name);
    getchar(); // Consume newline

    printf("Enter The School Name: ");
    scanf(" %[^\n]", fun_1.staff_school_name);
    getchar(); // Consume newline

    // Write to CSV file
    fprintf(file, "%s,%s,%s,%s,%s\n", fun_1.staff_name, fun_1.staff_position,
            fun_1.staff_department_name, fun_1.staff_school_name, fun_1.staff_id);

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
    else
    {
        printf("\n\n\n");
        printf("404 ERROR.TRY AGAIN \n");
        ;
        printf("\n\n\n");
    }
}

// Function to delete a staff profile
void delete_staff_profile()
{
    struct staff_operations fun_2;

    printf("\n\n"); // Just adding some basic styling.

    char x;
    int found = 0;
    int n;

    printf("Enter The Staff ID to Delete: ");
    scanf("%s", fun_2.id);

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

    char line[5000];

    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Extract staff details from line
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", fun_2.staff_name, fun_2.staff_position, fun_2.staff_department_name, fun_2.staff_school_name, fun_2.staff_id);

        // If ID matches, do NOT write this line (skip deletion)
        if (strcmp(fun_2.id, fun_2.staff_id) == 0)
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
        printf("Staff ID %s deleted successfully!\n", fun_2.id);
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
    else
    {
        printf("\n\n\n");
        printf("404 ERROR.TRY AGAIN \n");
        ;
        printf("\n\n\n");
    }

    printf("\n\n"); // Just adding some basic styling
}

// Function to search for a particular staff profile
void search_staff_profile()
{
    struct staff_operations fun_3;
    printf("\n\n"); // Just adding some basic styling.

    char x;
    int n;

    printf("Enter The Staff ID: ");
    scanf("%s", fun_3.id); // Taking ID as input

    FILE *file = fopen("database/staff_data.csv", "r"); // Open file in read mode
    if (file == NULL)
    {
        printf("Error: Unable to open the database file.\n");
        return;
    }

    char line[5000]; // Buffer to store each line
    int found = 0;   // Flag to check if record is found

    // Read file line by line
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Extracting data from the line
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%s", fun_3.staff_name, fun_3.staff_position, fun_3.staff_department_name, fun_3.staff_school_name, fun_3.staff_id);

        if (strcmp(fun_3.id, fun_3.staff_id) == 0)
        { // Compare user input with file data
            printf("\nStaff Found!\n");
            printf("-------------------------------------------------------------------------------\n");
            printf("| %-20s | %-15s | %-10s | %-10s | %-8s |\n",
                   "STAFF NAME", "DESIGNATION", "DEPARTMENT", "SCHOOL", "STAFF ID");
            printf("-------------------------------------------------------------------------------\n");
            printf("| %-20s | %-15s | %-10s | %-10s | %-8s |\n",
                   fun_3.staff_name, fun_3.staff_position, fun_3.staff_department_name, fun_3.staff_school_name, fun_3.staff_id);
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
    else
    {
        printf("\n\n\n");
        printf("404 ERROR.TRY AGAIN \n");
        ;
        printf("\n\n\n");
    }
    printf("\n\n"); // Just adding some basic styling
}

// Function to show all staff profiles
void show_all_staff_profile()
{
    struct staff_operations fun_4;
    printf("\n\n"); // Just adding some basic styling.

    char x;
    int n; // This variable is use to calculate the ascii value of [Yes & No].

    FILE *file = fopen("database/staff_data.csv", "r"); // Open the file in read mode
    if (file == NULL)
    {
        printf("Error: Unable to open the database file.\n");
        return;
    }

    printf("-------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-15s | %-15s | %-8s \n",
           "STAFF NAME", "DESIGNATION", "DEPARTMENT", "SCHOOL NAME", "STAFF ID");
    printf("-------------------------------------------------------------------------------------------\n");
    int count = 0; // To check if there are records
    while (fgets(fun_4.line, sizeof(fun_4.line), file))
    {
        // Extract values from CSV format
        if (sscanf(fun_4.line, "%[^,],%[^,],%[^,],%[^,],%[^,]", fun_4.staff_name, fun_4.staff_position, fun_4.staff_department_name, fun_4.staff_school_name, fun_4.staff_id) == 5)
        {
            printf("| %-20s | %-15s | %-15s | %-15s | %-8s  \n", fun_4.staff_name, fun_4.staff_position, fun_4.staff_department_name, fun_4.staff_school_name, fun_4.staff_id);
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
    else
    {
        printf("\n\n\n");
        printf("404 ERROR.TRY AGAIN \n");
        ;
        printf("\n\n\n");
    }
}
