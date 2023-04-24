#pragma once
#include "Hash.h"

class CountAsciiHash : public Hash {
public:
	virtual const char* GetName() override final;
	virtual uint64_t Calculate(const char*) override final;
};

