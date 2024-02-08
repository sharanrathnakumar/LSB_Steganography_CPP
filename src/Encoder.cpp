#include "../include/header.h"

int EncodeTextInToImage(char *ImageFname, char *TextFname) {
	//TODO: Implementation of Encoder function
	FILE *ImgPtr, *TextPtr, *EncImgPtr;
	char * buffer[54];

	ImgPtr = fopen(ImageFname, "rb");
	TextPtr = fopen(TextFname, "rb");
	EncImgPtr = fopen("EncodedImage.bmp","wb");

	if (ImgPtr == NULL || TextPtr == NULL || EncImgPtr) {
		std::cerr << "ERROR: Unable to open the file." << std::endl;
		return -1;
	}

	size_t bytesRead = fread(buffer, 1, 54, ImgPtr);
	
	if (bytesRead != 54) {
		std::cerr << "ERROR: Reading data from image failed" << std::endl;
		fclose(ImgPtr);
		fclose(TextPtr);
		fclose(EncImgPtr);
		return -1;
	}

	//INFO: Copying first 54 bytes [Image header]
	size_t bytesWritten = fwrite(buffer, 1, bytesRead, EncImgPtr);
	 if (bytesWritten != bytesRead) {
		 std::cerr << "Error writing to output file" << std::endl;
        fclose(ImgPtr);
        fclose(TextPtr);
        fclose(EncImgPtr);
        return -1;
    }	
	std::cout << "INFO: Image header copied successfully" << std::endl;

	fseek(TextPtr, 0, SEEK_END);
	long TextFileSize = ftell(TextPtr);

	if(TextFileSize == -1) {
		std::cerr << "ERROR: Unable to get the size of the Text file" << std::endl;
		return -1;
	}
	rewind(TextPtr);

	return -1;
}

