#pragma once
#include <cstdint>
#include <iostream>

class Student {
	const char* name;
	const char** grade_names;
	float* grades;
	uint64_t grade_number;
public:
	static bool EqualName(const char*, const char*);
	Student();
	Student(const char*);
	~Student();
	const char* GetName();
	void PrintNote();
	float& operator[] (const uint64_t& index) {
		if (index >= this->grade_number) {
			exit(1);
		}
		return this->grades[index];
	}
	float& operator[] (const char*);
	operator float();
};