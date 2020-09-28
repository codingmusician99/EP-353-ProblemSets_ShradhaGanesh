/* This program is designed to assign a note to a value in the pitch classification
starting with 0 and ending with 11. However, only white keys are included in this 
program */
#include <stdio.h>
int main(){
    char note = 'G';
    int pitchClass;
    switch(note){
        case 'C':
            pitchClass = 0;
            printf("A note %c translates to %i in pitch class.\n",note,pitchClass);
            break;
        case 'D':
            pitchClass = 2;
            printf("A note %c translates to %i in pitch class.\n",note,pitchClass);
            break;
        case 'E':
            pitchClass = 4;
            printf("A note %c translates to %i in pitch class.\n",note,pitchClass);
            break;
        case 'F':
            pitchClass = 5;
            printf("A note %c translates to %i in pitch class.\n",note,pitchClass);
            break;
        case 'G':
            pitchClass = 7;
            printf("A note %c translates to %i in pitch class.\n",note,pitchClass);
            break;
        case 'A':
            pitchClass = 9;
            printf("A note %c translates to %i in pitch class.\n",note,pitchClass);
            break;
        case 'B':
            pitchClass = 11;
            printf("A note %c translates to %i in pitch class.\n",note, pitchClass);
            break;
        default:
            printf("We are only using white keys!\n");
    }
    return 0;
        
    }
