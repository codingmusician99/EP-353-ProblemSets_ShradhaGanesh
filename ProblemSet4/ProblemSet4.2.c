/* The purpose of this program is to declare, define and use a 'sumup' function 
which would take a variable 'number' and find the sum of all the numbers leading 
up to it, including the 'number' value itself. */
#include <stdio.h>
// declaring sumup function // 
int sumup(int number);

// defining sumup function // 
int sumup(int number){
    return number * (number + 1)/2;
}

// calling sumup fuction // 
int main(){
    int number;
    printf("Type in an integer value: ");
    scanf("%d", &number);
    printf("Sumup of %d is %d\n", number, sumup(number));
    return 0;
}