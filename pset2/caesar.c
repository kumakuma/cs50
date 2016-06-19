/**
 * caesar.c
 * 
 * dan.smith.me@gmail.com
 * cs50 - 06/15/2016
 * 
 * encrypts messages using the caesar cipher
 * uses a command line input of non-negative int to determine the rotation
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

int main(int argc, string argv[])
{
    // check that the commanline input is correct
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // convert the argv into the rotation key
        string k = argv[1];
        int key = atoi(k);
        
        // capture the inputted string
        string p = GetString();
        
        // iterate through each char in string p
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            // encipher the char and print it
            char ciphered = cipherCode(p[i], key);
            printf("%c", ciphered);
        }
        // create a newline at end of the loop
        printf("\n");
    }
}

char cipherCode(char letter, int key)
{
    // checks that the letter is a member of the alphabet
    if (isalpha(letter))
    {
        int adjustment = 'A';
        if (islower(letter))
        {
            // checks whether it is lower case letter and changes adjustment
            adjustment = 'a';
        }
        letter = ((letter - adjustment + key) % 26) + adjustment;
    }
    
    return letter;
}
