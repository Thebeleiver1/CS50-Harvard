/*
    Filename: vigenere.c
    Author: Chris Anders, chris@hell-labs.de
    
    This file presents a solution for the vigenere problem in pset2 of CS50x.
*/

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>



int main(int argc, string argv[]) {
    
    int k = strlen("punyahrorp");

    int n = 5;
    int x[k];
    
    for (int i = 0; i< k; i++)
    {
        x[i] = i;
    }
    
    for( int i = 0; i<n; i++)
    {
        
        printf("punya %d %d \n", i , x[i]);
    }
    
}