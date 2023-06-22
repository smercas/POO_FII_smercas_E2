#pragma once
#include <vector>
#include "Procesor.h"

class Sentence {
private:
	std::vector<Procesor*> procesators;
	std::string name;
public:
	Sentence(std::string name);
	void RunAll();
	void ListAll();
	void Run(std::string);
	Sentence& operator+=(Procesor* procesor);
};
