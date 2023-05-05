#include "Value.h"

Value::Value(int32_t x) {
	this->x = x;
}

Value::~Value() {

}

void Value::print() {
	std::cout << this->x;
}

int64_t Value::compute() {
	return this->x;
}

uint64_t Value::get_children_count() {
	return 1;
}

Expression* Value::get_child(uint64_t index) {
	return this;
}
