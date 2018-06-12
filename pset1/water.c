/**
 * Water.c
 * cs50 
 * pset1
 * program that calculate Number of bottles used according to given time
 */
 
#include <stdio.h>
#include <cs50.h>

// functio to calculate Number of bottles used according to given time
int main(void)
{
    printf("minutes:");
    
    // user input how may minute he takes to have shower
    
    int x = GetInt();
    
    // 1 minute shower is equal to 12 bottles of water
    
    int y = 12;
    
    // calculating by multiplying no of bottles and water
    
    int total = (x * y);
    
    printf("Bottles: %d \n",total);
    

}