/* The purpose of this program is to take in commandline arguments of a string and an integer and find out
the last few characters of the string, depending on the integer value given */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Input a string and an integer number as command-line arguments to run this program\n");
        return 1;
    }

   for (int j = 0; j < atoi(argv[2]); j++){
       int k = strlen(argv[1]) - 1 - j;
       
       printf("The last %d characters of %s is %c\n",atoi(argv[2]), argv[1], argv[1][k]);
   }


return 0; 
    }
       

    
