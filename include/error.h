#ifndef ERROR_H
#define ERROR_H

#include <iostream>

void error(std::string msg, int err_code);
void error_fatal(std::string msg, int err_code);

#endif
