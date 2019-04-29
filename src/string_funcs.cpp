#include "../include/string_funcs.h"

std::string convertIdentifier(std::string str) {
	auto it = str.begin();
	*it = toupper(*it);
	while(it != str.end()) {
		if(*it == '_') {
			str.erase(it);
			*it = toupper(*it);
		}
		++it;
	}
	return str;
}

std::string convertFunction(std::string str) {
	auto it = str.begin();
	*it = tolower(*it);
	while(it != str.end()) {
		if(isupper(*it)) {
			*it = tolower(*it);
			str.insert(it, '_');
		}
		++it;
	}
	return str;
}

std::string includeGuard(std::string str) {
	auto it = str.begin();
	if(islower(*it)) {
		*it = toupper(*it);
	}
	++it;
	while(it != str.end()) {
		if(isupper(*it)) {
			str.insert(it, '_');
			++it;
		}
		*it = toupper(*it);
		++it;
	}
	str += "_H";
	return str;
}
