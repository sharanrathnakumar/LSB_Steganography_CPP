#include<iostream>
#include<cstring>

int main(int argc, char *argv[])
{

	if( argc <= 1) {
		std::cout << "Usage:\nFor LSB Encoding: ./lsb_steg -e <.bmp file> <.textfile> [output]\nLSB Decoding: ./lsb_steg -d <.bmp file> [output]" << std::endl;
	} else if(argc == 2 && ! strcmp(argv[1], "-e")){
		std::cout << "Error: For Encoding please pass the text file to be encoded as the third argument" << std::endl;
	} else {
		//TODO: Implementation for the file validation
	}
	return 0;
}
