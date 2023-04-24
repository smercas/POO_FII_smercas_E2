#include "Catalog.h"
#include <iostream>

Catalog::Catalog() {
	this->students = new Student*[0];
	this->student_number = 0;
}
Catalog::~Catalog() {
	for (uint64_t i = 0; i < this->student_number; ++i) {
		delete this->students[i];
	}
	delete[] this->students;
	this->student_number = 0;
}
uint64_t Catalog::GetCount() {
	return this->student_number;
}
Student& Catalog::operator[] (const uint64_t& index) {
	if (index >= this->student_number) {
		exit(1);
	}
	return *this->students[index];
}
Student& Catalog::operator[] (const char* student_name) {
	uint64_t i = 0;
	while (i < this->student_number && !Student::EqualName(this->students[i]->GetName(), student_name)) {
		++i;
	}
	if (i == this->student_number) {
		Student** aux = new Student* [this->student_number + 1];
		for (uint64_t j = 0; j < this->student_number; ++j) {
			aux[j] = this->students[j];
		}
		aux[this->student_number] = new Student(student_name);
		delete[] this->students;
		this->students = aux;
		aux = nullptr;
		++this->student_number;
		return *this->students[this->student_number - 1];
	}
	return *this->students[i];
}

void Catalog::operator += (const char* new_name) {
	Student** aux = new Student * [this->student_number + 1];
	for (uint64_t i = 0; i < this->student_number; ++i) {
		aux[i] = this->students[i];
	}
	aux[this->student_number] = new Student(new_name);
	delete[] this->students;
	this->students = aux;
	aux = nullptr;
	++this->student_number;
}