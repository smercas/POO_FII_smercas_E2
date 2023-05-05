#include "Sub.h"

Sub::Sub(Expression* e1, Expression* e2) {
	this->e = new Expression * [2];
	this->e[0] = e1;
	this->e[1] = e2;
}

Sub::~Sub() {
	delete e[0];
	delete e[1];
	delete[] e;
}

void Sub::print() {
	std::cout << "(";
	this->e[0]->print();
	std::cout << " - ";
	this->e[1]->print();
	std::cout << ")";
}

int64_t Sub::compute() {
	return e[0]->compute() - e[1]->compute();
}

uint64_t Sub::get_children_count() {
	return 2;
}

Expression* Sub::get_child(uint64_t index) {
	if (index >= this->get_children_count()) {
		return nullptr;
	}
	return e[index];
}
