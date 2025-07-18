#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    // Check if the image was read successfully
    if (results == 0) {
        printf("Error while reading image data\n");
    }

    else {
        // Check if the is wide enough to get the tenth pixel
        if (width >= 10) {
            pixel = getPixel(data, width, height, nbChannels, 9, 0);
            printf("tenth_pixel: %d, %d, %d", pixel->R, pixel->G, pixel->B);
        }

        else {
            printf("Image is too small to get the tenth pixel\n");
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
            printf("second_line: %d, %d, %d", pixel->R, pixel->G, pixel->B);
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
 * @brief This function reads the image and prints the pixel with the with the largest sum of RGB components in the output terminal. If multiple pixels are equals to the maximum, return the first pixel encountered (i.e. min (x,y)).
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
    pixelRGB *max_Pixel = getPixel(data, width, height, nbChannels, x, y);

    // Check if the image was read successfully
    if (results != 0) {
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                pixel = getPixel(data, width, height, nbChannels, i, j);
                if ((pixel->R + pixel->G + pixel->B) > (max_Pixel->R + max_Pixel->G + max_Pixel->B)) {
                    max_Pixel = pixel;
                    x = i;
                    y = j;
                }
            }
        }
        printf("max_pixel (%d, %d): %d, %d, %d", x, y, max_Pixel->R, max_Pixel->G, max_Pixel->B);
    }

    else {
        printf("Error while reading image data\n");
    }
}

/**
 * @brief This function reads the image and prints the pixel with the with the smallest sum of RGB components in the output terminal. If multiple pixels are equals to the minimum, return the first pixel encountered (i.e. min (x,y)).
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
    pixelRGB *min_Pixel = getPixel(data, width, height, nbChannels, x, y);

    // Check if the image was read successfully
    if (results != 0) {
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                pixel = getPixel(data, width, height, nbChannels, i, j);
                if ((pixel->R + pixel->G + pixel->B) < (min_Pixel->R + min_Pixel->G + min_Pixel->B)) {
                    min_Pixel = pixel;
                    x = i;
                    y = j;
                }
            }
        }
        printf("min_pixel (%d, %d): %d, %d, %d", x, y, min_Pixel->R, min_Pixel->G, min_Pixel->B);
    }

    else {
        printf("Error while reading image data\n");
    }
}

/**
 * @brief Print the pixel with the maximum R, G, or B value in the output terminal. If multiple pixels are equals to the maximum, return the first pixel encountered (i.e. min (x,y)).
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

/**
 * @brief Print the pixel with the minimum R, G, or B value in the output terminal. If multiple pixels are equals to the minimum, return the first pixel encountered (i.e. min (x,y)).
 * @param[in] source_path : path to the image to be read
 * @param[in] component : component to be checked ('R', 'G' or 'B')
 * To use :
 * ./freud.exe -f ./images/input/image.jpeg -c min_component <component>
 */
