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
            pixelRGB* current_original_pixel = get_pixel(data, original_width, original_height, n, x + first_x, y + first_y);
            pixelRGB* current_data_cropped_pixel = get_pixel(cropped_data, width, height, n, x, y);
            current_data_cropped_pixel->R=current_original_pixel->R;
            current_data_cropped_pixel->G=current_original_pixel->G;
            current_data_cropped_pixel->B=current_original_pixel->B;
        }
    }
    const char *output_file = "image_out.png";
    if (!write_image_data(output_file, cropped_data, width, height)) {
        fprintf(stderr, "Erreur lors de la sauvegarde de l'image : %s\n", output_file);
    } else {
        printf("Image recadrée sauvegardée : %s\n", output_file);
        system("start image_out.png");  
   
}
}