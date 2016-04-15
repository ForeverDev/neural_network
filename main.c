#include <stdio.h>
#include <stdlib.h>
#include "brain.h"
#include "bmp.h"

int main(int argc, char** argv) {
	
	/*
	const double data[] = {
		0, 0.2, 0, 0, 0.3
	};

	double* result;

	Brain* brain = Brain_new(3, 4, 2, 4);

	Brain_feedForward(brain, data);
	result = Brain_getOutput(brain);

	Brain_print(brain);
	printf("%f\n", result[0]);
	*/

	const BmpData* bmp = Bitmap_getColorData("TRU.BMP");

	for (int i = 0; i < bmp->raw_size; i += 3) {
		printf("%03d %03d %03d\n", bmp->image_data[i], bmp->image_data[i + 1], bmp->image_data[i + 2]);
	}

	return 0;

}
