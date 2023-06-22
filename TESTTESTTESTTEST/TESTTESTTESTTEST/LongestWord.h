#pragma once
#include "Procesor.h"
class LongestWord : public Procesor {
private:
	std::string name;
public:
	LongestWord(std::string);
	virtual std::string GetName() override final;
	virtual int Compute(std::string) override final;
};
