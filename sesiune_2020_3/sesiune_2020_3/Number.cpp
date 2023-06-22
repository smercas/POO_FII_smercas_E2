#include <iostream>
#include "Number.h"

Number::Number(int value) {
	this->number = value;
	this->count = 0;
	this->printers.fill(nullptr);
}
Number::operator int() {
	return this->number;
}
Number Number::operator+(const Number& n) {
	return Number(this->number + n.number);
}
Number Number::operator-(const Number& n) {
	return Number(this->number - n.number);
}
Number Number::operator*(const Number& n) {
	return Number(this->number * n.number);
}
Number Number::operator/(const Number& n) {
	return Number(this->number / n.number);
}
Number& Number::operator+=(Printer* prnt) {
	this->printers[this->count] = prnt;
	++this->count;
	return *this;
}
void Number::Print() {
	for (Printer* printer : printers) {
		if (printer) {
			std::cout << "Format: " << printer->GetFormatName() << "  Value: " << printer->FormatNumber(this->number) << std::endl;
		}
	}
}
