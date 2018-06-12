/**
 * greedy.c
 * based on greedy algorithm
 * give least coin as possible
 * output is given in number of coin
 */

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>


int count1;
int count2;
int count3;
int count4;
int total_coin;
float f;


int main(void)

// Validation
{
    do
    {
        printf("How Much Change is owed: ");
        f = GetFloat() ; 
      
    }
  while (f <= 0);
    // converting to cents
  
    int i = round(f * 100) ;
  
    // checking from bigger coint to smaller coin
  
    if (i >= 25 || i >= 10 || i >= 5 || i >= 1)
    {
        int t =  i % 25;
        
        count1 = i / 25;
    
    
        if (t >= 10 || i >= 5 || i >= 1)
        {
            count2 = t / 10;
            t = t % 10;
         
            if (t >= 5 || i >= 1 )
            {
                count3 = t / 5;
                
                t = t % 5;
            
                if (t >= 1)
                {
                    count4 = t / 1;
                    t = t % 1;
                }   
            
            }
        
        }
     
        // number of coin used
        total_coin = (count1 + count2 + count3 + count4);
    
        printf("%d\n",total_coin); 
    
        return 0;
  }
   
    
}

