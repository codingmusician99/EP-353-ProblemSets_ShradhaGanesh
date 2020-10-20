// The purpose of this program is to take in a string from the user and reverse it  
#include <stdio.h>
int main(){
    char string1[10]; 
    char string2[10]; 
    printf("Enter a string: ");
    scanf("%s", string1); 
    printf("%s\n", string1); 
    for (int i = 0; i <= 9; i++){
        char *str2 = string1 + 9; 
        str2 -= i;
        printf("%c", *str2); 


        } 
    return 0; 
}
   
    

   
    

