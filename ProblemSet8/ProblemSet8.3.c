/* The purpose of this program is to take an existing audio file 'SN.wav' and render an audio file 
that reverses SN.wav */ 
// To compile this program, use clang ProblemSet8.3.c -o ProblemSet8.3 -lsndfile
// To run this program, use ./ProblemSet8.3 

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sndfile.h>

int main(){
    SNDFILE *snwavFile; 
    SNDFILE *reversesnFile; 
    SF_INFO snwavInfo; 
    float *Buffer;
    long BufferSize = 0;  

    memset(&snwavInfo, 0, sizeof(SF_INFO)); 

    snwavFile = sf_open("SN.wav", SFM_READ, &snwavInfo); 

    if(!snwavFile) return 1; // Checking if snwavFile opens or not


    reversesnFile = sf_open("ReverseSN.wav", SFM_WRITE, &snwavInfo); 

    if(!reversesnFile) return 1; // Checking if reversesnFile opens or not

    int readCount;
    float *GoodBuffer; 
    int b = 0; 
    long reverseFile = 0; 
    int i = BufferSize; 

    

    while((readCount = sf_read_float(snwavFile, Buffer, BufferSize)) > 0){
        GoodBuffer = (float *)realloc(GoodBuffer, (readCount + reverseFile) * sizeof(float));  
        while (i > 0){
            GoodBuffer[b] = Buffer[i]; 
            b++; 
            i--; 
        } 
        
       reverseFile += readCount; 

   }

    sf_write_float(reversesnFile, GoodBuffer, reverseFile); 
    sf_close(snwavFile); 
    sf_close(reversesnFile);

    return 0; 
} 