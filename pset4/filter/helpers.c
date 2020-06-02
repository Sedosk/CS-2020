#include "helpers.h"

#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;

    // Loops through each row of the image
    for (int h = 0; h < height; h++)
    {
        // Loops through each pixel of the row
        for (int w = 0; w < width; w++)
        {
            // Takes rounded average of each color scale of pixel and stores it in 'avg'
            avg = round((image[h][w].rgbtRed + image[h][w].rgbtBlue + image[h][w].rgbtGreen) / 3.000);

            // Sets each color scale of pixel to 'avg' value
            image[h][w].rgbtRed = avg;
            image[h][w].rgbtBlue = avg;
            image[h][w].rgbtGreen = avg;
        }
    }

    return;
}

// Caps the value at 255
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaBlue;
    int sepiaGreen;

    // Loops through each row of the image
    for (int h = 0; h < height; h++)
    {
        // Loops through each pixel of the row
        for (int w = 0; w < width; w++)
        {
            // Sepia algorithm
            sepiaRed = limit(round(.393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue));
            sepiaGreen = limit(round(.349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue));
            sepiaBlue = limit(round(.272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue));

            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary array of pixels
    RGBTRIPLE save[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            // Saves left half of image
            save[h][w] = image[h][w];

            // Reflects right half of image into left half
            image[h][w] = image[h][width - w - 1];

            // Reflects saved left half of image into right half
            image[h][width - w - 1] = save[h][w];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary array of pixels
    RGBTRIPLE save[height][width];

    int count;
    int avgR, avgG, avgB;

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Saves copy of image
            save[h][w] = image[h][w];
        }
    }

    // Iterates through each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            avgR = avgG = avgB = 0;
            count = 0;

            // Iterates pixels around each pixel
            for (int hh = - 1; hh < 2; hh++)
            {
                for (int ww = - 1; ww < 2; ww++)
                {
                    // Checks for image bounds
                    if (w + ww < 0 || w + ww > width - 1 || h + hh < 0 || h + hh > height - 1)
                    {
                    }
                    else
                    {
                        // Sums up the value of every pixel in given rectangle
                        avgR += save[h + hh][w + ww].rgbtRed;
                        avgG += save[h + hh][w + ww].rgbtGreen;
                        avgB += save[h + hh][w + ww].rgbtBlue;

                        // Counts number of pixels inside the rectangle
                        count++;
                    }
                }
            }

            // Averages values of sums (line 129) and updates the image
            image[h][w].rgbtRed = round(avgR / (float) count);
            image[h][w].rgbtGreen = round(avgG / (float) count);
            image[h][w].rgbtBlue = round(avgB / (float) count);
        }
    }

    return;
}
