/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <string.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
   if (n >0){
        for (int i = 0; i < n; i++)
        {
            if(values[i] == value)
            return true;
            
            
        
        }
       return false;
  
   }
   return 1;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
     bool swap;
   // int counter = 0;
    do{
        swap = false;
    
     
    for (int i=0 ; i < n; i++){
        
        int temp = values[i];
        
        if(i != n-1){
            
         if(values[i] > values[i+1]){
             
            values[i] = values[i+1];
            values[i+1] = temp;
            swap = true;
            
        }}
        
       
      
       
    }
        
        
    }while(swap == true);
    
    
   
}