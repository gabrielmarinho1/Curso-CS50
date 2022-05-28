#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //roll through each line
    for (int h = 0; h < height; h++)
    {
        //roll through each column
        for (int w = 0; w < width; w++)
        {
            //take the average of the pixel color
            int average = round((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0);

            //change the pixel color into a grayscale
            image[h][w].rgbtRed = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //roll through each line
    for (int i = 0; i < height; i ++)
    {
        //roll through each column
        for (int j = 0; j < width; j++)
        {
            //convert pixels to float
            float oldRed = image[i][j].rgbtRed;
            float oldGreen = image[i][j].rgbtGreen;
            float oldBlue = image[i][j].rgbtBlue;

            //find the sepia pixel value
            int sepiaRed = round(.393 * oldRed + .769 * oldGreen + .189 * oldBlue);
            int sepiaGreen = round(.349 * oldRed + .686 * oldGreen + .168 * oldBlue);
            int sepiaBlue = round(.272 * oldRed + .534 * oldGreen + .131 * oldBlue);

            //set the pixel values to 255 if they're greather than 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //apply the filter to the pixels
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //variable that will temporarily store the pixel
    RGBTRIPLE pixel;

    //roll through each line
    for (int h = 0; h < height; h++)
    {
        //roll through half of the columns, because both halfs are reflected at the same time
        for (int w = 0; w < width / 2; w++)
        {
            //store the pixel
            pixel = image[h][w];
            //reflect the pixel from the left to the right
            image[h][w] = image[h][width - w - 1];
            //reflect the pixel from the right to the left
            image[h][width - w - 1] = pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //copy the original image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    return;
}
