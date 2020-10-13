/* The purpose of this program is to reverse a given array and print its elements */
#include <stdio.h>
int main(){
    int numbers[]= {5, 9, 1, 2, 4, 8, 3};

    for (int i = 0; i <= 6; i++){
        int f = 6-i;
        printf("The value of arr at index %d is %d\n", i, numbers[f]);
    }

    return 0;
}