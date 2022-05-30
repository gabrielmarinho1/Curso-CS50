// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

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

    //array that will temporarily store the data of the header
    uint8_t header[HEADER_SIZE];

    //read HEADER_SIZE(the first 44 bytes), 1 byte at a time, from the input file into header
    fread(header, HEADER_SIZE, 1, input);

    //write header into the output file
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    //the variable that will temporarily store each sample of the audio file
    int16_t buffer;

    //loop that will read each sample at a time from the input file and store it into the buffer until the file ends
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        //update the sample volume by multiplying it by factor
        buffer *= factor;

        //then, write the updated sample into the output file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
