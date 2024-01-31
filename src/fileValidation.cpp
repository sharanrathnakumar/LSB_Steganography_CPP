#include "../include/header.h"

int fileValidation(char * filename) {
	
	if(!strstr(filename, ".bmp")) {
		std::cerr << "Please give a .bmp file" << std::endl;
		return 0;
	} else {
		//TODO: It is a bmp file, move to the next validation part
		FILE *fptr = fopen(filename, "r");

		if(fptr == NULL) {
			std::cerr << "ERROR: Unable to open the " << filename << std::endl;
			return 0;
		} else {
			//TODO:File size need to be calculated and check the feasibilty of encoding the secret text data to it.
		}
		return 1;
	}
}
