/* This program is designed to print out all the musical notes
in an octave in an ascending scale */
#include <stdio.h>
#include <stdbool.h>
int main(){
    int note = 0;
    for (note = 0; note <= 11; note++){
        switch(note){
            case 0:
                note = 0;
                printf("C ");
                break;
            case 1:
                note = 1;
                printf("Db ");
                break;
            case 2:
                note = 2;
                printf("D ");
                break;
            case 3:
                note = 3;
                printf("Eb ");
                break;
            case 4:
                note = 4;
                printf("E ");
                break;
            case 5:
                note = 5;
                printf("F ");
                break;
            case 6:
                note = 6;
                printf("Gb ");
                break;
            case 7:
                note = 7;
                printf("G ");
                break;
            case 8:
                note = 8;
                printf("Ab ");
                break;
            case 9:
                note = 9;
                printf("A ");
                break;
            case 10:
                note = 10;
                printf("Bb ");
                break;
            case 11:
                note = 11;
                printf("B\n");
                break;

        
        }
    }
  return 0;  
}