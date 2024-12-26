#include <cs50.h>
#include <stdio.h>

int main(void){

    int height = 0;                                                         //~create an interger called height

    do{                                                                     //~do while loop

        height = get_int("Height: ");                                     //~prompts the user to input the value of height
        
    }while (height < 1 || height > 8);                                     //~validates that the value of the integer that the user inputs is between 1 and 8

    for(int i = 0; i < height; i++){                                        //~for loop that takes the value of height and prints "#" that number of times for each line

        printf("%*s", (height - i) -1, "");

        for(int row = 0; row <= i; row++){

            printf("#");
        }
        printf("\n");
    }
}