#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB* get_pixel(const unsigned char* data, int width, int height, int n, int x, int y) {
    if (data==NULL|| x<0 || y<0 || x>=width || y>= height || n<3){
        return NULL;
    }
    
    int index = (y * width + x) * channels;

    pixelRGB* pixel = malloc(sizeof(pixelRGB));
    if (pixel==NULL){
        return NULL;
    }

    pixel->R = data[index];
    pixel->G = data[index + 1];
    pixel->B = data[index + 2];

    return pixel;

}