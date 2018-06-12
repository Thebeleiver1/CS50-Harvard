#include <ctype.h>
#include <stdio.h>
//#include <cs50.h>
#include <math.h>


int main(void){
   //printf("Enter max number: ");
   int num = 10;
   
   
   
   for(int i = 2; i <= num; i++ )
   {
      int temp =  sqrt(i);
      int sqr = temp * temp;
      
   if (i == 2)
      printf("%i is a prime number \n",i);
   
    if (i == 3)
      printf("%i is a prime number \n",i);
   
    if (i == 5)
      printf("%i is a prime number \n",i);
      
   if (i % 5 != 0 && i% 2 != 0 && i % 3 != 0 && sqr != i ){
         
         printf("%i is a prime number\n",i);
      }
         
      }
     
   }