// The purpose of this program is to generate a 1 second 10% Pulse Wave with the specific 32 Harmonics
// To compile this program, use: clang ProblemSet9.2.c -lsndfile -o ProblemSet9.2
// To run this program, use: ./ProblemSet9.2 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

// Defining constant variables
#define SampleRate 44100
#define Second 1 
#define NumFrames SampleRate * Second
#define Channels 2
#define Format (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define FileName "pulse.wav"


int main(){
    SNDFILE *sndfile; 
    SF_INFO sfInfo; 
    double *buffer; 

    double Amplitude = 0.25f; 
    double Frequency = 440.0; 
    double Harmonics[32] = {1.00, 0.95, 0.87, 0.77, 0.65, 0.51, 0.37, 0.23, 0.11, 0.00, 0.09, 0.16, 0.20, 0.22, 0.21, 0.19, 0.15, 0.10, 0.05, 0.00, 0.04, 0.08, 0.11, 0.13, 0.13, 0.11, 0.09, 0.06, 0.03, 0.00, 0.03, 0.06}; 

    buffer = calloc(NumFrames * Channels, sizeof(double)); 

    if (!buffer){
        printf("No buffer please!\n"); 
        return 1; 
    } // Buffer Check

    memset(&sfInfo, 0, sizeof(SF_INFO)); 
    sfInfo.samplerate = SampleRate; 
    sfInfo.format = Format; 
    sfInfo.channels = Channels; 
    sfInfo.frames = NumFrames; 

    sndfile = sf_open(FileName, SFM_WRITE, &sfInfo); 

    if(!sndfile){
        printf("Cannot open file!\n"); 
        return 1; 
    } // Check if file opens or not 

    for (int t = 0; t < NumFrames; t++){
        for(int h = 1; h <= 32; h++){
            if ((Harmonics[h]) * Frequency < SampleRate/2){
                double sample = Amplitude * Harmonics[h] * sin(2.0 * M_PI * (Frequency * h/SampleRate) * t); 
                for (int c = 0; c < Channels; c++){
                    buffer[Channels * t + c] += sample; 
                }
            }

        }
        

    }

    sf_count_t count = sf_write_double(sndfile, buffer, NumFrames * Channels); 
    if (count != Channels * NumFrames){
        printf("ERROR!\n"); 
    } // Count Check

    sf_close(sndfile); 
    free(buffer); 

    return 0; 

}

