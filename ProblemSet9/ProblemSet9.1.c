// The purpose of this program is to generate a 1 second noise wave file using the rand() function 
// To compile this program, use: clang ProblemSet9.1.c -lsndfile -o ProblemSet9.1 
// To run this program, use: ./ProblemSet9.1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h> 
#include <time.h>

// Defining constant variables 
#define SampleRate 44100
#define Second 1
#define NumFrames SampleRate * Second
#define Channels 2
#define Format (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define FileName "noise.wav"


int main(){
    SNDFILE *sndfile; 
    SF_INFO sf_info; 
    float *buffer; 
    srand (time(NULL)); 

    buffer = calloc(NumFrames * Channels, sizeof(double)); 

    if (!buffer){
        printf("No buffer please!\n"); 
        return 1; 
    } // Buffer Check


    memset(&sf_info, 0, sizeof(SF_INFO)); // Initializing memset 

    sf_info.samplerate = SampleRate; 
    sf_info.channels = Channels; 
    sf_info.frames = NumFrames; 
    sf_info.format = Format; 

    sndfile = sf_open(FileName, SFM_WRITE, &sf_info);
    if (!sndfile){
        printf("Cannot open file!\n"); 
        return 1; 
    } // Check to see if file opens or not

    for (int t = 0; t < NumFrames; t++){
        double sample = rand() % (RAND_MAX - 1); 
        for(int c = 0; c < Channels; c++){
            buffer[Channels * t + c] += sample; 
        }
        
    }

    sf_count_t count = sf_write_float(sndfile, buffer, NumFrames * Channels); 
    if (count != Channels * NumFrames){
        printf("ERROR!\n"); 
    } // Count Check 

    sf_close(sndfile);
    free(buffer); 

    return 0; 

} 