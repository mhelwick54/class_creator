#ifndef CLASS_STRUCT_H
#define CLASS_STRUCT_H

#include <vector>
#include <utility>
#include <string>
#include <tuple>
#include <iostream>
#include <cctype>

#include "string_funcs.h"

class NewClass {
private:
	std::string class_name;
	bool is_template;
	std::vector<std::pair<std::string, std::string>> data_members;
	std::vector<std::tuple<std::string, std::string, std::vector<std::pair<std::string, std::string>>>> sets;
	std::vector<std::tuple<std::string, std::string, std::vector<std::pair<std::string, std::string>>>> gets;
	std::vector<std::tuple<std::string, std::string, std::vector<std::pair<std::string, std::string>>>> funcs;
public:
/*****************************************************Constructors/Destructors*/
	NewClass();
	NewClass(std::string class_name);

/**********************************************************************Get/Set*/
	void setName(std::string class_name) { this->class_name = class_name; }
	std::string getName() { return this->class_name; }
	void setTemplate(bool is_template) { this->is_template = is_template; }
	bool getTemplate() { return this->is_template; }

/**********************************************************************Methods*/
	void createClass(std::string class_name, bool is_template);
	void addDataMember(std::string member_name, std::string member_type);
	void addFunction(std::string func_name, std::string return_type, std::vector<std::pair<std::string, std::string>> args);
	void createGetsSets();
	void printCpp(std::ostream& os);

/********************************************************************Overloads*/
	friend std::ostream& operator<<(std::ostream& os, const NewClass& cls);
};

#endif
