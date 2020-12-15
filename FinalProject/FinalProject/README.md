# EP-353 Final Project

### Melodizer - Make Custom made melodies

### Created by: Shradha Ganesh

## What is Melodizer?
Melodizer is a program, written in C, where the user is enabled to input 16 integer numbers which the program then turns into musical notes and prints out a sound file with the user input notes. 

## Details of the program
Melodizer can be considered a very primitive form of algorithmic music. This program takes in 16 integer inputs from the user between 0 and 127. This is because, the program is designed to treat these integer values as MIDI note numbers. There are error checks in the program to ensure that the user input is an integer value between 0 and 127. If the user's input does not meet the conditions, a message saying "integer is too high" or "integer is too low" appears and the user will have to compile and run the code again. 

Before inputting integer values, the user sees greeting print messages as well as messages that further suggest to the user that the value they enter corresponds to a MIDI Note number. As a starting point, the program mentions that MIDI notes 60 to 72 correspond to the octave of C3-C4, hopefully encouraging the user to pick values within that range. However, the user is absolutely allowed to pick a value at their discretion as long as it falls within the range of 0 to 127. 

The program asks for an integer input from the user 16 times. This is with regards to treating 16 notes as 4 bars of 4/4 where each note is an 8th note. Once the user has successfully entered 16 note number values, the program computes a formula that converts the MIDI note values to Frequency values. The resulting frequency values are stored in an array called 'Notes'. A buffer is created by the program in order to preserve the resulting values. A sound file is also opened and initialized by the program in order to print out sonic information based on the inputs of the user. The SNDFILE struct is used to open this sound file. 

The program again has error checks to see if the sound file has successfully opened. In the beginning of the program, there are some constant variables that are defined. These are kSampleRate, kSecond, KNumFrames(which is kSampleRate * kSecond), Channels, Format, FileName and Harmonics. kSampleRate, kNumFrames, Channels and Format as made to correspond to the file info's parameters of samplerate, frames, channels and format. When defining the name of the resulting sound file, the constant variable FileName is used. 

The program then implements the algorithm for generating the waveform which will play the user input frequencies and print them into the sound file. In this algorithm, the program further implements another array with 16 floating point(double) values. These correspond to amplitudes for each of the resulting frequencies. This is in order to give some dynamic over the resulting melody. The program uses the waveform algorithm of a square wave with 180 harmonics. This is in attempt to give the resulting melody a unique timbre. The resulting sonic information is then written into the opened sound file and finally, the program closes the file and frees the buffer's memory space. 

The resulting sound file is made to be 5 seconds as the duration of the notes end up being 8th notes. This would be at a slow enough speed to comprehend and fast enough to not make you feel bored. This program is unfortunately not designed to have a variety of durations for each note. Each note will have equal duration in the resulting sound file. That depends on the duration of the sound file. The program enforces a 5 second sound file. 

The intention of this program is to perhaps be a starting point to users to create their own original melody by giving them a computer generated customize melody. This is also a stepping stone into further created music out of computer generated algorithms. 

## Build and Run Commands

In order to compile this program, you will have to use the bash command:

`clang FinalProjectMelodizer.c -lsndfile -o FinalProjectMelodizer`

In order to run this program, you will have to use the bash command: 

`./FinalProjectMelodizer`