void min_component(char *source_path, char component) {
    unsigned char *data;
    int width, height, nbChannels, i, j, x = 0, y = 0;
    pixelRGB *pixel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Initialize max pixel to the first pixel
    pixelRGB *min_pixel = getPixel(data, width, height, nbChannels, x, y);

    // Check if the image was read successfully
    if (results != 0) {
        if (component == 'R') {
            for (j = 0; j < height; j++) {
                for (i = 0; i < width; i++) {
                    pixel = getPixel(data, width, height, nbChannels, i, j);
                    if (pixel->R < min_pixel->R) {
                        min_pixel = pixel;
                        x = i;
                        y = j;
                    }
                }
            }
            printf("min_component R (%d, %d): %d", x, y, min_pixel->R);
        }
        else if (component == 'G') {
            for (j = 0; j < height; j++) {
                for (i = 0; i < width; i++) {
                    pixel = getPixel(data, width, height, nbChannels, i, j);
                    if (pixel->G < min_pixel->G) {
                        min_pixel = pixel;
                        x = i;
                        y = j;
                    }
                }
            }
            printf("min_component G (%d, %d): %d", x, y, min_pixel->G);
        }
        else if (component == 'B') {
            for (j = 0; j < height; j++) {
                for (i = 0; i < width; i++) {
                    pixel = getPixel(data, width, height, nbChannels, i, j);
                    if (pixel->B < min_pixel->B) {
                        min_pixel = pixel;
                        x = i;
                        y = j;
                    }
                }
            }
            printf("min_component B (%d, %d): %d", x, y, min_pixel->B);
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

/**
 * @brief write in a text file the result of: max_pixel, min_pixel, max_component R, max_component G, max_component B, min_component R, min_component G, min_component B
 * @param[in] source_path : path to the image to be read
 * To use :
 * ./freud.exe -f ./images/input/image.jpeg -c stat_report
 */
void stat_report(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Check if the image was read successfully
    if (results != 0) {
        fopen("stat_report.txt", "w");
        freopen("stat_report.txt", "w", stdout);
        max_pixel(source_path);
        printf("\n\n");
        min_pixel(source_path);
        printf("\n\n");
        max_component(source_path, 'R');
        printf("\n\n");
        max_component(source_path, 'G');
        printf("\n\n");
        max_component(source_path, 'B');
        printf("\n\n");
        min_component(source_path, 'R');
        printf("\n\n");
        min_component(source_path, 'G'); 
        printf("\n\n");
        min_component(source_path, 'B');
    } 
    
    else {
        printf("Error while reading image data\n");
    }
}

void color_red(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);
    // Check if the image was read successfully
    if (results != 0) {

        // Allocating memory for the new image data
        unsigned char *newData = malloc(width * height * nbChannels * sizeof(unsigned char));

        // Creating the new image datas (pixel's channel by pixel's channel)
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                // Old datas (pixel by pixel)
                pixelRGB *old_pixel = getPixel(data, width, height, nbChannels, i, j);

                // New datas (channel by channel)
                newData[(j * width + i) * nbChannels] = old_pixel->R;
                newData[(j * width + i) * nbChannels + 1] = 0;
                newData[(j * width + i) * nbChannels + 2] = 0;
                }
            }

        int write_result = write_image_data("image_out.bmp", newData, width, height);
        
        // Check write result
        if (write_result != 0) { 
            printf("Upload reussi ! \n");
        } else {
            printf("Error writing image\n");
        }
    }
    
    else {  
        printf("Error while reading image data\n");
    }
}

void color_green(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);
    // Check if the image was read successfully
    if (results != 0) {

        // Allocating memory for the new image data
        unsigned char *newData = malloc(width * height * nbChannels * sizeof(unsigned char));

        // Creating the new image datas (pixel's channel by pixel's channel)
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                // Old datas (pixel by pixel)
                pixelRGB *old_pixel = getPixel(data, width, height, nbChannels, i, j);

                // New datas (channel by channel)
                newData[(j * width + i) * nbChannels] = 0;
                newData[(j * width + i) * nbChannels + 1] = old_pixel->G;
                newData[(j * width + i) * nbChannels + 2] = 0;
                }
            }

        int write_result = write_image_data("image_out.bmp", newData, width, height);
        
        // Check write result
        if (write_result != 0) { 
            printf("Upload reussi ! \n");
        } else {
            printf("Error writing image\n");
        }
    }
    
    else {  
        printf("Error while reading image data\n");
    }
}

void color_blue(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);
    // Check if the image was read successfully
    if (results != 0) {

        // Allocating memory for the new image data
        unsigned char *newData = malloc(width * height * nbChannels * sizeof(unsigned char));

        // Creating the new image datas (pixel's channel by pixel's channel)
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                // Old datas (pixel by pixel)
                pixelRGB *old_pixel = getPixel(data, width, height, nbChannels, i, j);

                // New datas (channel by channel)
                newData[(j * width + i) * nbChannels] = 0;
                newData[(j * width + i) * nbChannels + 1] = 0;
                newData[(j * width + i) * nbChannels + 2] = old_pixel->B;
                }
            }

        int write_result = write_image_data("image_out.bmp", newData, width, height);
        
        // Check write result
        if (write_result != 0) { 
            printf("Upload reussi ! \n");
        } else {
            printf("Error writing image\n");
        }
    }
    
    else {  
        printf("Error while reading image data\n");
    }
}

