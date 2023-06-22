#pragma once
#include "Printer.h"
class Hexazecimal : public Printer {
public:
	virtual std::string GetFormatName() override final;
	virtual std::string FormatNumber(int) override final;
};
