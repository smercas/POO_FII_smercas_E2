#include "Calculator.h"

bool Calculator::CharEqual(const char* a, const char* b) {
	uint64_t i = 0;
	while (a[i] != '\0' && b[i] != '\0') {
		if (a[i] != b[i]) {
			return false;
		}
		++i;
	}
	if (a[i] != '\0' || b[i] != '\0') {
		return false;
	}
	return true;
}

Calculator::Calculator() {
	this->operations = new Operation* [0];
	this->operation_counter = 0;
}

Calculator::~Calculator() {
	if (this->operation_counter == 0) {
		printf("Nothing to delete.\n");
		return;
	}
	for (uint64_t i = 0; i < this->operation_counter; ++i) {
		delete this->operations[i];
	}
	delete[] this->operations;
	this->operation_counter = 0;
}

void Calculator::Compute(const int64_t& a, const int64_t& b) {
	for (uint64_t i = 0; i < operation_counter; ++i) {
		printf("%s(%lld,%lld) = %lld\n", this->operations[i]->GetName(), a, b, this->operations[i]->GetResult(a, b));
	}
}

void Calculator::operator+=(Operation* X) {
	uint64_t i = 0;
	while (i < this->operation_counter && Calculator::CharEqual(this->operations[i]->GetName(), X->GetName()) == false) {
		++i;
	}
	if (i == this->operation_counter) {
		Operation** aux = new Operation * [this->operation_counter + 1];
		for (uint64_t j = 0; j < this->operation_counter; ++j) {
			aux[j] = this->operations[j];
		}
		aux[this->operation_counter] = X;
		++this->operation_counter;
		delete[] this->operations;
		this->operations = aux;
		aux = nullptr;
	}
}

void Calculator::operator-=(const char* operation_name) {
	uint64_t i = 0;
	while (i < this->operation_counter && Calculator::CharEqual(this->operations[i]->GetName(), operation_name) == false) {
		++i;
	}
	if (i != this->operation_counter) {
		Operation** aux = new Operation * [this->operation_counter - 1];
		for (uint64_t j = 0; j < i; ++j) {
			aux[j] = this->operations[j];
		}
		for (uint64_t j = i + 1; j < this->operation_counter; ++j) {
			aux[j - 1] = this->operations[j];
		}
		--this->operation_counter;
		delete[] this->operations;
		this->operations = aux;
		aux = nullptr;
	}
}

Calculator::operator int() {
	return this->operation_counter;
}

bool Calculator::operator[](const char* operation_name) {
	uint64_t i = 0;
	while (i < this->operation_counter && Calculator::CharEqual(this->operations[i]->GetName(), operation_name) == false) {
		++i;
	}
	if (i == this->operation_counter) {
		return false;
	}
	return true;
}
