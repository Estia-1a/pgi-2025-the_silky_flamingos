#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB *getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {

    // Check if the pixel coordonates are in the image
    if (x >= width || y >= height) {
        return NULL; 
    }
    
    // Check if there is no data
    else if (data == NULL) {
        return NULL;
    }

    else {
        return (pixelRGB *) (data + (y * width + x) * n);
    }

}