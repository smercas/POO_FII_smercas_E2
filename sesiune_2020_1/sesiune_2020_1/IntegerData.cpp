#include <iostream>
#include "IntegerData.h"

IntegerData::IntegerData(std::string name, std::string value) : Entry(name) {
	this->value = stoi(value);
}
void IntegerData::Add(std::string toAdd) {
	value += stoi(toAdd);
}
bool IntegerData::Substract(int toSubstract) {
	value -= toSubstract;
	return true;
}
void IntegerData::Print() {
	std::cout << value;
}
