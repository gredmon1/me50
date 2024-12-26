#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string a, int b);
int count_words(string a, int b);
int count_sentences(string a, int b);
int readability(int a, int b, int c);

int main()
{
    string text = get_string("Text: "); //Prompt user to input Passage for the readability fuction

    int string_length = strlen(text); //declare the length of the string that is being input from the user
    int letters = count_letters(text, string_length); //call count_letters function
    int words = count_words(text, string_length); // call count_words function
    int sentences = count_sentences(text, string_length); //call count_sentences function
    int index = readability(letters, sentences, words); // call readability function
   
    //printf("%i letter(s)\n", letters);
    //printf("%i word(s)\n", words);
    // printf("%i sentence(s)\n", sentences);

   
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
   
    else if (index > 1 && index < 16)
    {
      
        printf("Grade %i\n", index);
    }
   
    else
    {
        printf("Grade 16+\n");
    }
   
    return 0;
}

int count_letters(string text, int string_length) //create count_letters function
{
    int count = 0;
    for (int i = 0; i < string_length; i++) //iterate through each character of the string
    {
        if (text[i] >= ' ' && text[i] <= '@')
        {
            count++;
        }
    }
    int num_of_letters = string_length - count;
      
    return num_of_letters;
}

int count_words(string text, int string_length) //create count_words function
{
    int count = 0;
    for (int i = 0; i < string_length; i++) //iterate through each character of the string
    {
        if (text[i] == ' ')
        {
            count++;
        }
      
    }
    return count + 1;
}

int count_sentences(string text, int string_length) //create count_sentences function
{
    int count = 0;
    for (int i = 0; i < string_length; i++) //iterate through each character of the string
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    } 
    return count;
}

int readability(int l, int s, int w) //create readability function
{
    float L = round(((float) l / w) * 100); 
    float S = round(((float) s / w) * 100); 
   
    float index = 0.0588 * L - 0.296 * S - 15.8; //Coleman-Liau index formula
   
    return round(index);
}