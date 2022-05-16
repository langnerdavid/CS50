// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE8;
typedef int16_t BYTE16;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE8 buffer;
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&buffer, sizeof(BYTE8), 1, input);
        fwrite(&buffer, sizeof(BYTE8), 1, output);
    }


    // TODO: Read samples from input file and write updated data to output file
    BYTE16 buffer2;
    while (fread(&buffer2, sizeof(BYTE16), 1, input))
    {
        buffer2 *= factor;
        fwrite(&buffer2, sizeof(BYTE16), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
