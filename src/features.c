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
    int width = 0, height = 0, channel_count = 0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    unsigned char* rotated_data = malloc(width * height * channel_count);
    if (!rotated_data) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channel_count; ++c) {
                int src_index = (y * width + x) * channel_count + c;
                int dest_index = ((x * height) + (height - 1 - y)) * channel_count + c;
                rotated_data[dest_index] = data[src_index];
            }
        }
    }
    write_bmp_image("image_out.bmp", rotated_data, height, width, channel_count);
    free(data);
    free(rotated_data);
}

