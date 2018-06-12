#include <stdio.h>
#include <cs50.h>

//functio to calculate Number of bottles used according to given timr
int main(void)
{
    printf("minutes:");
    
    int x;
    scanf("%d",&x);
    
    int y = 12;
    
    int z = (x *y);
    
    printf("Bottles: %d \n",z);
    

}