#pragma once
#include <string>

class Procesor {
public:
	virtual std::string GetName() = 0;
	virtual int Compute(std::string) = 0;
};
