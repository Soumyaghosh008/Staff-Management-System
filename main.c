#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// This the function which which compute the operation to adding a staff profile.
int add_staff_profile(){

// Open file in append mode
    FILE *file = fopen("database/database.csv", "a+");
    if (file == NULL) {
        printf("404 Error opening file!\n");
        return 0;
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

    return 0;
}


// This the function which which compute the operation to deleting a staff profile.
int delete_staff_profile(){
    return 0;
}


// This the function which which compute the operation to search a partclar staff profile.
int search_staff_profile(){
    return 0;
}


// This the function which which compute the operation to show the overall dataset of staff profiles.
int show_all__staff_profile(){
    return 0;
}


// This is the main function which create the options for the user.
// This function also call each and every user_defined_function as per the choises.
int main(){

    int your_option;

// Here we creat the entier manue for the user, to choose the option wisely.
Try_Again: printf("Enter [1] to Add a Staff Profile \n");
printf("Enter [2] to Delete a Staff Profile \n");
printf("Enter [3] to Search a Partcular Staff Profile \n");
printf("Enter [4] to Show the Complete Dataset of Staff Profiles \n");
printf("Enter [5] to Add a Staff Profile \n");

// Here we take the option from the user.
     printf("Enter Your Option: ");
    scanf("%d", &your_option);

// Here we creat a switch condition to activate a specific operation one at a time.
// Here we also call the user_defined_functions as per the choises.
switch (your_option)
{

// Here we calling the function which add a staff profile.
case 1:
    add_staff_profile();
    break;

// Here we calling the function which delete a staff profile.
    case 2:
    delete_staff_profile();
    break;

// Here we calling the function which search a specific staff profile.
    case 3:
    search_staff_profile();
    break;

// Here we calling the function which show the complete dataset of staff profiles.
    case 4:
    show_all__staff_profile();
    break;

default:
printf("404 ERROR. Try Again");
    break;
    goto Try_Again;
}
    return 0;
}