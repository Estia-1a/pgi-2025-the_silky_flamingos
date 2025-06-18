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

void dimension(char *source_path){
    unsigned char* data=NULL;
    int width=0, height=0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension : %d, %d", width, height);
}

void first_pixel (char *source_path){
    unsigned char* data=NULL;
    int width=0, height=0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("RGB : %d, %d, %d", data[0], data[1], data[2]);
}

void tenth_pixel (char *source_path){
    unsigned char* data=NULL;
    int width=0, height=0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("RGB : %d, %d, %d", data[27], data[28], data[29]);
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

    read_image_data(source_path, &data, &width, &height, &n);

    unsigned char* new_data = malloc(width * height * n);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* p = getPixel(data, width, height, n, x, y);
            int mirror_x = width - 1 - x;
            int mirror_y = y;
            setPixel(new_data, width, height, n, mirror_x, mirror_y, p);
            free(p);
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);

    free_image_data(data);
    free(new_data);
}


