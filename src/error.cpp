#include "../include/error.h"

void error(std::string msg, int err_code) {
	std::cout << "Error " << err_code << ": " << msg << "\n";
}

void error_fatal(std::string msg, int err_code) {
	std::cout << "Fatal error " << err_code << ": " << msg << "\n";
	exit(err_code);
}
