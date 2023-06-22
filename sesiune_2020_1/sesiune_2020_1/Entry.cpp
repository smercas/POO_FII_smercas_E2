#include "Entry.h"

Entry::Entry(std::string name) {
	this->name = name;
}

std::string Entry::GetName() {
	return this->name;
}
