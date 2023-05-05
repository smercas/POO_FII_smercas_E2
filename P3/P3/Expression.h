#pragma once
#include <cstdint>

class Expression {
public:
	virtual void print() = 0;
	virtual int64_t compute() = 0;
	virtual uint64_t get_children_count() = 0;
	virtual Expression* get_child(uint64_t) = 0;
};
