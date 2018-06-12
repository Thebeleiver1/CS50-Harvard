/**
 * mario.c
 * cs 50
 * pset1
 * based on mario game
 */
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i;
    
    int n;

    // validation to check if the number between the given condition
    do
    {
        printf("Height:");
        // Input from user
        n = GetInt();
    } while (n < 0 || n > 23);
    
    // creating a # stack
    
    for (i = n - 1; i >= 0; i = i - 1)
    {
        // loop that create space 
        
        for (int x = i - 1; x >= 0; x = x - 1)
        {
            
            printf(" ");
            
        }   
        
        // Add # in the beginining to make it 2 #
         
        printf("#"); 
        
        // Loop create # according to user input
        
        for (int y = i; y < n; y = y + 1) 
        {
                
            printf("#");
            
        }
        printf("\n");
    }

    return 0;
}