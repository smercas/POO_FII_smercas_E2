#pragma once
#include <string>
#include "Carte.h"

class Roman : public Carte {
private:
	std::string nume;
	std::string autor;
public:
	Roman(std::string, std::string);
	virtual std::string GetInfo() override final;
};
