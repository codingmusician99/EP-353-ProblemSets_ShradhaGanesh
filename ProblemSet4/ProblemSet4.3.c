/* The purpose of this program is to explore variable scope by creating functions with 
global, static and local variables and incrementing them and printing out their results
in an orderly manner */
#include <stdio.h>
// global variable // 
int global = 0;

// static and local variables in the voic increment function // 
void increment(){
    static int sint = 0;
    int local = 0;
    printf(" %d\t|  %d\t|  %d\n", local, sint, global);
    sint +=1;
    local +=1;
    global +=1;
    
    
}
// implementation of the variables in the main function // 
int main(){
    printf("local\t| sint\t| global\n");
    printf("------------------------\n");
    increment();
    increment();
    increment();
    increment();
    increment();
    increment();
    increment();
    increment();
    increment();
    increment();
    return 0;
}
