#pragma once
#include <iostream>
#include <cstdint>

class Fractie {
	uint64_t numerator;
	uint64_t denominator;
	static uint64_t gcd(uint64_t, uint64_t);
	static bool IsEqualName(const char*, const char*);
public:
	Fractie(const uint64_t&, const uint64_t&);
	Fractie(const char*);
	Fractie(const Fractie&);
	Fractie(Fractie&&) noexcept;
	~Fractie();
	void print();
	Fractie simplify();
	Fractie operator+(const Fractie&);
	Fractie operator-(const Fractie&);
	Fractie operator*(const Fractie&);
	bool operator==(const Fractie&);
	uint64_t operator[](const char*);
};
