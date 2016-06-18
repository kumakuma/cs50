/**
 * 
 * initials.c
 * 
 * prompts the user for their name, prints their initials in uppercase
 * with no spaces folowed by a new line
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>

char Upper(char c);
int main(void)
{
    // Prompt the user for their name
    // printf("Please enter your full name: ");
    string s = GetString();
    int n = strlen(s);
    // Iterate through all characters
    for (int i = 0; i < n; i++)
    {
        // select the first character OR characters following a space
        // print the upper case version of selected character
        if ((i == 0) || (s[i - 1] == ' '))
        {
            printf("%c", Upper(s[i]));
        }
    }
    printf("\n");
}

char Upper(char c)
{
    // adjustment ASCII value
    int adj = (int) 'a' - (int) 'A';
    // check whether c is lowercase
    if ((int) c >= (int) 'a')
    {
        // adjust the ASCII value to make it UpperCase
        c = (char) c - adj;
    }
    return c;
}