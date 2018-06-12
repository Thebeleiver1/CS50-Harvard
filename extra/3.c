#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <string.h>

int main(void){
    
    char a[] = {1,12,61,5,4,17,9};
    
     
       int value = GetInt();
       
     
    for (int i=0 ; i < strlen(a); i++){
       
        if(a[i] == value){
            
       printf ("found it");
       return 0;}
    }
        printf ("found it jjjjj");
        return 1;
        
        
    }
   