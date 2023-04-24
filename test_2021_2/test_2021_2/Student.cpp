#include "Student.h"
#include <cstdint>
#include <iostream>

bool Student::EqualName(const char* a, const char* b) {
	uint64_t i = 0;
	while (a[i] != 0 && b[i] != 0) {
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

Student::Student() : Student("") {

}
Student::Student(const char* name) {
	this->name = name;
	this->grade_names = new const char* [0];
	this->grades = new float[0];
	this->grade_number = 0;
}
Student::~Student() {
	this->name = "X";
	delete[] this->grade_names;
	delete[] this->grades;
	this->grade_number = 0;
}
const char* Student::GetName() {
	return this->name;
}
void Student::PrintNote() {
	uint64_t i = 0;
	while (i < this->grade_number) {
		printf("   %s => %f\n", this->grade_names[i], this->grades[i]);
		++i;
	}
}
/*
float* Student::operator[] (const uint64_t& index) {
	if (index >= this->grade_number) {
		return nullptr;
	}
	return &this->grades[index];
}
/**/
float& Student::operator[] (const char* grade_name) {
	uint64_t i = 0;
	while (i < this->grade_number && !EqualName(this->grade_names[i], grade_name)) {
		++i;
	}
	if (i == this->grade_number) {
		const char** aux1 = new const char* [this->grade_number + 1];
		float* aux2 = new float[this->grade_number + 1];
		for (uint64_t j = 0; j < this->grade_number; ++j) {
			aux1[j] = this->grade_names[j];
			aux2[j] = this->grades[j];
		}
		aux1[this->grade_number] = grade_name;
		aux2[this->grade_number] = 0;
		delete[] this->grade_names;
		delete[] this->grades;
		this->grade_names = aux1;
		this->grades = aux2;
		aux1 = nullptr;
		aux2 = nullptr;
		++this->grade_number;
		return this->grades[this->grade_number - 1];
	}
	return this->grades[i];
}
Student::operator float() {
	float result = 0;
	uint64_t i = 0;
	while (i < this->grade_number) {
		result = result + grades[i];
		++i;
	}
	result = result / this->grade_number;
	return result;
}