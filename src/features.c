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

void scale_crop(const char* in, const char* out, int cx, int cy, int w, int h){
    int iw, ih, c;
    unsigned char* img = stbi_load(in, &iw, &ih, &c, 0);
    if (!img) return;

    unsigned char* crop = malloc(w * h * c);
    int sx = cx - w / 2, sy = cy - h / 2;

    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            for (int i = 0; i < c; i++) {
                int xi = sx + x, yi = sy + y;
                int d = (y * w + x) * c + i;
                if (xi >= 0 && xi < iw && yi >= 0 && yi < ih)
                    crop[d] = img[(yi * iw + xi) * c + i];
                else
                    crop[d] = 0;
            }   
        }   
    }    
    stbi_write_png(out, w, h, c, crop, w * c);
    stbi_image_free(img);
    free(crop);
    printf("input.jpg", "output.png", 500, 600, 300, 400);
}