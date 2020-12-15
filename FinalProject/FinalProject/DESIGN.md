# EP-353 Final Project

### Melodizer -> Design Document

### Created by: Shradha Ganesh

## Summary of the program

Melodizer is a program that is designed to create a melody based on the user's input. The user is prompted to input 16 integer values between 0 and 127 and they correspond to MIDI note numbers. The program then converts these MIDI Notes into frequency values and computes a waveform to effectively print out the user input values as musical notes. 

## Design of Melodizer

The Melodizer program essentially needs to compute a waveform, print information into a sound file, convert MIDI Note values to frequency values and needs to allocate memory space in order to effective store information. Therefore, the libraries `<math.h>`, `<memory.h>`, `<stdlib.h>`, `<string.h>` and `<sndfile.h>` are used in addition to the standard library `<stdio.h>`. 

Parameters of the resulting sound file are established as constants in the beginning of the program. Sample Rate is defined to be 44100 Hz, the duration of the sound file is 5 seconds, the sound file is defined as mono and the format is specified to be .wav. The number of frames are also defined to be duration of sound file * sample rate. All of these parameters are made to correspond to the resulting sound file's parameters once the SNDFILE struct from `<sndfile.h>` is open. 

The duration of the sound file is made to be 5 seconds because the program asks for 16 integer inputs(notes) and with a 5 second sound file, each note's duration ends up being that of an 8th note. This makes each note fast enough to not bore the user but also is slow enough to fully comprehend what the notes are. The resulting sound file is named "Melody.wav". 

The program initially greets the user, giving them a very short brief of the program and instructs them to enter an integer value between 0 and 127. Before the user is enabled to input their value however, the program suggests that the values they enter will correspond to MIDI Note numbers and that numbers 60 to 72 all correspond to the C3-C4 octave. This is in attempt to inform the viewer of a ball park of the octave they may most likely want a lot of their notes to be in. But again, this is not enforced and the user can input any integer value they want as long as it is in the range of 0 and 127. There are error checks in the program which will ensure that the values are within that range. 

Once the user inputs an integer value, the program immediately converts the value to a frequency value using the formula to convert MIDI note numbers to frequency. In order to do this however, the variable that holds the MIDI note value is typecasted to a double from an integer data type in the formula computation. This is because MIDI note numbers are integers, however, frequencies can very well be decimal values with more than one decimal places. Once this conversion is done, the frequency is stored in an array, with a double data type, called Notes. This array is made to have 16 elements as the user will be prompted to input 16 integer values. 

Before any of this, the SNDFILE struct elements are initialized including a buffer pointer with a double data type. This is to both initialize the sound file and also to effectively allocate memory space when writing the information in the file. Once the array is filled with frequency elements, the buffer is allocated memory space the same number of elements as the number of frames * number of channels so that it covers the entire sound file parameters. The size of each element is made to be 'double'. Calloc is used for this memory allocation as it automatically initializes the memory space with 0s. 

The sndfile, named as melodyfile, is now opened with `sf_open`. The file name, as defined earlier in the program is "Melody.wav" and the corresponding parameters of the sound file(sample rate etc.) are all stored in the info of the sndfile and are written into this melodyfile. An error check is also there to ensure that the file has opened effectively. Once this is done, the waveform computation happens. 

Using `sf_count_t`, a variable called duration is defined to be the number of frames * channels / 16. This is to make each note have equal space when writing the samples into the sound file. Then, a for loop is established to run as long as the number of elements in the notes array so that the waveform computation happens as many times as the elements in the array. Here, a variable 'sample' with data type double is defined. In addition to that, a second array with double data type called 'Amplitude' is also established with 16 elements. This is to have different amplitudes for each of the user's notes. This is in attempt to give the resulting melody some dynamic change. 

Finally, using the sample variable, a square wave with 180 harmonics is computed in the program. This is to not just have a standard square wave timbre but also make it a little more interesting with a lot of harmonics. In the square wave computation, for both amplitude and frequency, each element of the array is recalled, thus having the waveform be affected by the frequency and amplitude changes. All of this is written into the buffer which is finally written into the actual sound file. 

An error check is also written to once again check if the samples have been written properly into the sound file. Once this is properly accomplished, the program closes the sound file and frees the buffer memory space. To compile this program, you would need to use:

`clang FinalProjectMelodizer.c -lsndfile - o FinalProjectMelodizer`

To run the program, you would need to use: 

`./FinalProjectMelodizer`

Including the `-lsndfile` command is essential because the program uses the sndfile third party plugin which will not be recognized unless specified. Once the program has successfully run, you should have a melody.wav file in your computer with your custom made melody! 

## Scope for Improvements

Unfortunately, this program does not currently support having a variety of durations for each note. This means the rhythm of the melody will always be a series of 8th notes, or 16th notes, or Quarter notes(this can be changed if the duration of the sound file is changed). It can never be a combination of note values. Perhaps, in the future, another version of the program could be made to support that. 

In addition to that, another possible improvement would be to add Digital Audio Effects(DAFx) such as Delay, Distortion, Reverb etc. to the resulting melody. Another improvement would be to include an envelope generator which could further manipulate the sound generation. 

