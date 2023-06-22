#pragma once
#include "Entry.h"

class IntegerData : public Entry {
private:
	int value;
public:
	IntegerData(std::string, std::string);
	void Add(std::string) override final;
	bool Substract(int) override final;
	void Print() override final;
};
