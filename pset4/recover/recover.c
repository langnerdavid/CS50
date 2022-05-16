#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    //Check if user typed in one comment line argument
    if (argc != 2)
    {
        printf("Usage: :/recover image\n");
        return 1;
    }

    FILE *inputfile = fopen(argv[1], "r");
    //check if inputfile can be opened
    if (inputfile == NULL)
    {
        printf("File can not be opened\n");
        return 1;
    }

    int count = 0;
    BYTE buffer[512];
    char filename[8];
    FILE *output = NULL;

    while (fread(buffer, 1, 512, inputfile))
    {
        //check if its the start of a new jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //check if its the first jpeg
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                output = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, output);
                count ++;
            }
            //otherwise close old jpeg
            //open new and write to it
            else
            {
                fclose(output);
                sprintf(filename, "%03i.jpg", count);
                output = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, output);
                count ++;
            }
        }
        //if it isnt the start of a new jpeg keep writing
        //but only if the first jpeg has been found
        else if (count > 0)
        {
            fwrite(buffer, sizeof(buffer), 1, output);
        }
        //continue;
    }

    fclose(output);
    fclose(inputfile);
    return 0;
}