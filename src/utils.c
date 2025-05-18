#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB *getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
    pixelRGB *pixel;
    
    printf("Pixel choisi (test): %d, %d, %d\n", x, y, n);
    pixel->R = data[x, y, 0];
    pixel->G = data[x, y, 1];
    pixel->B = data[x, y, 2];

    return pixel;
}