void color_gray(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);
    // Check if the image was read successfully
    if (results != 0) {

        // Allocating memory for the new image data
        unsigned char *newData = malloc(width * height * nbChannels * sizeof(unsigned char));

        // Creating the new image datas (pixel's channel by pixel's channel)
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                // Old datas (pixel by pixel)
                pixelRGB *old_pixel = getPixel(data, width, height, nbChannels, i, j);
                
                // Computing the average value of each pixel
                unsigned char value = (old_pixel->R + old_pixel->G + old_pixel->B) / 3;

                // New datas (channel by channel)
                newData[(j * width + i) * nbChannels] = value;
                newData[(j * width + i) * nbChannels + 1] = value;
                newData[(j * width + i) * nbChannels + 2] = value;
                }
            }

        int write_result = write_image_data("image_out.bmp", newData, width, height);
        
        // Check write result
        if (write_result != 0) { 
            printf("Upload reussi ! \n");
        } else {
            printf("Error writing image\n");
        }
    }
    
    else {  
        printf("Error while reading image data\n");
    }
}

void color_invert(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);
    // Check if the image was read successfully
    if (results != 0) {

        // Allocating memory for the new image data
        unsigned char *newData = malloc(width * height * nbChannels * sizeof(unsigned char));

        // Creating the new image datas (pixel's channel by pixel's channel)
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                // Old datas (pixel by pixel)
                pixelRGB *old_pixel = getPixel(data, width, height, nbChannels, i, j);

                // New datas (channel by channel)
                newData[(j * width + i) * nbChannels] = 255 - old_pixel->R;
                newData[(j * width + i) * nbChannels + 1] = 255 - old_pixel->G;
                newData[(j * width + i) * nbChannels + 2] = 255 - old_pixel->B;
                }
            }

        int write_result = write_image_data("image_out.bmp", newData, width, height);
        
        // Check write result
        if (write_result != 0) { 
            printf("Upload reussi ! \n");
        } else {
            printf("Error writing image\n");
        }
    }
    
    else {  
        printf("Error while reading image data\n");
    }
}

void color_gray_luminance(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);
    // Check if the image was read successfully
    if (results != 0) {

        // Allocating memory for the new image data
        unsigned char *newData = malloc(width * height * nbChannels * sizeof(unsigned char));

        // Creating the new image datas (pixel's channel by pixel's channel)
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                // Old datas (pixel by pixel)
                pixelRGB *old_pixel = getPixel(data, width, height, nbChannels, i, j);
                
                // Computing the average value of each pixel
                unsigned char value = 0.21 * old_pixel->R + 0.72 * old_pixel->G + 0.07 * old_pixel->B;

                // New datas (channel by channel)
                newData[(j * width + i) * nbChannels] = value;
                newData[(j * width + i) * nbChannels + 1] = value;
                newData[(j * width + i) * nbChannels + 2] = value;
                }
            }

        int write_result = write_image_data("image_out.bmp", newData, width, height);
        
        // Check write result
        if (write_result != 0) { 
            printf("Upload reussi ! \n");
        } else {
            printf("Error writing image\n");
        }
    }
    
    else {  
        printf("Error while reading image data\n");
    }
}

