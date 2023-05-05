#include "Fractie.h"

uint64_t Fractie::gcd(uint64_t a, uint64_t b)
{
	uint64_t r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool Fractie::IsEqualName(const char* a, const char* b) {
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

Fractie::Fractie(const uint64_t& numerator, const uint64_t& denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
}

Fractie::Fractie(const char* fraction) {
	uint64_t i = 0;
	uint64_t number = 0;
	while (fraction[i] != '\0' && fraction[i] != '/') {
		number = number * 10 + fraction[i] - '0';
		++i;
	}
	this->numerator = number;
	if (fraction[i] == '\0') {
		this->denominator = 1;
	}
	else {
		++i;
		number = 0;
		while (fraction[i] != '\0') {
			number = number * 10 + fraction[i] - '0';
			++i;
		}
		this->denominator = number;
	}
}

Fractie::Fractie(const Fractie& other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
}

Fractie::Fractie(Fractie&& other) noexcept {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
}

Fractie::~Fractie() {
	//nothing to deallocate on the heap as far as I know
	this->numerator = 0;
	this->denominator = 0;
}

void Fractie::print() {
	printf("%llu/%llu", this->numerator, this->denominator);
}

Fractie Fractie::simplify() {
	uint64_t gcd = Fractie::gcd(this->numerator, this->denominator);
	return Fractie(this->numerator / gcd, this->denominator / gcd);
}

Fractie Fractie::operator+(const Fractie& other) {
	uint64_t gcd = Fractie::gcd(this->denominator, other.denominator);
	return Fractie(this->numerator * other.denominator / gcd + other.numerator * this->denominator / gcd, this->denominator * other.denominator / gcd);
}

Fractie Fractie::operator-(const Fractie& other) {
	uint64_t gcd = Fractie::gcd(this->denominator, other.denominator);
	return Fractie(this->numerator * other.denominator / gcd - other.numerator * this->denominator / gcd, this->denominator * other.denominator / gcd);
}

Fractie Fractie::operator*(const Fractie& other) {
	return Fractie(this->numerator * other.numerator, this->denominator * other.denominator);
}

bool Fractie::operator==(const Fractie& other) {
	Fractie a = this->simplify();
	Fractie b = other;
	Fractie c = b.simplify();
	return a.numerator == c.numerator && a.denominator == c.denominator;
}

uint64_t Fractie::operator[](const char* name) {
	if (name == nullptr) {
		return 0;
	}
	if (Fractie::IsEqualName(name, "numerator")) {
		return this->numerator;
	}
	if (Fractie::IsEqualName(name, "denominator")) {
		return this->denominator;
	}
	return 0;
}
