#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

BmpData* Bitmap_getColorData(const char* filename) {
	FILE* file_handle = NULL;
	BmpFileHeader file_header;
	BmpData* data_header = (BmpData *)malloc(sizeof(BmpData));

	file_handle = fopen(filename, "rb");
	if (!file_handle) {
		return NULL;
	}

	fread(&file_header, sizeof(BmpFileHeader), 1, file_handle);

	if (file_header.magic_number != 0x4d42) {
		fclose(file_handle);
		printf("Expected bitmap file\n");
		return NULL;
	}

	fread(data_header, sizeof(BmpData) - sizeof(uint8 *), 1, file_handle);
	fseek(file_handle, file_header.offset, SEEK_SET);

	data_header->image_data = (uint8 *)malloc(data_header->raw_size);
	if (!data_header->image_data) {
		fclose(file_handle);
		return NULL;
	}

	fread(data_header->image_data, data_header->raw_size, 1, file_handle);
	if (!data_header->image_data) {
		fclose(file_handle);
		return NULL;
	}

	// BMP is stored as BGR, swap R and B
	for (int i = 0; i < data_header->raw_size; i += 3) {
		uint8 temp = data_header->image_data[i];
		data_header->image_data[i] = data_header->image_data[i + 2];
		data_header->image_data[i + 2] = temp;
	}

	fclose(file_handle);

	return data_header;
}
