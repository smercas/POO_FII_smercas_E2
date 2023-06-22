#pragma once
#include "Entry.h"

class StringData : public Entry {
private:
	std::string value;
public:
	StringData(std::string, std::string);
	void Add(std::string) override final;
	bool Substract(int) override final;
	void Print() override final;
};
