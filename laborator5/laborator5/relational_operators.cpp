#include "Number.h"

bool Number::operator== (const Number& toCmp) const {
	return strcmp(this->number, toCmp.number) == 0 && this->sign == toCmp.sign;
}
bool Number::operator== (const int64_t& toCmp) const {
	return *this == Number(toCmp);
}
bool operator== (const int64_t& b, const Number& A) {
	return A == b;
}
bool Number::operator< (const Number& toCmp) const {
	if (this->sign == toCmp.sign) {
		if (this->sign == '+') {
			if (strlen(this->number) == strlen(toCmp.number)) {
				return strcmp(this->number, toCmp.number) < 0;
			}
			else {
				return strlen(this->number) < strlen(toCmp.number);
			}
		}
		else {
			return -(*this) > -toCmp;
		}
	}
	else {
		return this->sign == '-';
	}
}
bool Number::operator< (const int64_t& toCmp) const {
	return *this < Number(toCmp);
}
bool operator< (const int64_t& b, const Number& A) {
	return A > b;
}
bool Number::operator> (const Number& toCmp) const {
	return !(*this < toCmp || *this == toCmp);
}
bool Number::operator> (const int64_t& toCmp) const {
	return *this > Number(toCmp);
}
bool operator> (const int64_t& a, const Number& B) {
	return Number(a) > B;
}
bool Number::operator!= (const Number& toCmp) const {
	return !(*this == toCmp);
}
bool Number::operator!= (const int64_t& toCmp) const {
	return *this != Number(toCmp);
}
bool operator!= (const int64_t& a, const Number& B) {
	return Number(a) != B;
}
bool Number::operator>= (const Number& toCmp) const {
	return !(*this < toCmp);
}
bool Number::operator>= (const int64_t& toCmp) const {
	return *this >= Number(toCmp);
}
bool operator>= (const int64_t& a, const Number& B) {
	return Number(a) >= B;
}
bool Number::operator<= (const Number& toCmp) const {
	return *this < toCmp || *this == toCmp;
}
bool Number::operator<= (const int64_t& toCmp) const {
	return *this <= Number(toCmp);
}
bool operator<= (const int64_t& a, const Number& B) {
	return Number(a) <= B;
}
