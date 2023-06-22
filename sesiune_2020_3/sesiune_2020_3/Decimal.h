#pragma once
#include "Printer.h"
class Decimal : public Printer {
	virtual std::string GetFormatName() override final;
	virtual std::string FormatNumber(int) override final;
};
