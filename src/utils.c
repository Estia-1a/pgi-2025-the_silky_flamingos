#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB *getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
    pixelRGB *pixel;
    
    // Convert the data 2D coordinates to 1D and thus, to "channel" coordinates
    int index = (y * width + x) * n;

    printf("Index R: %d\n", index);
    printf("Value R: %d\n", data[index]);
    pixel->R = data[index];

    printf("Index G: %d\n", index + 1);
    printf("Value G: %d\n", data[index + 1]);
    pixel->G = data[index + 1];

    printf("Index B: %d\n", index + 2);
    printf("Value B: %d\n", data[index + 2]);
    pixel->B = data[index + 2];

    return pixel;
}


