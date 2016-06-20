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
    // check that the commanline input is correct
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        // select the second item of the array as keyword
        string keyword = argv[1];
        // printf("Keyword: %s\n", keyword);
        // check the keyword is valid
        if (!checkInput(keyword))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
        
        // for (int i = 0; i < strlen(keyword); i++)
        // {
        //     int key = keyword[i];
        //     printf("k: %c, ki: %i\n", (char) key, key);
        // }
        
        // capture the inputted string
        string p = GetString();
        
        // iterate through each char in string p
        for (int i = 0, j = 0, n = strlen(p), m = strlen(keyword); i < n; i++)
        {
            int key = (int) keyword[j];
            // printf("k: %c, ki: %i\n", (char) key, key);
            char c = p[i];
            if (isalpha(c) && c != ' ')
            {
                // encipher the char and print it
                c = cipherCode(p[i], key);
                if (j < m - 1)
                {
                    j++;
                }
                else
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
    // checks that the letter is a member of the alphabet
    // printf("letter: %c letterI: %i key: %i\n", letter, (int) letter, key);
    
    if (islower((char) key))
    {
        key = key - 'a';
    }
    else
    {
        key = key - 'A';
    }
    
    int adjustment = 'A';
    if (islower(letter))
    {
        // checks whether it is lower case letter and changes adjustment
        adjustment = 'a';
    }
    letter = ((letter - adjustment + key) % 26) + adjustment;
    // printf("ciphered: %i\n", letter);
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