#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


string cyphertext(int a, string b); 
int key;

int main(int argc, string argv[])
{
    if (argc == 2) // Check to see if user input 2 arguments
    {
        //printf("Success");
        for (int i = 0; i < strlen(argv[1]); i++) //Check each character in the input string of argv[1]
        {
            if (isdigit(argv[1][i]) == 0) // Check to see if the char is a digit, if not a digit print statment below
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

    }
    
    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    key = atoi(argv[1]); //Convert string to an int and make it equal to the key value

    if (key > 0) // Check to see if key is a positive number, if it is it continues the program
    {
           
        string plain_text = get_string("Plaintext: ");
        string cypher_text = cyphertext(key, plain_text); 
        printf("ciphertext: %s\n", cypher_text);
    }

    else // if not it replies with an error and exits the program
    {
        printf("ERROR\n");
        return 1;
    }

    return 0;
}

string cyphertext(int k, string pT) // function definition for cyphertext
{
    int string_length = strlen(pT);
    string cT = pT;

    for (int i = 0; i <= string_length; i++)
    {
        if ((pT[i] >= 'a' && pT[i] < '{'))
        {
            cT[i] = ((int) pT[i] - 97 + k) % 26 + 97;
        }

        else if ((pT[i] > '@' && pT[i] < '['))
        {
            cT[i] = ((int) pT[i] - 65 + k) % 26 + 65;
        }
        
        else if ((pT[i] > '0' && pT[i] < '9'))
        {
            cT[i] = ((int) pT[i] - 48 + k) % 10 + 48;
        }
    }
    return cT;
}

