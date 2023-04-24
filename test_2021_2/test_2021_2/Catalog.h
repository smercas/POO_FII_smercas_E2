#pragma once
#include <cstdint>
#include "Student.h"

class Catalog {
	Student** students;
	uint64_t student_number;
public:
	Catalog();
	~Catalog();
	uint64_t GetCount();
	Student& operator[] (const uint64_t&);
	Student& operator[] (const char*);
	void operator += (const char* new_name);
};