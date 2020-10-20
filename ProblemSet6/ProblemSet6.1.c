/* The purpose of this program is to get a user input integer value and adjust it to the range of MIDI
and output it to the user */
#include <stdio.h>
#include <stdlib.h>

// Declaring adjustMIDIRange 
void adjustMIDIRange(char *midi);

// Defining adjustMIDIRange
void adjustMIDIRange(char *midi){
    if (*midi < 0){
        int c = 0; 
        midi = (char *) &c; 
        
    }
    if (*midi > 127){
        int d = 127;
        midi = (char *) &d; 

    }
} 

// Calling adjustMIDIRange
int main(){
    char MIDI; 
    printf("Enter an integer between 0 and 127: ");
    scanf("%hhd",&MIDI);
    adjustMIDIRange(&MIDI);
    printf("The MIDI number is %d\n", MIDI); 
    return 0; 
} 