void color_desaturate(char *source_path) {
    unsigned char *data;
    int width, height, nbChannels, i, j, minChannel, maxChannel;

    // Read the image data
    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);
    // Check if the image was read successfully
    if (results != 0) {

        // Allocating memory for the new image data
        unsigned char *newData = malloc(width * height * nbChannels * sizeof(unsigned char));

        // Creating the new image datas (pixel's channel by pixel's channel)
        for (j = 0; j < height; j++) {
            for (i = 0; i < width; i++) {
                // Old datas (pixel by pixel)
                pixelRGB *old_pixel = getPixel(data, width, height, nbChannels, i, j);

                // Searching the minimum channel
                if ( old_pixel->R < old_pixel->G ) {
                    minChannel = fmin(old_pixel->R, old_pixel->B);
                }
                else {
                    minChannel = fmin(old_pixel->G, old_pixel->B);
                }

                // Searching the maximum channel
                if ( old_pixel->R < old_pixel->G ) {
                    maxChannel = fmax(old_pixel->G, old_pixel->B);
                }
                else {
                    maxChannel = fmax(old_pixel->R, old_pixel->B);
                }
                
                // Computing the average value of min and max
                unsigned char value = (maxChannel + minChannel) / 2;

                // New datas (channel by channel)
                newData[(j * width + i) * nbChannels] = value;
                newData[(j * width + i) * nbChannels + 1] = value;
                newData[(j * width + i) * nbChannels + 2] = value;
                }
            }

        int write_result = write_image_data("image_out.bmp", newData, width, height);
        
        // Check write result
        if (write_result != 0) { 
            printf("Upload reussi ! \n");
        } else {
            printf("Error writing image\n");
        }
    }
    
    else {  
        printf("Error while reading image data\n");
    }
}

void rotate_cw(char *source_path) {
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    int new_width = height;
    int new_height = width;
    unsigned char* new_data = malloc(new_width * new_height * n);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* p = getPixel(data, width, height, n, x, y);
            int new_x = height - 1 - y;
            int new_y = x;
            setPixel(new_data, new_width, new_height, n, new_x, new_y, p);
            free(p);
        }
    }

    write_image_data("image_out.bmp", new_data, new_width, new_height);


    free(data);
    free(new_data);
}

void rotate_acw(char *source_path) {
    unsigned char* data = NULL;
    int width = 0, height = 0, channel_count = 0;
    
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int new_width = height;
    int new_height = width;
    unsigned char* rotated_data = malloc(new_width * new_height * channel_count);
   
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channel_count; ++c) {
                rotated_data[((new_height - x - 1) * new_width + y) * channel_count + c] =
                    data[(y * width + x) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", rotated_data, new_width, new_height);

    free(data);
    free(rotated_data);
}

void mirror_horizontal(char *source_path) {
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    if (read_image_data(source_path, &data, &width, &height, &n) == 0) {
        
        return;
    }

    int new_width = width;
    int new_height = height;
    unsigned char* new_data = malloc(new_width * new_height * n);
    if (!new_data) {
        free_image_data(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* p = getPixel(data, width, height, n, x, y);
            int mirror_x = new_width - 1 - x;
            int mirror_y = y;
            setPixel(new_data, new_width, new_height, n, mirror_x, mirror_y, p);
            free(p);
        }
    }

    write_image_data("image_out.bmp", new_data, new_width, new_height);

    free_image_data(data);
    free(new_data);
}

void mirror_vertical(char* source_path) {
    unsigned char* data = NULL;
    int width=0, height=0, channel_count=0;
    read_image_data(source_path, data, width, height, channel_count);
    printf("dimensions: %d, %d",width,height);
}

void scale_crop(char *source_path, int center_x, int center_y, int width, int height){
    unsigned char* data = NULL;
    int original_width, original_height, n, x, y;
    read_image_data(source_path, &data, &original_width, &original_height, &n);
    int first_x = center_x - width/2;
    int first_y = center_y - height/2;
 
    if (first_x<0) first_x=0;
    if (first_y<0) first_y=0;
    if (first_x + width > original_width) width = original_width - first_x;
    if (first_y + height > original_height) height = original_height - first_y;
 
   
    unsigned char* cropped_data = malloc(width*height*n);
   
    for ( y=0; y < height;y++){
        for(x=0; x < width;x++){
            pixelRGB* current_original_pixel = getPixel(data, original_width, original_height, n, x + first_x, y + first_y);
            pixelRGB* current_data_cropped_pixel = getPixel(cropped_data, width, height, n, x, y);
            current_data_cropped_pixel->R=current_original_pixel->R;
            current_data_cropped_pixel->G=current_original_pixel->G;
            current_data_cropped_pixel->B=current_original_pixel->B;
        }
    }
    write_image_data("image_out.bmp",cropped_data,width,height);
}
