#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//define a uint8_t variable as a BYTE
typedef uint8_t BYTE;

//define the block size
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    //check command-line argumments
    if (argc != 2)
    {
        printf("Usage: ./recover card_raw\n");
        return 1;
    }

    // Open memory card
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //get an address that will receive the image, set as NULL to be used in file pointers
    FILE *image = NULL;

    //buffer of size 512 bytes
    BYTE buffer[BLOCK_SIZE];

    //image count
    int count = 0;

    //array that will store the image's name
    char img[8];

    //read a 512 bytes block from raw_file into buffer until the file ends
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, raw_file))
    {
        //if the first 4 bytes of the block are a header of a jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if there ain't no jpeg file currently opened
            if (image == NULL)
            {
                //get the new jpeg file's name
                sprintf(img, "%03i.jpg", count);

                //open a new jpeg
                image = fopen(img, "w");

                //and write the block into it
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, image);

                //count +1 jpegs found
                count++;
            }

            //otherwise the block starts with a jpeg file header and there is a jpeg file already opened
            else
            {
                //close the last one
                fclose(image);

                //get the new jpeg file's name
                sprintf(img, "%03i.jpg", count);

                //open a new jpeg file
                image = fopen(img, "w");

                //and write into it
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, image);

                //count +1 jpegs found
                count++;
            }
        }

        //otherwise the block read doesn't start with a header of a jpeg file
        else
        {
            //if there is a jpeg file currently opened
            if (image != NULL)
            {
                //write the block into it
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, image);
            }
        }

    }

    //close the raw_file
    fclose(raw_file);

    //close the last image file
    fclose(image);
}