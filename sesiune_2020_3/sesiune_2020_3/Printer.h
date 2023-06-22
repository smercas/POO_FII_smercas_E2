#pragma once
#include <string>

class Printer {
public:
	virtual std::string GetFormatName() = 0;
	virtual std::string FormatNumber(int) = 0;
};
