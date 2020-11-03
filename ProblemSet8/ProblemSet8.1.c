/* The purpose of this program is to read an existing 'sine.wav' file and increase it's time duration by 
5 times and render it as a new .wav file. */
// To compile this program use clang ProblemSet8.1.c -o ProblemSet8.1 -lsndfile 
// To run this program use ./ProblemSet8.1

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sndfile.h>

int main(void){
    SNDFILE *sineFile = NULL; 
    SNDFILE *sine5File = NULL; 
    SF_INFO sineInfo; 
    float *Buffer; 
    long BufferSize = 0; 

    memset(&sineInfo, 0, sizeof(SF_INFO)); 

    sineFile = sf_open("sine.wav", SFM_READ, &sineInfo); 

    if(!sineFile){
        printf("Error in opening this file!"); 
        puts (sf_strerror(NULL)); 
        return 1; 
    }  // Checking if sine.wav is opening or not. 
   

    Buffer = (float *) malloc(sineInfo.frames * sizeof(float)); 

    BufferSize = sineInfo.frames;   

    sine5File = sf_open("sine5.wav", SFM_WRITE, &sineInfo); 

    if (!sine5File){
        printf("Error in opening this file!"); 
        puts (sf_strerror(NULL)); 
        return 1; 

    }  // Checking if sine5.wav is opening or not. 
    

    for (int i = 0; i < 5; i++){
        sf_read_float(sineFile, Buffer, BufferSize); 
        sf_write_float(sine5File, Buffer, BufferSize); 
        sf_seek(sineFile, 0, SEEK_SET); 
    }
    

    sf_close(sineFile); 
    sf_close(sine5File); 
    free(Buffer); 

    return 0; 

}