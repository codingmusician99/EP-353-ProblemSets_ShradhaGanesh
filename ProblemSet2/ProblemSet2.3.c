/* Problem Set 2.3
This program is intended to display the frequency and amplitude/decibel level 
of a Sine Tone/Sine Wave. */
#include <stdio.h>
int main(){
    float frequency = 65.406;
    float decibel = -21.8;
    printf("This sine tone has:\n\tFrequency of %4.3fHz\n\tDecibel level of %4.1fdB\n",frequency,decibel);
    return 0;
}