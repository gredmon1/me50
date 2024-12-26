#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint8_t BYTE; 

#define FSIZE 512 // Define the size of FSIZE

int main(int argc, char *argv[])
{
    
    FILE *file = fopen(argv[1], "r"); // Open input argument
    
    if (argv[1] == NULL)
    {
        printf("Invalid argument.\n");
        return 1;
    }
    
    BYTE buffer[FSIZE];
    
    char filename[8];
    int counter = 0;
    FILE *jpg = fopen(filename, "w"); 
    bool firstJPGfound = false;
    
    
    while (fread(buffer, FSIZE, 1, file) == 1) // Read FSIZE bytes into a buffer from file
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //condition to check if this is a jpeg
        {
            if (firstJPGfound == false)     //condition to check if the first JPG has been found already. if not, execute code
            {
                sprintf(filename, "%03i.jpg", counter); //create .jpg image to write to
                fopen(filename, "w"); // open the newly created jpg
                fwrite(buffer, FSIZE, 1, jpg); // write to the newly created jpg
                firstJPGfound = true;
            }
            
            if (counter >= 0)
            {
                fclose(jpg);
                sprintf(filename, "%03i.jpg", counter);
                fopen(filename, "w");
                fwrite(buffer, FSIZE, 1, jpg);
                counter++;
            }
        }
        
        else 
        {
            fopen(filename, "a");
            fwrite(buffer, FSIZE, 1, jpg);
        }
        
    }
    fclose(jpg); //close current image
    free(jpg); //free memory allocted for that image
    return 0; 
    
   
}
