
/**
 * Initials.c
 * Cs50
 * Pset2
 * 
 * Keeps only the initial of a word from sentence and change to capital letter.
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    
   // user input.. text
   
    string s = GetString();
    
    // user input is not null
    
    if (s != NULL)
    {
        // first letter is not null
        if (s[0] != ' ')
        {
            printf("%c", toupper(s[0]));
        
        }
    
        for ( int i = 0, n = strlen(s); i < n; i++)
        {
           // change the letter to uppercase that comes after space
            if (s[i] == ' ' && s[i + 1] != ' ')
            {
                printf("%c",toupper(s[i + 1])); 
                
            }
        }
   }
    printf("\n");
}