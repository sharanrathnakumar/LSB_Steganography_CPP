#include "../include/header.h"

int fileValidation(char * filename, char * secretTextname) {
	
	if(!strstr(filename, ".bmp")) {
		std::cerr << "Please give a .bmp file" << std::endl;
		return -1;
	} else {
		//TODO: It is a bmp file, move to the next validation part
		FILE *fptr = fopen(filename, "rb");

		if(fptr == NULL) {
			std::cerr << "ERROR: Unable to open the " << filename << std::endl;
			return -1;
		} else {
			long imageSize = fileSize(fptr);
			if (imageSize > 0) {
				FILE *secretFptr = fopen(secretTextname, "rb");
				long secretTextSize = fileSize(secretFptr);

				if(secretTextSize == -1) {
					std::cerr << "ERROR: The secret text file is invalid" << std::endl;
					return -1;
				}

				long minEncodableSize = 54 + (secretTextSize * 8); // First 54 byte header and remaining byte for text file, each bit of the textfile will require one byte of the pixel.

				if (imageSize > minEncodableSize) {
					std::cout << "INFO: The secret text can be encoded to the image file" << std::endl;
					return 1;
				} else {
					std::cerr << "ERROR: The size of the image is too short to encode the text file" << std::endl;
					return -1;
				}

			} else {
				std::cerr << "ERROR: Invalid Image File" << std::endl;
				return -1;
			}

		}
		return 1;
	}
}

long fileSize(FILE* fptr) {

	if(fptr == NULL) {
		std::cerr << "ERROR: File Validation failed" << std::endl;
		return -1;
	}

	fseek(fptr, 0, SEEK_END);
    long size = ftell(fptr);
    fclose(fptr);

	return size;
}
