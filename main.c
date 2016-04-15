#include <stdio.h>
#include <stdlib.h>
#include "brain.h"
#include "bmp.h"

int main(int argc, char** argv) {
	
	BmpData* bmp;
	Brain* brain;
	double* result;
	double* fractional_RGB;

	bmp = Bitmap_getColorData("TRU.BMP");
	fractional_RGB = (double *)malloc(bmp->width * bmp->height * sizeof(double));

	for (int i = 0; i < bmp->width * bmp->height; i++) {
		fractional_RGB[i] = ((double)bmp->image_data[i]) / 255.0;
	}

	brain = Brain_new(bmp->width * bmp->height, 1, 3, 5);

	Brain_feedForward(brain, fractional_RGB);
	Brain_print(brain);

	return 0;

}
