#pragma once
#include <cstdint>

class Hash {
public:
	static bool charFind(const char*, const char&);
	virtual const char* GetName() = 0;
	virtual uint64_t Calculate(const char*) = 0;
};