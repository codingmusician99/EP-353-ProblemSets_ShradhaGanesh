/* The purpose of this program is to take in a name and a character and figure out how many times the given 
character appears in the given name */
#include <stdio.h>

// Declaring countCharacter function // 
int countCharacter(char name[], int character);

// Defining countCharacter function // 
int countCharacter(char name[], int character){
    int count = 0; 
    for (int i = 0; name[i]; i++){
        if (name[i] == character){
            count++;
        }
    }
    return count;
}

// Calling countCharacter function in the main function // 
int main(){
    char name[30];
    printf("Enter name: ");
    scanf("%s", name);
    char character;
    int count = 0;
    printf("Enter character: ");
    scanf("%s", &character);
    count = countCharacter(name,character);
    
    printf("The string %s has %d '%c's.\n", name, count, character);
    return 0;
    }


    


