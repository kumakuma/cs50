/**
 * vigenere.c
 *
 * dan.smith.me@gmail.com
 * cs50 - 06/19/2016
 *
 * encrypts messages using the vigenere cipher
 * uses a command line input of keyword
 *
 * requests a string to cipher and outputs the ciphertext
 *
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char cipherCode(char letter, int key);
bool checkInput(string keyword);

int main(int argc, string argv[])
{
    // check that the commandline input is correct
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        // select the second item of the array as keyword
        string keyword = argv[1];

        // check the keyword is valid
        if (!checkInput(keyword))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }

        // capture the inputted string
        string p = GetString();

        // iterate through each char in string p
        for (int i = 0, j = 0, n = strlen(p), m = strlen(keyword); i < n; i++)
        {
            // to ensure that the keyword is treated same either way as per spec
            int key = tolower(keyword[j]);
            // printf("k: %c, ki: %i\n", (char) key, key);
            char c = p[i];
            if (isalpha(c) && c != ' ')
            {
                // encipher the char and print it
                c = cipherCode(p[i], key);

                // increment j
                if (j < m - 1)
                {
                    j++;
                }
                else // wrap around to beginning of keyword
                {
                    j = 0;
                }
            }
            printf("%c", c);
        }
        // create a newline at end of the loop
        printf("\n");
    }
}

char cipherCode(char letter, int key)
{
    int adjustment = 'a';
    
    // determine alphabetical index of key
    int keyValue = key - adjustment;
    
    // determine case of letter and assign correct alphabetical index
    if (isupper(letter))
    {
        adjustment = 'A';
    }
    
    // calculate letter value
    letter = (char) ((letter - adjustment + keyValue) % 26) + adjustment;

    return letter;
}

bool checkInput(string keyword)
{
    bool result = true;
    for (int i = 0, n = strlen(keyword); i < n; i++ )
    {
        if (!isalpha(keyword[i]))
        {
            result = false;
        }
    }
    return result;
}