/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    int pSize = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    if(pSize < 1 || pSize > 100)
    {
        printf("You have enter invalid pixel size \n");
        return 1;
    }
    
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    
    
    // Adjusting the Size
    int originalWidth = bi.biWidth;
    int originalHeight = bi.biHeight;
    bi.biWidth *= pSize;
    bi.biHeight *= pSize;

    // determine padding for scanlines
    int wPadding =  (4 - (originalWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int hPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //calculating size
    bi.biSizeImage = abs(bi.biHeight) * (bi.biWidth * sizeof(RGBTRIPLE) + hPadding);
    bf.bfSize = (bi.biSizeImage + 54);
    
    
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0; i < abs(originalHeight); i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < pSize; j++)
        {
            fseek(inptr, (54 + ((originalWidth * 3 + wPadding) * i)), SEEK_SET);
            
            for(int k = 0; k < originalWidth; k++)
            {
            // temporary storage
                RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for(int m = 0;m < pSize; m++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
        

        // skip over padding, if any
        //fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
            for (int k = 0; k < hPadding; k++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
