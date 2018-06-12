#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <string.h>

int main(void){
    
    char a[] = {1,12,61,5,4,17,9};
    //char value = ,GetChar();
    
    //int c = strlen(a);
    bool swap;
   // int counter = 0;
    do{
        swap = false;
    
     
    for (int i=0 ; i < strlen(a); i++){
        
        int temp = a[i];
        if(i != strlen(a)-1){
         if(a[i] > a[i+1]){
            a[i] = a[i+1];
            a[i+1] = temp;
            swap = true;
            
        }}
        
       
       printf ("%d\n",a[i]);
        //char value = GetChar();
        
       
        }
        
        
    }while(swap == true);
    
    //counter ++;
}
        
   