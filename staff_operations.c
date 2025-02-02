#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "staff_operations.h"

// This the function which which compute the operation to adding a staff profile.
void add_staff_profile(){

// Open file in append mode
    FILE *file = fopen("database/database.csv", "a+");
    if (file == NULL) {
        printf("404 Error opening file!\n");
    }

    char staff_name[100];
    char staff_position[100];
    char staff_department_name[100];
    char staff_school_name[100];
    int staff_id[100];

// Here we take the name from the user.
    printf("Enter The Staff Name: ");
    scanf("%[^\n]", staff_name);

// Here we take the ID from the user.
    printf("Enter The Staff ID: ");
    scanf("%d", staff_id);

// Here we take the position from the user.
    printf("Enter His/Her Position: ");
    scanf("%[^\n]", staff_position);

// Here we take the department name from the user.
    printf("Enter The Department Name: ");
    scanf("%[^\n]", staff_department_name);

// Here we take the school name from the user.
    printf("Enter The School Name: ");
    scanf("%[^\n]", staff_school_name);

// Write to CSV file
    fprintf(file, "%s,%s,%s,%s,%d \n", staff_name, staff_position,
    staff_department_name, staff_school_name, staff_school_name,staff_id);
    
    printf("Staff Added Successfully! (Data saved in database.csv)\n");

    fclose(file);
    // Close file


}


// This the function which which compute the operation to deleting a staff profile.
void delete_staff_profile(){

}


// This the function which which compute the operation to search a partclar staff profile.
void search_staff_profile(){

}


// This the function which which compute the operation to show the overall dataset of staff profiles.
void show_all_staff_profile(){

}