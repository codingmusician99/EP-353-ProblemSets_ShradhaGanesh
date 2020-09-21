/* Problem Set 2.2
To print out the Pitch, Velocity and Channel values of the MIDI Note */
#include <stdio.h>
int main(){
    int note = 36;
    int velocity = 89;
    int channel = 6;
    printf("This MIDI note consists of:\n\tPitch:\t\t%d\n\tVelocity:\t%d\n\tChannel:\t%d\n", note, velocity, channel);
    return 0;

}