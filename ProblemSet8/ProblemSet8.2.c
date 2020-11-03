/* The purpose of this program is to take in existing sine.wav and tri.wav files and write them into an audio file
that plays them alternatively for 5 times */
// To compile this program use clang ProblemSet8.2.c -o ProblemSet8.2 -lsndfile
// To run this program use ./ProblemSet8.2 

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sndfile.h>

int main(void){
    SNDFILE *sinewavfile = NULL; 
    SNDFILE *triwavfile = NULL; 
    SNDFILE *sintrifile = NULL; 
    SF_INFO sintriInfo; 
    float *Buffer; 
    long BufferSize = 0; 

    memset(&sintriInfo, 0, sizeof(SF_INFO));  

    sinewavfile = sf_open("sine.wav", SFM_READ, &sintriInfo); 
    triwavfile = sf_open("tri.wav", SFM_READ, &sintriInfo); 

    if (!sinewavfile){
        printf("Error in opening this file!"); 
        return 1;
    } // checking if the sine wave file opens or not

    if (!triwavfile){
        printf("Error in opening this file!"); 
        return 1; 
    } // checking if the triangle wave file opens or not

    Buffer = (float *)malloc(sintriInfo.frames * sizeof(float)); 

    BufferSize = sintriInfo.frames; 

    sintrifile = sf_open("sintri.wav", SFM_WRITE, &sintriInfo); 

    if (!sintrifile){
        printf("Error in opening this file!"); 
        return 1; 
    } // checking if the resulting sintri file opens or not 

    for (int i = 0; i < 5; i++){
        sf_read_float(sinewavfile, Buffer, BufferSize);
        sf_write_float(sintrifile, Buffer, BufferSize); 
        sf_seek(sinewavfile, 0, SEEK_SET);  
        sf_read_float(triwavfile, Buffer, BufferSize); 
        sf_write_float(sintrifile, Buffer, BufferSize); 
        sf_seek(triwavfile, 0, SEEK_SET); 
    }

    sf_close(sinewavfile); 
    sf_close(triwavfile); 
    sf_close(sintrifile); 
    free(Buffer); 

    return 0;  
}