#include "Neg.h"

Neg::Neg(Expression* e) {
	this->e = e;
}

Neg::~Neg() {

}

void Neg::print() {
	std::cout << " - ";
	this->e->print();
}

int64_t Neg::compute() {
	return -this->e->compute();
}

uint64_t Neg::get_children_count()
{
	return 1;
}

Expression* Neg::get_child(uint64_t index)
{
	if (index >= 1) {
		return nullptr;
	}
	return e;
}
