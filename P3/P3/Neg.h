#pragma once
#include <cstdint>
#include <iostream>
#include "Expression.h"

class Neg : public Expression {
	Expression* e;
public:
	Neg(Expression* e);
	~Neg();
	virtual void print() override final;
	virtual int64_t compute() override final;
	virtual uint64_t get_children_count() override final;
	virtual Expression* get_child(uint64_t) override final;
};
