#include "Number.h"

Number Number::operator+ (const Number& toAdd) const {
	uint8_t newBase = std::max(this->base, toAdd.base);
	if (strcmp(this->number, "0") == 0 && strcmp(toAdd.number, "0") == 0) {
		return Number("0", newBase);
	}
	else if (strcmp(this->number, "0") == 0) {
		return Number(toAdd);
	}
	else if (strcmp(toAdd.number, "0") == 0) {
		return Number(*this);
	}
	else {
		Number A(*this);
		Number B(toAdd);
		A.SwitchBase(newBase);
		B.SwitchBase(newBase);
		if (A.sign == '-' && B.sign == '-') {
			//add: (-a) + (-b) = (-a) - b = -(b - (-a) = -(b + a) = -(a + b)
			return Number(Number::CharArrayAdd(A.number, B.number, newBase), newBase, '-');
		}
		else if (A.sign != '-' && B.sign == '-') {
			//sub: a + (-b) = a - b
			char* newNumber; char newSign;
			std::tie(newNumber, newSign) = Number::CharArraySub(A.number, B.number, newBase);
			return Number(newNumber, newBase, newSign);
		}
		else if (A.sign == '-' && B.sign != '-') {
			//sub: (-a) + b = b + (-a) = b - a = -(a - b)
			char* newNumber; char newSign;
			std::tie(newNumber, newSign) = Number::CharArraySub(B.number, A.number, newBase);
			return Number(newNumber, newBase, newSign);
		}
		else {
			//add: a + b = a + b
			return Number(Number::CharArrayAdd(A.number, B.number, newBase), newBase, '+');
		}
	}
}
Number Number::operator+ (const int64_t& toAdd)  const {
	return *this + Number(toAdd);
}
Number operator+ (const int64_t& a, const Number& B) {
	return Number(a) + B;
}

Number& Number::operator+= (const Number& toAdd) {
	*this = *this + toAdd;
	return *this;
}
Number& Number::operator+= (const int64_t& toAdd) {
	*this = *this + Number(toAdd);
	return *this;
}

Number Number::operator- (const Number& toSub) const {
	uint8_t newBase = std::max(this->base, toSub.base);
	if (strcmp(this->number, "0") == 0 && strcmp(toSub.number, "0") == 0) {
		return Number("0", newBase);
	}
	else if (strcmp(this->number, "0") == 0) {
		return Number((const char*)toSub.number, toSub.base, oppSign(toSub.sign));
	}
	else if (strcmp(toSub.number, "0") == 0) {
		return Number(*this);
	}
	else {
		Number A(*this);
		Number B(toSub);
		A.SwitchBase(newBase);
		B.SwitchBase(newBase);
		if (A.sign == '-' && B.sign == '-') {
			//sub: (-a) - (-b) = (-a) + b = b - a = -(a - b)
			char* newNumber; char newSign;
			std::tie(newNumber, newSign) = Number::CharArraySub(B.number, A.number, newBase);
			return Number(newNumber, newBase, newSign);
		}
		else if (A.sign != '-' && B.sign == '-') {
			//add: a - (-b) = a + b
			return Number(Number::CharArrayAdd(A.number, B.number, newBase), newBase, '+');
		}
		else if (A.sign == '-' && B.sign != '-') {
			//add: (-a) - b = -(b - (-a)) = -(b + a) = -(a + b)
			return Number(Number::CharArrayAdd(A.number, B.number, newBase), newBase, '-');
		}
		else {
			//sub: a - b = a - b
			char* newNumber; char newSign;
			std::tie(newNumber, newSign) = Number::CharArraySub(A.number, B.number, newBase);
			return Number(newNumber, newBase, newSign);
		}
	}
}
Number Number::operator- (const int64_t& toSub) const {
	return *this - Number(toSub);
}
Number operator- (const int64_t& a, const Number& B) {
	return Number(a) - B;
}

Number& Number::operator-= (const Number& toSub) {
	*this = *this - toSub;
	return *this;
}
Number& Number::operator-= (const int64_t& toSub) {
	*this = *this - Number(toSub);
	return *this;
}

