/**
 * mario.c
 * 
 * recreates a half pyramid of #
 * input: positive integers <= 23
 * output: prints a half pyramid of #
 * 
 * Dan Smith
 * dan.smith.me@gmail.com
 * 
 * cs50 pset1
 * 
 * // found hint here: http://stackoverflow.com/questions/14678948/how-to-repeat-a-char-using-printf
 * 
 */
 
#include <stdio.h>
#include <cs50.h>
 
int main(void)
{
    // requests height of pyramid until a valid input is entered
    int height = 0;
    do
    {
        printf("height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    // from the hint listed above
    // prints out one # for each unit of height
    // for (int i = 1; i <= height; i++)
    // {
        // printf("%.*s#%.*s\n", (height-i), "                       ", i, "#######################");
    // }
    
    // less efficient version though probably the one intended (?)
    int length = height;
    for (int row = 0; row < height; row++)
    {
        for (int spaces = 0; spaces < (length - row - 1); spaces++)
        {
            printf(" ");
        }
        for (int blocks = 0; blocks <= row; blocks++)
        {
            printf("#");
        }
        printf("#\n");
    }

}
 