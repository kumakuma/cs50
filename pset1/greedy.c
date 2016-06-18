/**
 *  greedy.c
 * 
 *  optimizes the chage given to the minimum number of coins possible 
 *  input: how much change is owed (float)
 *  output: a string of the differentcoins
 * 
 *  Dan Smith
 *  dan.smith.me@gmail.com
 * 
 *  cs50 pset1
 * 
 **/
 
#include <stdio.h>
#include <cs50.h>
#include <math.h>
 
int main(void)
{
    float amount_owed = 0.0;
    // ask the user how much change is owed
    printf("O hai! ");
    while (amount_owed <= 0.0)
    {
        printf("How much change is owed?\n");
        amount_owed = GetFloat();
    }
    
    // convert into whole cents
    amount_owed = round(amount_owed * 100);
    // initialise int values for coins 
    int qtrs = 0;
    int dimes = 0;
    int nickels = 0;
    int cents = 0;
    
    // check how many quarters are needed and reduce amount by their value
    if (amount_owed >= 25)
    {
        qtrs = amount_owed / 25;
        amount_owed = amount_owed - (qtrs * 25);
    }
    // check how many dimes are needed and reduce amount by their value
    if (amount_owed >= 10)
    {
        dimes = amount_owed / 10;
        amount_owed = amount_owed - (dimes * 10);
    }
    // check how many cents are needed and reduce amount by that number
    if (amount_owed >= 5)
    {
        nickels = amount_owed / 5;
        amount_owed = amount_owed - (nickels * 5);
    }
    // check how many cents are needed and reduce amount by that number
    if (amount_owed >= 1)
    {
        cents = amount_owed;
        amount_owed = amount_owed  - (cents);
    }
    
    // print the required output
    printf("%i\n", (qtrs + dimes + nickels + cents));
}