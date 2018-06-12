/**
 * Vigenere.c
 * CS50
 * Pset2
 * 
 * Encrypt the message according to user text in line argument
 * 
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    string keyword;
 
    string text;
   
    // check if user input anything beside file name
   
    if (argc != 2)
    {
        
        printf("please enter one line command");
        return 1;
    }
    
    else if (argv[1])
    {
        // coverting user word to letter 
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                // accept only letters as input. 
                
                printf("contains illegal characters.\n");
                
                return 1;
            }
        
        }
        
    }   

    keyword = argv[1];
    
    int key_length = strlen(keyword);
    int x[key_length];


    for (int i = 0; i < key_length; i++)
    {
        x[i] = (tolower(keyword[i]) - 97);
        // k[i] = newkey[i];
        // printf("%i\n",k[i]);
        
    }
    
    text = GetString();
    int k = 0;
    
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        char t = text[i];
        
        // check value is alphabet
    
        if (isalpha(text[i]))
        {
            // lowercase
            
            if (islower(text[i]))
            {
                
                t = ((((text[i] - 97) + (x[k % key_length])) % 26) + 97);
                
                // int r = x[(k % key_length)];
                
              
            }
            
            // uppercase
            else 
            {
                
                t = ((((text[i] - 65) + (x[k % key_length])) % 26) + 65);  
                
            }
            
            k++;
        
        
        }
      
        printf("%c",t);
    }  
            
    
    printf("\n")   ;     
    

}