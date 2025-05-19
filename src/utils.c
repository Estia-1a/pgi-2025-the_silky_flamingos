#include <estia-image.h>

#include "utils.h"
#include <stdlib.h>

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB *getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    pixelRGB *pixel;

    // Check if the pixel coordonates are in the image
    if (x >= width || y >= height) {
        return 0; 
    }
    
    else {
        // Convert the data 2D coordinates to 1D and thus, to "channel" coordinates
        int index = (y * width + x) * n;

        // Allocate memory for the pixel (using malloc)
        pixel = malloc(sizeof(pixelRGB));

        pixel->R = data[index];
        pixel->G = data[index + 1];
        pixel->B = data[index + 2];

        return pixel;
    }

}


