#pragma once
#include <iostream>
#include <cstdint>

class Matrix {
	int32_t** matrix;
	uint64_t width;
	uint64_t height;
	static bool IsEqualChar(const char*, const char*);
public:
	Matrix(const uint64_t&, const uint64_t&);
	~Matrix();
	void fill(const int32_t&);
	int32_t& operator()(const uint64_t& x, const uint64_t& y);
	void print();
	bool is_square_matrix();
	bool is_identity_matrix();
	bool operator==(const Matrix&);
	uint64_t operator[](const char*);
};

