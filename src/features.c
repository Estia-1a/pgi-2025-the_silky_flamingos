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
    printf("Hello World bro!");
}

void dimension(char *source_path){
    unsigned char* data = NULL;
    int width=0, height=0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimensions: %d, %d",width,height);
}

void first_pixel (char *source_path){
    unsigned char* data =NULL;
    int width=0, height=0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("color: %d, %d, %d", data[0], data[1], data[2]);

}

void tenth_pixel (char *source_path){
    unsigned char* data =NULL;
    int width=0, height=0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("color: %d, %d, %d", data[27], data[28], data[29]);
}

void second_line(char *source_path){
    unsigned char* data =NULL;
    int width=0, height=0, channel_count=0;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("second_line: %d, %d, %d", data[4464], data[4465], data[4466]);
}

void scale_crop(const char* in, int cx, int cy, int cw, int ch){
    
    const char* out ="output.png";
    unsigned char* data = NULL;
    int iw = 0, ih = 0, c = 0;

    int success = read_image_data(in, &data, &iw, &ih, &c);
    if (!success) {
        printf("Erreur : Impossible de charger l'image '%s'\n", in);
        return;
    }

    unsigned char* crop = malloc(cw * ch * c);
    if (!crop) {
        printf("Erreur : Échec de l'allocation mémoire pour le crop\n");
        free_image_data(data);
        return;
    }

    int sx = cx - cw / 2;
    int sy = cy - ch / 2;

    for (int y = 0; y < ch; y++) {
        for (int x = 0; x < cw; x++) {
            for (int i = 0; i < c; i++) {
                int xi = sx + x;
                int yi = sy + y;
                int dst_index = (y * cw + x) * c + i;

                if (xi >= 0 && xi < iw && yi >= 0 && yi < ih) {
                    int src_index = (yi * iw + xi) * c + i;
                    crop[dst_index] = data[src_index];
                } else {
                    crop[dst_index] = 0;
                }
            }
        }
    }

    success = write_image_data(out, crop, cw, ch);
    if (!success) {
        printf("Erreur : Impossible d'écrire l'image '%s'\n", out);
    }

    free_image_data(data);
    free(crop);

    printf("Image d'entrée : %s\n", in);
    printf("Image de sortie (crop) : %s\n", out);
}