Number Number::operator* (const Number& toMul) const {
	uint8_t newBase = std::max(this->base, toMul.base);
	if (strcmp(this->number, "0") == 0 || strcmp(toMul.number, "0") == 0) {
		return Number("0", newBase);
	}
	else {
		Number A(*this);
		Number B(toMul);
		A.SwitchBase(newBase);
		B.SwitchBase(newBase);
		if (A.sign == '-' && B.sign == '-') {
			return Number(Number::CharArrayMul(A.number, B.number, newBase), newBase, '+');
		}
		else if (A.sign != '-' && B.sign == '-') {
			return Number(Number::CharArrayMul(A.number, B.number, newBase), newBase, '-');
		}
		else if (A.sign == '-' && B.sign != '-') {
			return Number(Number::CharArrayMul(A.number, B.number, newBase), newBase, '-');
		}
		else {
			return Number(Number::CharArrayMul(A.number, B.number, newBase), newBase, '+');
		}
	}
}
Number Number::operator* (const int64_t& toMul) const {
	return *this * Number(toMul);
}
Number operator* (const int64_t& a, const Number& B) {
	return Number(a) * B;
}

Number& Number::operator*= (const Number& toMul) {
	*this = *this * toMul;
	return *this;
}
Number& Number::operator*= (const int64_t& toMul) {
	*this = *this * Number(toMul);
	return *this;
}

Number Number::operator/ (const Number& toDiv) const {
	uint8_t newBase = std::max(this->base, toDiv.base);
	if (strcmp(toDiv.number, "0") == 0) {
		printf("ERROR: Division by zero attempted (%s / %s).\n", this->number, toDiv.number);
		exit(5);
	}
	if (strcmp(this->number, "0") == 0) {
		return Number("0", newBase);
	}
	else {
		Number A(*this);
		Number B(toDiv);
		A.SwitchBase(newBase);
		B.SwitchBase(newBase);
		Number quotient;
		Number remainder;
		std::tie(quotient, remainder) = Number::CharArrayDiv(A.abs(), B.abs(), newBase);
		if (A.sign == '-' && B.sign == '-') {
			quotient = quotient + 1;
		}
		else if (A.sign != '-' && B.sign == '-') {
			quotient = -quotient;
		}
		else if (A.sign == '-' && B.sign != '-') {
			quotient = -(quotient + 1);
		}
		else {

		}
		return quotient;
		//see QRDiv for explanations
	}
}
Number Number::operator/ (const int64_t& toDiv) const {
	return *this / Number(toDiv);
}
Number operator/ (const int64_t& a, const Number& B) {
	return Number(a) / B;
}

Number& Number::operator/= (const Number& toDiv) {
	*this = *this / toDiv;
	return *this;
}
Number& Number::operator/= (const int64_t& toDiv) {
	*this = *this / Number(toDiv);
	return *this;
}

Number Number::operator% (const Number& toDiv) const {
	if (strcmp(toDiv.number, "0") == 0) {
		printf("ERROR: Division by zero attempted (%s / %s).\n", this->number, toDiv.number);
		exit(5);
	}
	uint8_t newBase = std::max(this->base, toDiv.base);
	if (strcmp(this->number, "0") == 0) {
		return Number("0", newBase);
	}
	else {
		Number A(*this);
		Number B(toDiv);
		A.SwitchBase(newBase);
		B.SwitchBase(newBase);
		Number quotient;
		Number remainder;
		std::tie(quotient, remainder) = Number::CharArrayDiv(A.abs(), B.abs(), newBase);
		if (A.sign == '-' && B.sign == '-') {
			remainder = B - remainder;
		}
		else if (A.sign != '-' && B.sign == '-') {
		}
		else if (A.sign == '-' && B.sign != '-') {
			remainder = B - remainder;
		}
		else {

		}
		return remainder;
		//see QRDiv for explanations
	}
}
Number Number::operator% (const int64_t& toDiv) const {
	return *this % Number(toDiv);
}
Number operator% (const int64_t& a, const Number& B) {
	return Number(a) % B;
}

Number& Number::operator%= (const Number& toDiv) {
	*this = *this + toDiv;
	return *this;
}
Number& Number::operator%= (const int64_t& toDiv) {
	*this = *this + Number(toDiv);
	return *this;
}
