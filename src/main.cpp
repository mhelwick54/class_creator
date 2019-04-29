#include "../include/main.h"

int main() {
	int menu_choice = -1;
	auto cls = std::make_unique<NewClass>();
	do {
		menu_choice = menu();
		switch(menu_choice) {
			case 1: create_class(cls);
				break;
			case 2: add_data_member(cls);
				break;
			case 3: create_get_set(cls);
				break;
			case 4:	add_function(cls);
				break;
			case 5: print_to_file(cls);
				break;
			default: error("unkown option", menu_choice);
		}
	} while(menu_choice != 5);

	return 0;
}

int menu() {
	int choice = -1;
	std::cout << "\tMenu\n";
	std::cout << "+------------------------------------------------------------------------------+\n";
	std::cout << "\t\t1. Create class\n";
	std::cout << "\t\t2. Add data member\n";
	std::cout << "\t\t3. Create gets/sets\n";
	std::cout << "\t\t4. Add function\n";
	std::cout << "\t\t5. Write to file and exit\n";
	std::cout << "Selection: ";
	std::cin >> choice;
	return choice;
}

void create_class(std::unique_ptr<NewClass> &cls) {
	std::cout << "Enter class name: ";

	std::string name;
	std::cin >> name;

	char temp = false;
	std::cout << "Is this class a template? (Y/N) ";
	std::cin >> temp;
	bool is_template = (temp == 'Y' || temp == 'y') ? true : false;

	cls->createClass(name, is_template);
	std::cout << *cls.get();
}

void add_data_member(std::unique_ptr<NewClass> &cls) {
	std::cout << "Enter type: ";
	std::string type_name;
	std::cin >> type_name;
	std::cout << "Enter identifier: ";
	std::string name;
	std::cin >> name;
	cls->addDataMember(name, type_name);
	std::cout << *cls.get();
}

void create_get_set(std::unique_ptr<NewClass> &cls) {
	cls->createGetsSets();
	std::cout << *cls.get();
}

void add_function(std::unique_ptr<NewClass> &cls) {
	std::cout << "Enter function name: ";
	std::string name;
	std::cin >> name;
	std::cout << "Enter return type: ";
	std::string ret_type;
	std::cin >> ret_type;
	char choice;
	std::vector<std::pair<std::string, std::string>> args;
	do {
		std::cout << "Enter argument? (Y/N): ";
		std::cin >> choice;
		if(choice == 'n' || choice == 'N') {
			break;
		}
		std::cout << "Enter type: ";
		std::string arg_type;
		std::cin >> arg_type;
		std::cout << "Enter identifier: ";
		std::string arg;
		std::cin >> arg;
		args.push_back(std::make_pair(arg_type, arg));
	} while(choice == 'Y' || choice == 'y');
	cls->addFunction(name, ret_type, args);
	std::cout << *cls.get();
}

void print_to_file(std::unique_ptr<NewClass> &cls) {
	std::cout << "Enter file path: ";
	std::string path;
	std::cin >> path;
	mkdir(path.c_str(), 0777);
	mkdir((path + "include/").c_str(), 0777);
	mkdir((path + "bin/").c_str(), 0777);
	mkdir((path + "src/").c_str(), 0777);
	std::ofstream out;
	std::string file_name = path + "include/" + convertFunction((*cls.get()).getName()) + ".h";
	out.open(file_name.c_str());
	out << *cls.get();
	out.close();
	file_name = path + "src/" + convertFunction((*cls.get()).getName()) + ".cpp";
	out.open(file_name.c_str());
	cls->printCpp(out);
	out.close();
}
