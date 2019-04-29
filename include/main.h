#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

#include "error.h"
#include "class_structure.h"
#include "string_funcs.h"

int menu();
void create_class(std::unique_ptr<NewClass> &cls);
void add_data_member(std::unique_ptr<NewClass> &cls);
void create_get_set(std::unique_ptr<NewClass> &cls);
void add_function(std::unique_ptr<NewClass> &cls);
void print_to_file(std::unique_ptr<NewClass> &cls);

#endif
