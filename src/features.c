#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !!");
}

/**
 * @brief This function reads the image and prints its dimensions.
 * @param[in] source_path : path to the image to be read
 * To use :
 * ./freud.exe --debug -f ../images/input/image.jpeg -c dimension
 */

void dimension (char *source_path) {
    unsigned char *data;
    int width, height, nbChannels;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Check if the image was read successfully
    if (results != 0) {
        printf("dimension: %d, %d", width, height);
    }

    else {
        printf("Error while reading image data\n");
    }
}

/**
 * @brief This function reads the image and prints the RGB values of the first pixel.
 * @param[in] source_path : path to the image to be read
 * To use :
 * ./freud.exe --debug -f ../images/input/image.jpeg -c first_pixel
 */
void first_pixel (char *source_path) {
    unsigned char *data;
    int width, height, nbChannels;
    pixelRGB *pixel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Check if the image was read successfully
    if (results != 0) {
        pixel = getPixel(data, width, height, nbChannels, 0, 0);
        printf("first pixel: %d, %d, %d", pixel->R, pixel->G, pixel->B);
    }

    else {
        printf("Error while reading image data\n");
    }
}

/**
 * @brief This function reads the image and prints the RGB values of the tenth pixel.
 * @param[in] source_path : path to the image to be read
 * To use :
 * ./freud.exe -f ./images/input/image.jpeg -c tenth_pixel 
 */

void tenth_pixel (char *source_path) {
    unsigned char *data;
    int width, height, nbChannels;
    pixelRGB *pixel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Check if the is wide enough to get the tenth pixel
    if (width < 10 ) {
        printf("Image is too small to get the tenth pixel\n");
        return;
    }

    else {
        // Check if the image was read successfully
        if (results != 0) {
            pixel = getPixel(data, width, height, nbChannels, 9, 0);
            printf("first pixel: %d, %d, %d", pixel->R, pixel->G, pixel->B);
        }

        else {
            printf("Error while reading image data\n");
        }
    }
}

/**
 * @brief This function reads the image and prints the RGB values of the first pixel of the second line.
 * @param[in] source_path : path to the image to be read
 * To use :
 * ./freud.exe -f ./images/input/image.jpeg -c second_line 
 */

void second_line (char *source_path) {
    unsigned char *data;
    int width, height, nbChannels;
    pixelRGB *pixel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Check if the image is high enough to get the first pixel of the second line
    if (height < 2) {
        printf("Image is too small to get the first pixel of the second line\n");
        return;
    }

    else {
        // Check if the image was read successfully
        if (results != 0) {
            pixel = getPixel(data, width, height, nbChannels, 0, 1);
            printf("first pixel: %d, %d, %d", pixel->R, pixel->G, pixel->B);
        }

        else {
            printf("Error while reading image data\n");
        }
    }
}

/**
 * @brief This function reads the image and prints the RGB values of the pixel at (x,y).
 * @param[in] source_path : path to the image to be read
 * @param[in] x : x coordinate of the pixel
 * @param[in] y : y coordinate of the pixel
 * To use :
 * ./freud.exe -f ./images/input/image.jpeg -c print_pixel <X> <Y>
 */
void print_pixel(char *source_path, int x, int y) {
    unsigned char *data;
    int width, height, nbChannels;
    pixelRGB *pixel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Check if the image was read successfully
    if (results != 0) {
        pixel = getPixel(data, width, height, nbChannels, x, y);
        printf("print_pixel (%d, %d): %d, %d, %d", x, y, pixel->R, pixel->G, pixel->B);
    }

    else {
        printf("Error while reading image data\n");
    }
}

/**
 * @brief This function reads the image and prints the pixel with the with the largest sum of RGB components in the output terminal.
 * @param[in] source_path : path to the image to be read
 * To use :
 * ./freud.exe -f ./images/input/image.jpeg -c max_pixel
 */
void max_pixel(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j, x = 0, y = 0;
    pixelRGB *pixel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Initialize max pixel to the first pixel
    pixelRGB *max_pixel = getPixel(data, width, height, nbChannels, x, y);

    // Check if the image was read successfully
    if (results != 0) {
        for (i = 0; i < width; i++) {
            for (j = 0; j < height; j++) {
                pixel = getPixel(data, width, height, nbChannels, i, j);
                if ((pixel->R + pixel->G + pixel->B) >= (max_pixel->R + max_pixel->G + max_pixel->B)) {
                    printf("New max pixel found: (%d, %d): %d, %d, %d\n", i, j, pixel->R, pixel->G, pixel->B);
                    max_pixel = pixel;
                    x = i;
                    y = j;
                }
            }
        }
        printf("max_pixel (%d, %d): %d, %d, %d", x, y, pixel->R, pixel->G, pixel->B);
    }

    else {
        printf("Error while reading image data\n");
    }
}