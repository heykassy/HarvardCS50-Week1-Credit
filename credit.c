#include <cs50.h>
#include <stdio.h>

int main(void)
{

    //Prompt for input
    long ccnumber = get_long("Credit card number: ");
    if (ccnumber < 3000000000000)
    {
        printf("INVALID\n");
        return 0;
    }


    // Getting the digits sorted in an array from right to left
    int digits[16];
    digits [0] = ccnumber % 10;
    long count = 10;
    long count2 = 1;

    for (int i = 0; i < 16; i++)
    {
        digits [i] = ccnumber % count / count2;
        count *= 10;
        count2 *= 10;
    }


    // Multiply by 2 every other number starting from the second-to-last and add up the numbers
    int checksum = 0;
    for (int i = 1; i < 17; i = i + 2)
    {
        int multiply = digits[i] * 2;
        checksum = checksum + (multiply % 10) + ((multiply % 100) / 10);
    }


    // Adding the ones that were not multiplied
    for (int i = 0; i < 16; i = i + 2)
    {
        checksum = checksum + digits[i];
    }


    // Check if the last digit of checksum is zero and find credit card brand
    if (checksum % 10 == 0)
    {
        if (digits[15] == 4 || (digits[12] == 4 && digits[13] == 0 && digits[14] == 0 && digits[15] == 0))
        {
            printf("VISA\n");
        }
        else if (digits[15] == 5 && digits[14] >= 1 && digits[14] <= 5)
        {
            printf("MASTERCARD\n");
        }
        else if (digits[15] == 0 && digits[14] == 3 && (digits[13] == 4 || digits[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}