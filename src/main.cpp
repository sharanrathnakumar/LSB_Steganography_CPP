#include "../include/header.h"

int main(int argc, char *argv[])
{

	if( argc <= 2) {
		std::cout << "Usage:\nFor LSB Encoding: ./lsb_steg -e <.bmp file> <.textfile> [output]\nLSB Decoding: ./lsb_steg -d <.bmp file> [output]" << std::endl;
	} else if(argc == 3 && ! strcmp(argv[1], "-e")) {
		std::cout << "Error: For Encoding please pass the text file to be encoded as the third argument" << std::endl;
	} else {
		//INFO: Argument validation successfull
		if(fileValidation(argv[2],argv[3]) == 1) {
			//TODO: File validation successfull
			std::cout << "INFO: File Validation is successfull" << std::endl;

			if(!strcmp(argv[1],"-e")) {
				std::cout << "INFO: Encoding started" << std::endl;

				if(EncodeTextInToImage(argv[2],argv[3]) == 1) {
					//TODO: Implement the encoding function
					std::cout << "INFO: Encoding succesfull" << std::endl;
					return 0;
				} else  {
					std::cerr << "ERROR: Encoding failed." << std::endl;
					return -1;
				}
			} else if (!strcmp(argv[1],"-d")){
				std::cout << "INFO: Decoding started" << std::endl;
				//TODO: Implement the decoding function
			} else {
				std::cerr << "ERROR: Invalid Entry. Use -e for encoding or -d for decoding" << std::endl;
			}

		} else {
			std::cout << "ERROR: File validation failed\nExiting" << std::endl;
			return -1;
		}
	}
	return 0;
}
