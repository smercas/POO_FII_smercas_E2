#pragma once
#include <string>
#include "Feline.h"

class Tiger : public Feline {
	virtual std::string GetName() override final { return "Tiger"; }
	virtual bool IsAFish() override final { return false; }
	virtual bool IsABird() override final { return false; }
	virtual bool IsAMammal() override final { return true; }
	virtual int GetSpeed() override final { return 100; }
};

