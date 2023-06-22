#pragma once
#include "Procesor.h"

class CountLetter : public Procesor {
private:
	std::string name;
	bool(*function)(char);
public:
	CountLetter(std::string, bool(*)(char));
	virtual std::string GetName() override final;
	virtual int Compute(std::string) override final;
};
