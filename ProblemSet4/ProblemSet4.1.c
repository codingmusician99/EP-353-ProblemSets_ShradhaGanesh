/* The purpose of this program was to rewrite the text from a .txt file into another .txt file through C program
however, the uppercase letters need to be lowercase and lowercase letters need to be uppercase */
#include <stdio.h>
int main(){
    FILE * textfile; //first .txt file//
    FILE * othertextfile; //.txt being written on by C program// 

    textfile = fopen("LoremIpsum.txt", "r");
    othertextfile = fopen("l0REMiPSUM.txt", "w");

    if(textfile == NULL){
        printf("This file cannot be opened or it does not exist!");
        return 1;
    }
    if(othertextfile == NULL){
        printf("This file cannot be opened or it does not exist!");
        return 1;
    }
    int c; 
    while((c = fgetc(textfile)) != EOF){
        if(c >= 'A' && c <= 'Z'){
            c = c - 'A' + 'a';
            fputc(c, othertextfile);
        }
        if(c >= 'a' && c <= 'z'){
            c = c - 'a' + 'A';
            fputc(c, othertextfile);
        }
    }
         fclose(textfile);
         fclose(othertextfile);
         return 0;
    }
   
    
    

    
    
    

   

