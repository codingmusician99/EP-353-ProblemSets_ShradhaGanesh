/* The purpose of this program is to create a struct 'Note' with its properties of pitch, velocity and channel and then
have the user input values and assign it to each of the properties of 'Note' */

#include <stdio.h>
#include <stdlib.h>
const int NOTES = 3; // constant value for sizeof in malloc
struct Note 
{
    unsigned char pitch; 
    unsigned char velocity;
    unsigned char channel;
};

typedef struct Note Note; // Type definition of struct Note to just Note. 

// Declaring printNote function
Note printNote(Note *note); 

// Defining printNote function
Note printNote(Note *note){
        printf("Please enter a value for pitch: "); 
        scanf("%hhd", &note[0].pitch); 
        printf("Please enter value for velocity: "); 
        scanf("%hhd", &note[1].velocity); 
        printf("Please enter a value for channel: "); 
        scanf("%hhd", &note[2].channel); 
        return *note; 
    }
    
// Calling printNote function 
int main(){ 
    Note *note = malloc(NOTES * sizeof(Note)); 
    printNote(note); 
    printf("The MIDI Note has:\nPitch -> %d\nVelocity -> %d\nChannel -> %d\n", note[0].pitch, note[1].velocity, note[2].channel);
    free (note); 
    return 0; 

} 
