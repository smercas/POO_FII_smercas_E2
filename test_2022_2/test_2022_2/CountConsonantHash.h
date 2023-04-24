#pragma once
#include "Hash.h"

class CountConsonantHash : public Hash{
	virtual const char* GetName() override final;
	virtual uint64_t Calculate(const char*) override final;
};

