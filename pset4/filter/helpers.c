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
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
