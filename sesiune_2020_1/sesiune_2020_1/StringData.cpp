#include <iostream>
#include "StringData.h"

StringData::StringData(std::string name, std::string value) : Entry(name) {
	this->value = value;
}
void StringData::Add(std::string toAdd) {
	this->value += toAdd;
	//this->value.append(toAdd);
}
bool StringData::Substract(int toSubstract) {
	if (this->value.size() >= toSubstract) {
		this->value.erase(this->value.size() - toSubstract, toSubstract);
		return true;
	}
	else {
		std::cout << "StringData: len(" << this->value << ") < " << toSubstract << std::endl;
		return false;
	}
}
void StringData::Print() {
	std::cout << this->value;
}
