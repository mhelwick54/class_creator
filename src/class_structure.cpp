#include "../include/class_structure.h"

NewClass::NewClass() {}

NewClass::NewClass(std::string class_name) {
	 this->class_name = class_name;
}

void NewClass::createClass(std::string class_name, bool is_template) {
	this->class_name = class_name;
	this->is_template = is_template;
}

void NewClass::addDataMember(std::string member_name, std::string member_type) {
	auto p = std::make_pair(member_type, member_name);
	this->data_members.push_back(p);
}

void NewClass::addFunction(std::string func_name, std::string return_type, std::vector<std::pair<std::string, std::string>> args) {
	auto t = std::make_tuple(return_type, func_name, args);
	this->funcs.push_back(t);
}

void NewClass::createGetsSets() {
	//sets
	for(auto mem : this->data_members) {
		std::vector<std::pair<std::string, std::string>> args;
		std::string name = convertIdentifier(mem.second);
		args.push_back(std::make_pair(mem.first, mem.second));
		auto t = std::make_tuple("void", "set" + name, args);
		this->sets.push_back(t);
	}
	//gets
	for(auto mem : this->data_members) {
		std::vector<std::pair<std::string, std::string>> args;
		std::string name = convertIdentifier(mem.second);
		auto t = std::make_tuple(mem.first, "get" + name, args);
		this->gets.push_back(t);
	}
}

void NewClass::printCpp(std::ostream& os) {
	os << "#include \"../include/" << convertFunction(this->class_name) + ".h" << "\"\n\n";
	for(auto func : this->funcs) {
		os << std::get<0>(func) << " " << this->class_name << "::" << std::get<1>(func) << "(";
		for(auto arg : std::get<2>(func)) {
			os << arg.first << " " << arg.second;
			if(arg != (std::get<2>(func)).back()) {
				os << ", ";
			}
		}
		os << ") {\n\n}\n\n";
	}
}

std::ostream& operator<<(std::ostream& os, const NewClass& cls) {
	os << "#ifndef " << includeGuard(cls.class_name) << "\n" << "#define ";
	os << includeGuard(cls.class_name) << "\n\n";
	if(cls.is_template) {
		os << "template <typename T>\n";
	}
	os << "class " << cls.class_name << " {\nprivate:\n";
	for(auto member : cls.data_members) {
		os << "\t" << member.first << " " << member.second << ";\n";
	}
	os << "public:\n";
	os << "\t/*****************************************************Constructors/Destructors*/\n";
	os << "\t" << cls.class_name << "();\n";
	os << "\t/**********************************************************************Get/Set*/\n";
	for(auto mem : cls.sets) {
		os << "\t" << std::get<0>(mem) << " " << std::get<1>(mem) << "(";
		auto arg = std::get<2>(mem).begin();
		os << arg->first << " " << arg->second;
		os << ") { this->" << arg->second << " = " << arg->second << "; }\n";
	}
	for(auto mem : cls.gets) {
		os << "\t" << std::get<0>(mem) << " " << std::get<1>(mem) << "() { ";
		os << "return this->" << convertFunction(std::get<1>(mem)) << "; }\n";
	}
	os << "\t/**********************************************************************Methods*/\n";
	for(auto func : cls.funcs) {
		os << "\t" << std::get<0>(func) << " " << std::get<1>(func) << "(";
		for(auto arg : std::get<2>(func)) {
			os << arg.first << " " << arg.second;
			if(arg != (std::get<2>(func)).back()) {
				os << ", ";
			}
		}
		os << ");\n";
	}
	os << "\t/********************************************************************Overloads*/\n";
	os << "};\n\n#endif";
	return os;
}
