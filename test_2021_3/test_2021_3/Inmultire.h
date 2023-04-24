#pragma once
#include "Operation.h"

class Inmultire : public Operation {
	virtual const char* GetName() override final;
	virtual int64_t GetResult(const int64_t&, const int64_t&) override final;
};

