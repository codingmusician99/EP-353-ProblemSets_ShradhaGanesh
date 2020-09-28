/* This program is designed to output the amplitude value of a 
loudness decibel level */
#include <stdio.h>
#include <math.h>
int main(){
    char loudness;
    float amp;
    loudness = -85;
    amp = pow(10,loudness/20);
    printf("The loudness of -85 has an amplitutde of %f.\n",amp); 
} 