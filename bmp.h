#ifndef BMP_H
#define BMP_H

#include "types.h"

#pragma pack(push, 1)

typedef struct BmpFileHeader BmpFileHeader;
typedef struct BmpData BmpData;

struct BmpFileHeader {
	uint16 magic_number;	/* magic word of BMP, should be 0x424D */
	uint32 bmp_size;		/* size of BMP file in bytes */
	uint16 reserved[2];		/* reserved section */
	uint32 offset;			/* offset of image data */
};

struct BmpData {
	uint32 header_size;		/* size for the data header */
	sint32 width;			/* width of the image */
	sint32 height;			/* height of the image */
	uint16 planes;			/* number of color planes */
	uint16 bpp;				/* bits per pixel */
	uint32 compression;		/* compression method being used */
	uint32 raw_size;		/* raw bitmap data size */
	sint32 horizontal_res;	/* horizontal resolution */
	sint32 vertical_res;	/* vertical resolution */
	uint32 num_colors;		/* numbers of colors in the palette */
	uint32 important_num;	/* number of important colors */

	uint8* image_data;		/* allocated by Bitmap_getColorData */
};

BmpData* Bitmap_getColorData(const sint8*);

#endif
