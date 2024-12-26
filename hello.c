#include <cs50.h>
#include <stdio.h>

int main(void)
{

    string name = get_string("What is your name?\n"); //Name will prompt user to input a string variable
    printf("Hello, %s\n", name); //This will print the input to the screen

}