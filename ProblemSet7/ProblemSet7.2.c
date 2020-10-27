/* The purpose of this program is to take a string input using malloc, copy it into a function and return the copy
of the string */ 
#include <stdio.h>
#include <stdlib.h>
// Declaring copyString function 
char *copyString(char *string); 

//Defining copyString function
char *copyString(char *string){
    scanf("%[^\n]", string); // I am using %[^\n] so that scanf accounts for spaces in the string as well
    return string; 

}

// Calling copyString function
int main(){
    char *line = malloc(50 * sizeof(char)); 
    printf("Enter a string: ");
    copyString(line); 
    printf("%s\n", line); 
    free (line); 
    return 0; 

}