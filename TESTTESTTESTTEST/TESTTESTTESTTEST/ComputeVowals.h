#pragma once
#include "Procesor.h"

class ComputeVowals : public Procesor {
private:
	std::string name;
public:
	ComputeVowals(std::string);
	virtual std::string GetName() override final;
	virtual int Compute(std::string) override final;
};
