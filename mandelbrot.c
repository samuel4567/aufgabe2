#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Include that allows to print result as an image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Default size of image
#define X 1280
#define Y 720
#define MAX_ITER 10000

void calc_mandelbrot(uint8_t image[Y][X]) {
	// TODO: Write your code here!
	for(int i=0;i<Y;i++){
        for(int j=0;j<X;j++){
            float x = 0.0;
            float y = 0.0;
            float cx =X/(float)j;
            float cy = Y/(float)i;
            int k;
	    float x_tmp;
            for(k=0;k<MAX_ITER && x*x + y*y <= 2*2;k++){
                x_tmp = x*x - y*y + cx;
                y = 2*x*y + cy;
                x = x_tmp;
            }
            int  norm_iteration = k%255;
            image[i][j] = norm_iteration;
    }
    }
}

int main() {
	uint8_t image[Y][X];

	calc_mandelbrot(image);

	const int channel_nr = 1, stride_bytes = 0;
	stbi_write_png("mandelbrot.png", X, Y, channel_nr, image, stride_bytes);
	return EXIT_SUCCESS;
}

