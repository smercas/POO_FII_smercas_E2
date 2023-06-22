#pragma once
#include <string>
#include "Animal.h"

class Shark : public Animal {
	virtual std::string GetName() override final { return "Shark"; }
	virtual bool IsAFish() override final { return true; }
	virtual bool IsABird() override final { return false; }
	virtual bool IsAMammal() override final { return false; }
};
