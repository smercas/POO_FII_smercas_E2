#pragma once
#include "Carte.h"
class Revista : public Carte {
private:
	std::string titlu;
	int nrArticole;
public:
	Revista(std::string, int);
	virtual std::string GetInfo() override final;
};
