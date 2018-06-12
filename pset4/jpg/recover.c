/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{
  FILE *infile = fopen("card.raw", "r");
  
  //FILE *outfile = fopen(fileName,"w");
  
  BYTE buffer[512];
  
  
  if(infile == NULL)
  { 
      
      printf("file is not selected or removed\n");
      return 1;
  }
  
    int count = 0;
    
    FILE *empty = NULL;
    
    while(fread(buffer, sizeof(buffer), 1, infile)){
        
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            
            if(empty != NULL)
                fclose(empty);
                
            char fileName[7];
            
            sprintf(fileName,"%03d.jpg",count);
            
            empty = fopen(fileName,"w");
            
            count++;
            
            
        }
        
            if(empty != NULL)
                fwrite(buffer, sizeof(buffer),1, empty);
    }
        
            if(empty != NULL)
                fclose(empty);
                
            fclose(infile);
            
            return 0;
        
        
}
