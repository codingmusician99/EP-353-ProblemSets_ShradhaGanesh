/* The purpose of this program is to set an array named numbers with a size of 8 and initialize its elements 
to an integer value given by the user */ 
#include <stdio.h>
//Declaring setArray function
void setArray(int *numbers, int value, int size);

//Defining setArray function
void setArray(int *numbers, int value, int size){
    for (int i = 0; i < size; i++){
        numbers[i] = value; 
    }

}

//Calling setArray function
int main(){
    int value;
    printf("Enter an integer: ");
    scanf("%d",&value);
    int size = 8; 
    int numbers[size];
    setArray(numbers, value, size); 
    printf("The elements in the array are:\n"); 
    for (int i = 0; i < size; i++){
        printf("%d\n", numbers[i]); 
    }
    return 0; 
    
}