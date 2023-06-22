#pragma once
#include <string>
#include "Animal.h"

class Eagle : public Animal {
	virtual std::string GetName() override final { return "Eagle"; }
	virtual bool IsAFish() override final { return false; }
	virtual bool IsABird() override final { return true; }
	virtual bool IsAMammal() override final { return false; }
};
