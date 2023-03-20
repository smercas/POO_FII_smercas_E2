#include "Number.h"

Number Number::abs () const {
	Number temp(*this);
	temp.sign = '+';
	return temp;
}
char& Number::operator[] (uint64_t index) const {
	if (index >= strlen(this->number)) {
		printf("WARNING: Recieved index (%llu) greater than the number length (%llu). Method will return the last digit of the number.\n", index, strlen(this->number));
		return this->number[strlen(this->number) - 1];
	}
	else {
		return this->number[index];
	}
}
Number Number::operator+ () const {
	return *this;
}
Number Number::operator- () const {
	Number temp(*this);
	if (strcmp(this->number, "0")) {
		if (temp.sign == '+') {
			temp.sign = '-';
		}
		else {
			temp.sign = '+';
		}
	}
	return temp;
}
Number Number::operator-- () {
	char* aux = (char*)malloc(strlen(this->number));
	if (aux == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(3);
	}
	aux[strlen(this->number) - 1] = '\0';
	for (uint64_t i = 0; i < strlen(aux); ++i) {
		aux[i] = this->number[i + 1];
	}
	free(this->number);
	this->number = aux;
	aux = nullptr;
	return *this;
}
Number Number::operator-- (int) {
	char* aux = (char*)malloc(strlen(this->number));
	if (aux == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(3);
	}
	aux[strlen(this->number) - 1] = '\0';
	for (uint64_t i = 0; i < strlen(aux); ++i) {
		aux[i] = this->number[i];
	}
	free(this->number);
	this->number = aux;
	aux = nullptr;
	return *this;
}