#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "staff_operations.h"










// This function adds a staff profile.
void add_staff_profile() {

    printf("\n\n"); // To add a stlying.


    char x; 
    int n;// This variable is use to calculate the ascii value of [Yes & No].

    // Open file in append mode
    FILE *file = fopen("database/staff_data.csv", "a+");
    if (file == NULL) {
        printf("404 Error opening file!\n");
        return;  // Exit function if file opening fails
    }

    char staff_name[100];
    char staff_position[100];
    char staff_department_name[100];
    char staff_school_name[100];
    char staff_id[100];


    Again:
    // Take input from the user
    printf("Enter The Staff Name: ");
    scanf(" %[^\n]", staff_name);
    getchar();  // Consume newline

    printf("Enter The Staff ID: ");
    scanf(" %[^\n]", staff_id);
    getchar();  // Consume newline

    printf("Enter His/Her Position: ");
    scanf(" %[^\n]", staff_position);
    getchar();  // Consume newline

    printf("Enter The Department Name: ");
    scanf(" %[^\n]", staff_department_name);
    getchar();  // Consume newline

    printf("Enter The School Name: ");
    scanf(" %[^\n]", staff_school_name);
    getchar();  // Consume newline

    // Write to CSV file
    fprintf(file, "%s,%s,%s,%s,%s\n", staff_name, staff_position,
            staff_department_name, staff_school_name, staff_id);


        fflush(file);  // Force the data to be written immediately.


    printf("\n");
    printf("Staff Added Successfully! (Record saved in database)\n"); // This is the messege after recording the informations.
    printf("\n");
    
    // Close file
    fclose(file);


    printf("Press [Y/N] to add more Profile or Stop Here: "); // Here we take option from user that he want to countiniue or not.
    scanf(" %c", &x);

    n = (int) x; //here we typecast the char value from int value.

    if (n == 121 || n == 89)
    {
        goto Again;
    }else if (n == 78 || n == 110)
    {
        main();
    }
}











// Function to delete a staff profile
void delete_staff_profile() {


    printf("\n\n"); //Just adding some basic styling
    // Implementation needed
}











// Function to search for a particular staff profile
void search_staff_profile() {


    printf("\n\n"); //Just adding some basic styling
    // Implementation needed
}











// Function to show all staff profiles
void show_all_staff_profile() {


    printf("\n\n"); //Just adding some basic styling.

    char x; 
    int n;// This variable is use to calculate the ascii value of [Yes & No].   

    FILE *file = fopen("database/staff_data.csv", "r"); // Open the file in read mode
    if (file == NULL) {
        printf("Error: Unable to open the database file.\n");
        return;
    }

    char line[256]; // Buffer to store each line from the file
    printf("-------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-15s | %-15s | %-8s \n", 
            "STAFF NAME", "DESIGNATION", "DEPARTMENT", "SCHOOL NAME", "STAFF ID");
    printf("-------------------------------------------------------------------------------------------\n");
    int count = 0; // To check if there are records
    while (fgets(line, sizeof(line), file)) {
        char staff_name[100], staff_id[100], staff_position[100], staff_department[100], staff_school[100];

        // Extract values from CSV format
        if (sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", staff_name, staff_position, staff_department, staff_school, staff_id) == 5) {
            printf("| %-20s | %-15s | %-15s | %-15s | %-8s  \n", staff_name, staff_position, staff_department, staff_school, staff_id);
            count++;
        }
    }

    fclose(file); // Close the file


    printf("\n");
    printf("Press [Y] for go to Main Menu: "); // Here we take option from user that he want to countiniue or not.
    scanf(" %c", &x);

    n = (int) x; //here we typecast the char value from int value.

    if (n == 121 || n == 89)
    {
        main();
    }

    
}
