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
        printf("first_pixel: %d, %d, %d", pixel->R, pixel->G, pixel->B);
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
            printf("tenth_pixel: %d, %d, %d", pixel->R, pixel->G, pixel->B);
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
            printf("second_line_first_pixel: %d, %d, %d", pixel->R, pixel->G, pixel->B);
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
 * If multiple pixels are equals to the maximum, return the first pixel encountered (i.e. min (x,y)).
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
                    max_pixel = pixel;
                    x = i;
                    y = j;
                }
            }
        }
        printf("max_pixel (%d, %d): %d, %d, %d", x, y, max_pixel->R, max_pixel->G, max_pixel->B);
    }

    else {
        printf("Error while reading image data\n");
    }
}

/**
 * @brief This function reads the image and prints the pixel with the with the smallest sum of RGB components in the output terminal. 
 * If multiple pixels are equals to the minimum, return the first pixel encountered (i.e. min (x,y)).
 * @param[in] source_path : path to the image to be read
 * To use :
 * ./freud.exe -f ./images/input/image.jpeg -c min_pixel
 */
void min_pixel(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j, x = 0, y = 0;
    pixelRGB *pixel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Initialize min pixel to the first pixel
    pixelRGB *min_pixel = getPixel(data, width, height, nbChannels, x, y);

    // Check if the image was read successfully
    if (results != 0) {
        for (i = 0; i < width; i++) {
            for (j = 0; j < height; j++) {
                pixel = getPixel(data, width, height, nbChannels, i, j);
                if ((pixel->R + pixel->G + pixel->B) < (min_pixel->R + min_pixel->G + min_pixel->B)) {
                    min_pixel = pixel;
                    x = i;
                    y = j;
                }
            }
        }
        printf("min_pixel (%d, %d): %d, %d, %d", x, y, min_pixel->R, min_pixel->G, min_pixel->B);
    }

    else {
        printf("Error while reading image data\n");
    }
}

/**
 * @brief Print the pixel with the maximum R, G, or B value in the output terminal.
 * If multiple pixels are equals to the maximum, return the first pixel encountered (i.e. min (x,y)).
 * @param[in] source_path : path to the image to be read
 * @param[in] component : component to be checked ('R', 'G' or 'B')
 * To use :
 * ./freud.exe -f ./images/input/image.jpeg -c max_component <component>
 */
void max_component(char *source_path, char component) {
    unsigned char *data;
    int width, height, nbChannels, i, j, x = 0, y = 0;
    pixelRGB *pixel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Initialize max pixel to the first pixel
    pixelRGB *max_pixel = getPixel(data, width, height, nbChannels, x, y);

    // Check if the image was read successfully
    if (results != 0) {
        if (component == 'R') {
            for (j = 0; j < height; j++) {
                for (i = 0; i < width; i++) {
                    pixel = getPixel(data, width, height, nbChannels, i, j);
                    if (pixel->R > max_pixel->R) {
                        printf("max_component R (%d, %d): %d\n", x, y, max_pixel->R);
                        max_pixel = pixel;
                        x = i;
                        y = j;
                    }
                }
            }
            printf("max_component R (%d, %d): %d", x, y, max_pixel->R);
        }
        else if (component == 'G') {
            for (j = 0; j < height; j++) {
                for (i = 0; i < width; i++) {
                    pixel = getPixel(data, width, height, nbChannels, i, j);
                    if (pixel->G > max_pixel->G) {
                        max_pixel = pixel;
                        x = i;
                        y = j;
                    }
                }
            }
            printf("max_component G (%d, %d): %d", x, y, max_pixel->G);
        }
        else if (component == 'B') {
            for (j = 0; j < height; j++) {
                for (i = 0; i < width; i++) {
                    pixel = getPixel(data, width, height, nbChannels, i, j);
                    if (pixel->B > max_pixel->B) {
                        max_pixel = pixel;
                        x = i;
                        y = j;
                    }
                }
            }
            printf("max_component B (%d, %d): %d", x, y, max_pixel->B);
        }
        else {
            printf("Invalid component. Use 'R', 'G' or 'B'.\n");
            return;
        }
    }

    else {
        printf("Error while reading image data\n");
    }
}