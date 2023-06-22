#include <iostream>
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
	this->carti.fill(nullptr);
	this->count = 0;
}

Biblioteca::~Biblioteca() {
	this->count = 0;
}

Biblioteca& Biblioteca::operator+=(Carte* carte) {
	this->carti[count] = carte;
	++this->count;
	return *this;
}

std::array<Carte*, 100>::iterator Biblioteca::begin()
{
	return this->carti.begin();
}

std::array<Carte*, 100>::iterator Biblioteca::end()
{
	return this->carti.begin() + count;
}

Biblioteca::operator int() {
	return this->count;
}
void Biblioteca::PrintFilter(bool (*filter_function)(Carte*)) {
	for (Carte* carte : this->carti) {
		if (filter_function(carte)) {
			std::cout << carte->GetInfo() << std::endl;
		}
	}
}
