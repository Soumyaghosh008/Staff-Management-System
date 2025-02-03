#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "staff_operations.h"
// This is the main function which create the options for the user.
// This function also call each and every user_defined_function as per the choises.
int main(){

    int your_option, try = 0;

// Here we creat the entier manue for the user, to choose the option wisely.

//Just adding some basic styling.
printf("\t\t\t\t\t #####_____Welcome To Staff Managament System_____#####\n\n\n\n\n");

Try_Again: //Address for the goto feature. 

printf("Enter [1] to Add a Staff Profile \n");
printf("Enter [2] to Delete a Staff Profile \n");
printf("Enter [3] to Search a Partcular Staff Profile \n");
printf("Enter [4] to Show the Complete Dataset of Staff Profiles \n");

// Adding some styling.
printf("\n\n\n");

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
    show_all_staff_profile();
    break;

// Here we print and compute the try_again feature.
default:
printf("\n\n\n");
printf("\t\t\t\t\t #####_____404 ERROR.TRY AGAIN_____#####\n\n\n\n\n");;

// Here we compute the calculations for the try again feature. 
// Note: This feature only works for 3 times only. After that you have to do this again from start.
try++;
if(try < 4){
    goto Try_Again;
}else{
    printf("Do it from Start");
}


}
    return 0;
}