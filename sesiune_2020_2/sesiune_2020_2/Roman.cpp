#include "Roman.h"

Roman::Roman(std::string nume, std::string autor) {
	this->nume = nume;
	this->autor = autor;
}
std::string Roman::GetInfo() {
	return "Roman " + nume + " de " + autor;
}
