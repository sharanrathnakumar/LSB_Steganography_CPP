#include "../include/header.h"

int main(int argc, char *argv[])
{

	if( argc <= 2) {
		std::cout << "Usage:\nFor LSB Encoding: ./lsb_steg -e <.bmp file> <.textfile> [output]\nLSB Decoding: ./lsb_steg -d <.bmp file> [output]" << std::endl;
	} else if(argc == 3 && ! strcmp(argv[1], "-e")) {
		std::cout << "Error: For Encoding please pass the text file to be encoded as the third argument" << std::endl;
	} else {
		if(fileValidation(argv[2],argv[3]) == 1) {
			//TODO: File validation successfull
			std::cout << "INFO: File Validation is successfull" << std::endl;
		} else {
			std::cout << "ERROR: File validation failed\nExiting" << std::endl;
			return -1;
		}
	}
	return 0;
}
