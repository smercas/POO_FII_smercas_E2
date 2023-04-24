#pragma once
#include "Hash.h"

class EasyHash : public Hash {
	virtual const char* GetName() override final;
	virtual uint64_t Calculate(const char*) override final;
};

