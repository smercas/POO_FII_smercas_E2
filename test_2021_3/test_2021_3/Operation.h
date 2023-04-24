#pragma once
#include <cstdint>

class Operation {
public:
	virtual const char* GetName() = 0;
	virtual int64_t GetResult(const int64_t&, const int64_t&) = 0;
};

