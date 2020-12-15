// Melodizer --> Create your own custom melody with C programming
// Created by: Shradha Ganesh
// EP-353 Final Project

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sndfile.h>

// Defining constants
#define kSampleRate 44100
#define kSecond 5
#define kNumFrames kSampleRate * kSecond
#define Channels 1
#define Format (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define kFileName "Melody.wav" 
#define Harmonics 180



int main(){
    SNDFILE *melodyfile = NULL; 
    SF_INFO meloInfo; 
    double *buffer; 
    double Notes[16]; // array to keep frequency values in

    // Greetings and instruction messages to the user

    printf("Hi there! Welcome to Melodizer! Where you can make your own melody!\n"); 
    printf("All you have to do is input some integer values! And we'll give you the melody!\n"); 
    printf("Hint: Keep in mind that your integer inputs will be MIDI note numbers!\n"); 
    printf("MIDI Notes 60 to 72 is the octave of C3(Middle C) to C4!\n"); 

    // Prompting user to type in integer values to store in array
    for (int i = 0; i <= 15; i++){
        printf("Please enter an integer value between 0 and 127: ");
        int n; 
        scanf("%d", &n); 
        if (n < 0){
            printf("Integer value is too low!\n"); 
            return 1; 
        } // Checking to see if user inputs high enough integer value
        if (n > 127){
            printf("Integer value is too high!\n"); 
            return 1; 
        } // Checking to see if user inputs low enough integer value
        double f = pow(2, ((double)n -69)/12) * 440; // converting MIDI note to frequency
        Notes[i] = f; 
    }


    buffer = calloc(kNumFrames * Channels, sizeof(double)); 
    if (!buffer){
        printf("No buffer please!\n"); 
        return 1; 
    } // Buffer check

    memset(&meloInfo, 0, sizeof(SF_INFO)); 

    meloInfo.samplerate = kSampleRate; 
    meloInfo.frames = kNumFrames; 
    meloInfo.channels = Channels; 
    meloInfo.format = Format; 


    melodyfile = sf_open(kFileName, SFM_WRITE, &meloInfo); 

    if(!melodyfile){
        printf("Can't open file!\n"); 
        return 1; 
    } // File open check

    // Attempt to compute waveform that would play the notes provided by user
    sf_count_t duration = (kNumFrames * Channels) / 16;
    for (int r = 0; r <= 15; r++){ 
        for (int s = 0; s < duration; s++){ 
            double sample;  
            // Array to have variety of amplitudes for each note
            double Amplitude[16] = {0.01, 0.02, 0.01, 0.02, 0.01, 0.02, 0.01, 0.01, 0.02, 0.01, 0.02, 0.01, 0.02, 0.02, 0.01, 0.01}; 
            for(int i = 1; i <= Harmonics; i+=2){ //Up to numHarmonics
                sample = (Amplitude[r])/ i * sin(2.0 * M_PI * ((Notes[r] * i)/kSampleRate) * s); 
                for (int u = 0; u < Channels; u++){
                    buffer[s + u + duration * r] += sample; 
                }
            }
        }
    }

    sf_count_t count = sf_write_double(melodyfile, buffer, meloInfo.channels * kNumFrames);

    if (count != meloInfo.channels * kNumFrames){
        printf("ERROR!\n"); 
        return 1; 
    }

    sf_close(melodyfile); 
    free(buffer); 

    return 0; 
}
