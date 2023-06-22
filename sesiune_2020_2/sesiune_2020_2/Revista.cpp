#include "Revista.h"

Revista::Revista(std::string titlu, int nrArticole) {
	this->titlu = titlu;
	this->nrArticole = nrArticole;
}
std::string Revista::GetInfo() {
	return "Revista " + titlu + " cu " + std::to_string(nrArticole) + " articole";
}
