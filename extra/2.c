#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <string.h>




int main(void)
{
    char x[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	// add as many numbers as you like to x[]
    int i;
    
    for(i = 0; i < sizeof(x) ; ++i)       
        {
        printf("%d \n", x[i]*2);
        }
    printf("\n");
    return(0);
}