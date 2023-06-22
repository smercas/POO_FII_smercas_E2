#pragma once
#include <array>
#include "Carte.h"

class Biblioteca {
private:
	std::array<Carte*, 100> carti;
	int count;
public:
	Biblioteca();
	~Biblioteca();
	Biblioteca& operator+=(Carte* carte);
	std::array<Carte*, 100>::iterator begin();
	std::array<Carte*, 100>::iterator end();
	operator int();
	void PrintFilter(bool(*)(Carte*));
};

