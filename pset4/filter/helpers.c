#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int red = image[j][i].rgbtRed;
            int blue = image[j][i].rgbtBlue;
            int green = image[j][i].rgbtGreen;

            //calculate the middle number rgb value
            int average = round(((float)red + (float)blue + (float)green) / 3);

            //new rgb value of all is the average value
            image[j][i].rgbtRed = average;
            image[j][i].rgbtBlue = average;
            image[j][i].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int originalRed = image[j][i].rgbtRed;
            int originalBlue = image[j][i].rgbtBlue;
            int originalGreen = image[j][i].rgbtGreen;

            //use sepia formula to calculate new rgb values
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            //check if the value is over 255 because the rgb scale is limited to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[j][i].rgbtRed = sepiaRed;
            image[j][i].rgbtBlue = sepiaBlue;
            image[j][i].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j  ++)
        {
            RGBTRIPLE buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE buffer[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumgreen = 0, sumred = 0, sumblue = 0;
            float counter = 0;
            for (int h = i - 1; h <= i + 1; h++)
            {
                for (int k = j - 1; k <= j + 1; k++)
                {
                    //check if the pixel is in the picture
                    if (h >= 0 && k >= 0 && h < height && k < width)
                    {
                        //adding all rgb numbers around the pixel together
                        sumred += buffer[h][k].rgbtRed;
                        sumblue += buffer[h][k].rgbtBlue;
                        sumgreen += buffer[h][k].rgbtGreen;
                        counter ++;
                    }



                }
            }

            //calculate average amount of rgb
            int avgred = round(sumred / counter);
            int avgblue = round(sumblue / counter);
            int avggreen = round(sumgreen / counter);

            //new image with the average amount of rgb
            image[i][j].rgbtRed = avgred;
            image[i][j].rgbtBlue = avgblue;
            image[i][j].rgbtGreen = avggreen;
        }
    }
    return;
}
