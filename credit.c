#include <cs50.h>
#include <math.h>
#include <stdio.h>


int main()
{
    long creditCardNum = 0;

    
    do
    {
     
        creditCardNum = get_long("Number: ");//Prompt user to input credit card number until the input is a integer
       

    }
    while (creditCardNum == true);
    
    int Count = log10(creditCardNum);// Calculate the length of the credit card number minus 1
    int FirstDigit = creditCardNum / pow(10, Count);//Isolate the first digit of the credit card number
    int FirstTwoDigits = creditCardNum / 100000000000000;//Isolate the two digits of the credit card number for inputs of 16 digits 
    int FirstTwoDigits_a = creditCardNum / 10000000000000;//Isolate the two digits of the credit card number for inputs of 15 digits
    int totalCount = Count + 1;// Calculate the length of the credit card number minus 1
    int count = 0;
    int digit = 0;
    long temp_num = creditCardNum;
  
   




// Establish conditions for Visa, Master Card, and AMEX

     
    //int FirstDigit = creditCardNum / pow(10, Count);//Isolate the first digit of the credit card number
    //int FirstTwoDigits = creditCardNum / 100000000000000;//Isolate the two digits of the credit card number for inputs of 16 digits
    //int FirstTwoDigits_a = creditCardNum / 10000000000000;//Isolate the two digits of the credit card number for inputs of 15 digits
    if (FirstDigit == 4 && (totalCount >= 13 && totalCount <= 16))
    {
        printf("VISA\n");
    }
    
    
    else if ((FirstTwoDigits >= 51 && FirstTwoDigits <= 55) && totalCount == 16)
    {
        printf("MASTERCARD\n");
    }
    

    else if ((FirstTwoDigits_a == 34 || FirstTwoDigits_a == 37) && totalCount == 15)
    {
        printf("AMEX\n");
    }
      
    else
    {
        printf("INVALID\n");
    }
    
// Luhn's algorithm (checksum)

    
    while (creditCardNum > 0)
    {
        digit = creditCardNum % 10;
        count++ ;
        creditCardNum = (creditCardNum - digit) / 10;
        break ;
    }
    
    int sum_a = 0;
    int sum_b = 0;
    
   
    for (count = 0; count % 2 == 0; count++)
    {
        sum_a = sum_a + ((count % 10) * 2);

        while ((creditCardNum % 10) * 2 >= 10)
        {
            sum_a = (sum_a % 10) + 1 ;
        } 
    }
   
    for (count = 0 ; count % 2 != 0 ; count++)
    {
        sum_b = sum_b + digit ;
    }
   
    int total_sum = sum_a + sum_b ;
    

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n") ;
    }
    return 0; 
}