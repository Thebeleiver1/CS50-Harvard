/**
 * Ceaser.c
 * CS50
 * pset2
 * 
 * encryp message using k
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    int k;
   
    // user input validation
    
    if (argc != 2)
    {
        
        printf("please enter one line command\n");
        return 1;
    }
    else 
    {
        // change string to integer
        
        k = atoi(argv[1]);
        
        // user message
        
        string text = GetString();
        
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            char t = text[i];
            
            if (isalpha(text[i]))
            {
                if (islower(text[i]))
                {
                    
                    t = ((((text[i] - 97) + k) % 26) + 97);
                    /*t =   text[i]+k;
                    if ( t> 122 )
                    {
                        t = (t % 123) + 97;
                        
                    }*/
                  
                }
                
                else 
                {
                    
                    t = ((((text[i] - 65) + k) % 26) + 65);
                    /*=   text[i]+k;
                    if ( t> 90 )
                    {
                        t = (t % 91) + 65;
                    
                    }*/
                }
            
            
            }
            printf("%c",t); 
          
        }
        printf("\n");
         
        return 0;
    }

}