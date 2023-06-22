#pragma once
#include <array>
#include "printer.h"

class Number {
private:
	int number;
	int count;
	std::array<Printer*, 100> printers;
public:
	Number(int);
	operator int();
	Number operator+(const Number&);
	Number operator-(const Number&);
	Number operator*(const Number&);
	Number operator/(const Number&);
	Number& operator+=(Printer*);
	void Print();
};
