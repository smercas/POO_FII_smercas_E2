#pragma once
#include <string>

class Entry {
protected:
	std::string name;
public:
	Entry(std::string);
	std::string GetName();
	virtual void Add(std::string) = 0;
	virtual bool Substract(int) = 0;
	virtual void Print() = 0;
};
