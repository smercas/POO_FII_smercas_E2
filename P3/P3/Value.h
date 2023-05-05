#pragma once
#include <cstdint>
#include <iostream>
#include "Expression.h"

class Value : public Expression {
	int32_t x;
public:
	Value(int32_t);
	~Value();
	virtual void print() override final;
	virtual int64_t compute() override final;
	virtual uint64_t get_children_count() override final;
	virtual Expression* get_child(uint64_t) override final;
};
