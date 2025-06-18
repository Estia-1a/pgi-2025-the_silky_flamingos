#include <estia-image.h>
#include <stdlib.h>
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB* getPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    pixelRGB* p = malloc(sizeof(pixelRGB));
    int index = (y * width + x) * n;
    p->R = data[index];
    p->G = data[index + 1];
    p->B = data[index + 2];
    return p;
}

void setPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel) {
    int index = (y * width + x) * n;
    data[index] = pixel->R;
    data[index + 1] = pixel->G;
    data[index + 2] = pixel->B;
}