#pragma once
#include <cstdint>
#include <iostream>
#include "Operation.h"

class Calculator {
	Operation** operations;
	uint64_t operation_counter;
	static bool CharEqual(const char*, const char*);
public:
	Calculator();
	~Calculator();
	void Compute (const int64_t&, const int64_t&);
	void operator += (Operation*);
	void operator -= (const char*);
	operator int();
	bool operator[] (const char*);
};