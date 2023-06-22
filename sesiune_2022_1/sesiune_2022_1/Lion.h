#pragma once
#include <string>
#include "Feline.h"

class Lion : public Feline {
	virtual std::string GetName() override final { return "Lion"; }
	virtual bool IsAFish() override final { return false; }
	virtual bool IsABird() override final { return false; }
	virtual bool IsAMammal() override final { return true; }
	virtual int GetSpeed() override final { return 80; }
};
