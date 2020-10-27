/* The purpose of this program is to user input of long integers, put them in an array and 
compute its average! */ 

#include <stdio.h>
#include <stdlib.h>

int main(){
    long integer; 
    int arraysize = 0; 
    int *array = malloc(arraysize * sizeof(int));
    int ArrayAverage = 0; 
    
    while (integer != 0){
        printf("Please enter an integer: "); 
        scanf("%ld", &integer); 
        array = realloc(array, arraysize*sizeof(long)); 

        // If array's size becomes larger than 100, program will break from while loop
        if (arraysize > 100){
            break; 
        }
        
        array[arraysize] = integer; 
        arraysize++; 


        
        // Check to see if malloc is working or not 
        if (array == NULL){
            printf("Malloc failed!"); 
            return 1; 
        }  
    }

    // Determines the sum of all the integer inputs 
    for (int i = 0; i < arraysize; i++){
        ArrayAverage += array[i]; 
    }

    // Divides the sum with the size of the array
    ArrayAverage = ArrayAverage/arraysize; 
    printf("The average of all the integers inputted by the user is %d\n", ArrayAverage); 
        
        
        
    free (array); 
    return 0; 
} 
