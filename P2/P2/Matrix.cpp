#include "Matrix.h"
#include <iomanip>

bool Matrix::IsEqualChar(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr) {
		return false;
	}
	uint64_t i = 0;
	while (a[i] != '\0' && b[i] != '\0') {
		if (a[i] != b[i]) {
			return false;
		}
		++i;
	}
	if (a[i] != b[i]) {
		return false;
	}
	return true;
}

Matrix::Matrix(const uint64_t& width, const uint64_t& height) {
	this->matrix = new int32_t * [width];
	for (uint64_t i = 0; i < width; ++i) {
		this->matrix[i] = new int32_t[height];
	}
	this->width = width;
	this->height = height;
}
Matrix::~Matrix() {
	for (uint64_t i = 0; i < this->width; ++i) {
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
	this->matrix = nullptr;
	this->width = 0;
	this->height = 0;
}
void Matrix::fill(const int32_t& value) {
	for (uint64_t i = 0; i < this->width; ++i) {
		for (uint64_t j = 0; j < this->height; ++j) {
			this->matrix[i][j] = value;
		}
	}
}

int32_t& Matrix::operator()(const uint64_t& x, const uint64_t& y)
{
	if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
		return this->matrix[0][0];
	}
	return this->matrix[x][y];
}

void Matrix::print() {
	if (this->height == 0 || this->width == 0) {
		return;
	}
	for (uint64_t i = 0; i < this->height; ++i) {
		for (uint64_t j = 0; j < this->width; ++j) {
			std::cout << std::setw(2) << this->matrix[j][i] << ' ';
		}
		std::cout << '\n';
	}
}

bool Matrix::is_square_matrix()
{
	return this->width == this->height;
}

bool Matrix::is_identity_matrix()
{
	if (this->width != this->height) {
		return false;
	}
	if (this->width < 2) {
		return false;
	}
	for (uint64_t i = 0; i < this->width; ++i) {
		if (this->matrix[i][i] != 1) {
			return false;
		}
	}
	for (uint64_t i = 0; i < this->width; ++i) {
		for (uint64_t j = 0; j < i; ++j) {
			if (this->matrix[i][j] != 0 || this->matrix[j][i] != 0) {
				return false;
			}
		}
	}
	/*
	for (uint64_t i = 0; i < this->width; ++i) {
		for (uint64_t j = 0; j < this->height; ++j) {
			if ((this->matrix[i][j] != 1 && i == j) ||
				(this->matrix[i][j] != 0 && i != j)) {
				return false;
			}
		}
	}
	/**/
	return true;
}

bool Matrix::operator==(const Matrix& other)
{
	if (this->width != other.width || this->height != other.height) {
		return false;
	}
	for (uint64_t i = 0; i < this->width; ++i) {
		for (uint64_t j = 0; j < this->height; ++j) {
			if (this->matrix[i][j] != other.matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

uint64_t Matrix::operator[](const char* item)
{
	if (item == nullptr) {
		return 0;
	}
	if (Matrix::IsEqualChar(item, "width")) {
		return this->width;
	}
	if (Matrix::IsEqualChar(item, "height")) {
		return this->height;
	}
	if (Matrix::IsEqualChar(item, "size")) {
		return this->width * this->height * sizeof(int32_t);
	}
	return 0;
}
