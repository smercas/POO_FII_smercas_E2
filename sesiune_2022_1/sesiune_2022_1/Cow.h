#pragma once
#include <string>
#include "Animal.h"

class Cow : public Animal {
	virtual std::string GetName() override final { return "Cow"; }
	virtual bool IsAFish() override final { return false; }
	virtual bool IsABird() override final { return false; }
	virtual bool IsAMammal() override final { return true; }
};
