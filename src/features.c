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
    printf("Hello World !!!");
}

/**
 * @brief This function reads the image and prints its dimensions.
 * @param[in] source_path : path to the image to be read
 * To try :
 * ./freud.exe --debug -f ../images/input/image.jpeg -c dimension
 */ 
void dimension (char *source_path) {
    unsigned char *data;
    int width, height, nbChannels;

    printf("source_path: %s\n", source_path);

    int results = read_image_data(source_path, &data, &width, &height, &nbChannels);

    // Check if the image was read successfully
    if (results != 0) {
        printf("dimension: %d, %d", width, height);
    }

    else {
        printf("Error while reading image data\n");
    }    
}
void dimension(char *source_path){
    unsigned char *data;
    int width=0, height=0, channel_count=0; 
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension : %d, %d",width,height);
}