#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define BLOCK_SIZE 512

// Creates a struct BYTE of 8-bit unsigned integer
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Requires one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover filename.jpg\n");
        return 1;
    }

    char *infile = argv[1];

    // Create a file called inptr and read file from command-line
    FILE *inptr = fopen(infile, "r");

    // If file cannot be opened program quits
    if (inptr == NULL)
    {
        printf("Could not open %s\n", infile);
        return 1;
    }

    // Create a BYTE called buffer of size BLOCK_SIZE
    BYTE buffer[BLOCK_SIZE];

    char filename[8];
    int filenumber = 0;
    FILE *outptr = NULL;

    while (true)
    {
        // Read each byte of inptr in blocks of BLOCK_SIZE and store it in buffer
        fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        // Check file end and break while loop
        if (feof(inptr))
        {
            break;
        }

        // Look for start of new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", filenumber);

            // Create a file called outptr and write in it
            outptr = fopen(filename, "w");
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);

            filenumber++;
        }
        // Continue to recover image
        else
        {
            outptr = fopen(filename, "a");
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);
        }

        // Close opened file
        fclose(outptr);
    }

    // Close opened file
    fclose(inptr);
    
    return 0;
}
