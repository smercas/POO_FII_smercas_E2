#include "Number.h"

void Number::chgSign(char& currentSign) {
	if (currentSign == '+') {
		currentSign = '-';
	}
	else if (currentSign == '-') {
		currentSign = '+';
	}
}
char Number::oppSign(char currentSign) {
	if (currentSign == '+') {
		return '-';
	}
	else if (currentSign == '-') {
		return '+';
	}
	else {
		printf("WARNING: Invalid sign(%c). How the hell did this happen?\n", currentSign);
		return '+';
	}
}
void Number::ExtendCharArrayLeft(char*& r, char toAppend) {
	uint64_t rl = strlen(r);
	char* aux = (char*)malloc(rl + 2);
	if (aux == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(4);
	}
	aux[rl + 1] = '\0';
	aux[0] = toAppend;
	for (uint64_t i = 0; i < rl; ++i) {
		aux[i + 1] = r[i];
	}
	free(r);
	r = aux;
	aux = nullptr;
}
void Number::CharAdd(char& r, char a, char b, bool& co, uint8_t base) {
	r = u[a] + u[b] + co;
	if (r >= base) {
		r = r - base;
		co = true;
	}
	else {
		co = false;
	}
	r = c[r];
}
char* Number::CharArrayAdd(const char* a, const char* b, uint8_t base) {
	if (a == nullptr || b == nullptr) {
		ADD_SUB_NULLPTR_WARNING;
		return nullptr;
	}
	else {
		bool carryover = false;
		if (strlen(a) < strlen(b)) {
			const char* aux = a;
			a = b;
			b = aux;
		}
		uint64_t al = strlen(a);
		uint64_t bl = strlen(b);
		char* result = (char*)malloc(al + 1);
		if (result == nullptr) {
			HEAP_ALLOCATION_FAILURE_ERROR;
			exit(3);
		}
		result[al] = '\0';
		uint64_t rl = strlen(result);
		for (uint64_t i = 1; i <= bl; ++i) {
			CharAdd(result[rl - i], a[al - i], b[bl - i], carryover, base);
		}
		for (uint64_t i = bl + 1; i <= al; ++i) {
			CharAdd(result[rl - i], a[al - i], 0, carryover, base);
		}
		/*
		a's length = b's length:
			first for:
				a1, a2, ..., an-1, an
				b1, b2, ..., bn-1, bn
				->
				r1, r2, ..., rn-1, rn
			second for:
				--nothing--
		a's length > b's length:
			first for:
				a1, a2, ..., an-k-1, an-k, an-k+1, an-k+2, ..., an-1, an
										   b1    , b2    , ..., bk-1, bk
				->
										   rn-k+1, rn-k+2, ..., rn-1, rn
			second for:
				a1, a2, ..., an-k-1, an-k
				->
				r1, r2, ..., rn-k-1, rn-k
		*/
		if (carryover) {
			ExtendCharArrayLeft(result, c[carryover]);
		}
		return result;
	}
}

void Number::RemoveZeroesLeft(char*& r) {
	if (r[0] != '0') {
		return;
	}
	else {
		uint64_t i = 0;
		while (r[i] == '0') {
			++i;
		}
		char* aux = (char*)malloc(strlen(r) - i + 1);
		if (aux == nullptr) {
			HEAP_ALLOCATION_FAILURE_ERROR;
			exit(4);
		}
		aux[strlen(r) - i] = '\0';
		for (uint64_t j = 0; j < strlen(r) - i; ++j) {
			aux[j] = r[j + i];
		}
		free(r);
		r = aux;
		aux = nullptr;
	}
}
void Number::CharSub(char& r, char a, char b, bool& br, uint8_t base) {
	r = u[a] - u[b] - br;
	if (r < 0) {
		r = r + base;
		br = true;
	}
	else {
		br = false;
	}
	r = c[r];
}
std::tuple<char*, char> Number::CharArraySub(const char* a, const char* b, uint8_t base) {
	if (a == nullptr || b == nullptr) {
		ADD_SUB_NULLPTR_WARNING;
		return std::make_tuple(nullptr, '\0');
	}
	else {
		char sign = '+';
		bool borrow = false;
		uint64_t i = 0;
		if (strlen(a) == strlen(b)) {
			while (a[i] && a[i] == b[i]) {
				++i;
			}
			if (a[i] == '\0' && b[i] == '\0') {
				char* result = (char*)malloc(2);
				if (result == nullptr) {
					HEAP_ALLOCATION_FAILURE_ERROR;
					exit(3);
				}
				result[0] = '0';
				result[1] = '\0';
				return std::make_tuple(result, '+');
			}
			if (a[i] < b[i]) {
				const char* aux = a;
				a = b;
				b = aux;
				sign = '-';
			}
		}
		else {
			if (strlen(a) < strlen(b)) {
				const char* aux = a;
				a = b;
				b = aux;
				sign = '-';
			}
		}
		char* result = (char*)malloc(strlen(a) - i + 1);
		if (result == nullptr) {
			HEAP_ALLOCATION_FAILURE_ERROR;
			exit(3);
		}
		uint64_t al = strlen(a);
		uint64_t bl = strlen(b);
		result[al - i] = '\0';
		uint64_t rl = strlen(result);
		for (uint64_t j = 1; j <= bl - i; ++j) {
			CharSub(result[rl - j], a[al - j], b[bl - j], borrow, base);
		}
		for (uint64_t j = bl - i + 1; j <= al - i; ++j) {
			CharSub(result[rl - j], a[al - j], 0, borrow, base);
		}
		/*
		* a, as a number, will always be greater than or equal to b
		a's length = b's length:
			i is the first position where a and b differ:
			   _				  _		  _					_
			i: 1 2 3 4		1 2 3 4		1 2 3 4		1 2 3 4 5
			a: 4 3 4 5		1 0 0 4		1 5 4 3		2 0 4 8
			b: 1 6 9 1		1 0 0 3		1 3 2 5		2 0 4 8
			if a and b are equal, then we can safely return "0"
			otherwise, we'll rely on i to give us the difference length
			first for:
				a1, a2, ..., an-i-1, an-i, an-i+1, an-i+2, ..., an-1, an
				b1, b2, ..., bn-i-1, bn-i, bn-i+1, bn-i+2, ..., bn-1, bn
				->
										   r1    , r2    , ..., ri-1, ri
			borrow = rx+1 / base
			rx = ax - bx - borrow
			second for:
				--nothing--

			at the end borrow is going to be 0, since a > b => an-i+1 > bn-i+1 => an-i+1 - bn-i+1 > 0 => an-i+1 - bn-i+1 - borrow >= 0
			the final number might have some excess zeroes at the beginning, which should be eliminated
			ex:
				1 0 0 0 1 0 0 0 -
				1 0 0 0 0 9 9 9
				---------------
						0 0 0 1 -> 1
		a's length > b's length:
		i is going to be a bit fat 0
			first for:
				a1, a2, ..., an-k-1, an-k, an-k+1, an-k+2, ..., an-1, an
										   b1    , b2    , ..., bk-1, bk
				->
										   rn-k+1, rn-k+2, ..., rn-1, rn
			second for:
				a1, a2, ..., an-k-1, an-k
				->
				r1, r2, ..., rn-k-1, rn-k
			borrow = rx+1 / base
			rx = ax - bx - borrow

			at the end borrow is going to be 0, since a>b ...
			the final number might have some excess zeroes at the beginning, which should be eliminated
			ex:
			1 0 0 8 -
			  9 9 9
			-------
			0 0 0 9 -> 9
		*/
		RemoveZeroesLeft(result);
		return std::make_tuple(result, sign);
	}
}
char* Number::CharArrayMul(const char* a, const char* b, uint8_t base) {
	char* result = (char*)malloc(strlen(a) + strlen(b) + 1);
	if (result == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(3);
	}
	uint64_t rl = strlen(a) + strlen(b);
	result[rl] = '\0';
	uint64_t i, j, n, k;
	for (i = 0; i < rl; ++i) {
		result[i] = c[0];
	}
	for (i = strlen(a) - 1; i < strlen(a); --i) {
		for (j = strlen(b) - 1; j < strlen(b); --j) {
			n = u[result[i + j + 1]] + (uint64_t)u[a[i]] * u[b[j]];
			k = 0;
			while (n >= base) {
				result[i + j + 1 - k] = c[n % base];
				n = n / base;
				++k;
				n = n + u[result[i + j + 1 - k]];
			}
			result[i + j + 1 - k] = c[n % base];
		}
	}
	RemoveZeroesLeft(result);
	return result;
}
void Number::CharArraySub_DivHelper(char*& a, const char* b, uint8_t base) {
	bool borrow = false;
	uint64_t al = strlen(a);
	uint64_t bl = strlen(b);
	for (uint64_t j = 1; j <= bl; ++j) {
		CharSub(a[al - j], a[al - j], b[bl - j], borrow, base);
	}
	for (uint64_t j = bl + 1; j <= al; ++j) {
		CharSub(a[al - j], a[al - j], 0, borrow, base);
	}
	uint64_t j = 0;
	while (a[j] == '0') {
		++j;
	}
	if (j) {
		uint64_t k;
		for (k = 0; k < al - j; ++k) {
			a[k] = a[k + j];
		}
		for (k = al - j; k < al; ++k) {
			a[k] = '\0';
		}
	}
}
std::tuple<Number, Number> Number::CharArrayDiv(const Number& A, const Number& B, uint8_t base) {
	if (A < B) {
		return std::make_tuple(Number("0", base), A);
	}
	uint64_t h, i, j;
	char* newNumber = (char*)malloc(strlen(B.number) + 2);
	if (newNumber == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(3);
	}
	for (i = 1; i <= strlen(B.number) + 1; ++i) {
		newNumber[i] = '\0';
	}
	newNumber[0] = '0';
	Number chunk(newNumber, base, '+');
	/*
	chunk will represent that number on every step of long division
	it's obvious that the space needed is at most strlen(divisor) + 1,
	since the highest that number can go is lower than divisor * 10
		examples:
	let divisor be							100 |  99
	the highest this number can go is		999 | 989

	in this implementation, chunk will be filled with '\0' and have
	digits added when we need them:
	index:	0  |  1  |  2  |  3  |  4  |  5  |  6
	chunk:	0  | \0  | \0  | \0  | \0  | \0  | \0

	after some subtractions, chunk can be left in this state:
	index:	0  |  1  |  2  |  3  |  4  |  5  |  6
	chunk:	0  |  0  |  0  |  7  | \0  | \0  | \0
	obviously 0007 is not a valid number, so the zeroes will be removed:
	index:	0  |  1  |  2  |  3  |  4  |  5  |  6
	chunk:	7  | \0  | \0  | \0  | \0  | \0  | \0
	removing the zeroes is done by the CharArraySub_DivHelper
	this method also does the repeated subtraction beforehand

	adding digits is fairly simple, just put it in strlen(chunk.number)
	the last character assigned on the heap is guaranteed to remain '\0'
	as i've explained above
	*/
	i = 0;
	while (chunk < B && i < strlen(A.number)) {
		chunk.number[i] = A.number[i];
		++i;
	}
	//chunk get values added in until it's greater than the divisor
	//the values are added how you'd add values when doing manual long division
	//lmao
	newNumber = (char*)malloc(strlen(A.number) - i + 2);
	if (newNumber == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(3);
	}
	newNumber[strlen(A.number) - i + 1] = '\0';
	for (j = 0; j < strlen(newNumber); ++j) {
		newNumber[j] = '0';
	}
	//newNumber is just where the result'll be stored
	//basically a bunch of zeroes
	//having newNumber initialised with zeroes makes it easier to increment
	//it's hard to explain why the size is strlen(divident) - i + 1 but i'll try anyway
	//i is the size of the number from the first stef of the usual long division algorithm
	//	62345 | 23			9048 | 8
	//	6	  |----			9	 |---
	//	0	  | 4			^	 |
	//	-	  |
	//	62	  |
	//	^^	  |
	//these are the numbers we're talking about
	//from then on, for every digit we add to the chunk, the size of the result will increase by one
	//the relation between the size of the divident, divisor and the result is:
	//strlen(divident) = strlen(divisor) + strlen(result) - 1
	h = 0;
	while (chunk >= B) {
		Number::CharArraySub_DivHelper(chunk.number, B.number, base);
		newNumber[h] = c[u[newNumber[h]] + 1];
	}
	++h;
	while (i < strlen(A.number)) {
		chunk.number[strlen(chunk.number)] = A.number[i];
		while (chunk >= B) {
			Number::CharArraySub_DivHelper(chunk.number, B.number, base);
			newNumber[h] = c[u[newNumber[h]] + 1];
		}
		++h;
		++i;
	}
	return std::make_tuple(Number(newNumber, base, '+'), chunk);
}
std::tuple<Number, Number> Number::QRDiv(const Number& A, const Number& B, uint8_t base) {
	if (strcmp(B.number, "0") == 0) {
		printf("ERROR: Division by zero attempted (%s / %s).\n", A.number, B.number);
		exit(5);
	}
	uint8_t newBase = std::max(A.base, B.base);
	if (strcmp(A.number, "0") == 0) {
		return std::make_tuple(Number("0", newBase), Number("0", newBase));
	}
	else {
		Number quotient;
		Number remainder;
		std::tie(quotient, remainder) = Number::CharArrayDiv(A.abs(), B.abs(), newBase);
		if (A.sign == '-' && B.sign == '-') {
			quotient = quotient + 1;
			remainder = B - remainder;
		}
		else if (A.sign != '-' && B.sign == '-') {
			quotient = -quotient;
		}
		else if (A.sign == '-' && B.sign != '-') {
			quotient = -(quotient + 1);
			remainder = B - remainder;
		}
		else {

		}
		//let a and b be positive integers
		//q and r(positive integers) exist and are unique for any positive integers a and b such that:
		// 
		//a = b * q + r ----------------------------------> solution(where a > 0 and b > 0): (q, r)
		// =>
		//a = (-b) * (-q) + r =>
		//		 => a = (-b) * (-q) + r ------------------> solution(where a > 0 and b < 0): (-q, r)
		//(-a) = -(b * q) - r =>
		//		 => (-a) = b * (-q) - r =>
		//		 => (-a) = b * (-q) - b + b - r =>
		//		 => (-a) = b * (-(q + 1)) + (b - r) ------> solution(where a < 0 and b > 0): (-(q + 1), b - r)
		//(-a) = -(b * q) - r =>
		//		 => (-a) = (-b) * q - r =>
		//		 => (-a) = (-b) * q - b + b - r =>
		//		 => (-a) = (-b) * (q + 1) + (b - r) ------>	solution(where a < 0 and b < 0): (q + 1, b - r)
		return std::make_tuple(quotient, remainder);
	}
}
void Number::SwitchBaseTo10() {
	Number X = 1; //base 10
	uint8_t digit = 0; //base 10
	Number result = 0; //base 10
	uint64_t i = strlen(this->number) - 1;
	while (i < strlen(this->number)) {
		digit = u[this->number[i]];
		result = result + digit * X;
		X = X * this->base;
		--i;
	}
	*this = result;
}

uint8_t Number::Conv_Char_To_Uint8_T(const char* value) {
	if (strcmp(value, "0") == 0) {
		return 0;
	}
	else {
		uint8_t result = 0;
		uint64_t i = 0;
		while (value[i]) {
			result = result * 10 + u[value[i]];
			++i;
		}
		return result;
	}
}
void Number::ExtendCharArrayRight(char*& r, char toAppend) {
	uint64_t rl = strlen(r);
	char* aux = (char*)malloc(rl + 2);
	if (aux == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(4);
	}
	aux[rl + 1] = '\0';
	aux[rl] = toAppend;
	for (uint64_t i = 0; i < rl; ++i) {
		aux[i] = r[i];
	}
	free(r);
	r = aux;
	aux = nullptr;
}
void Number::SwitchBaseFrom10(uint8_t newBase) {
	Number Q(*this);
	Number R("0", Q.base);
	char* result = (char*)malloc(1);
	if (result == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(3);
	}
	result[0] = '\0';
	uint64_t i = 0;
	while (strcmp(Q.number, "0")) {
		std::tie(Q, R) = QRDiv(Q, Number(newBase), Q.base);
		Number::ExtendCharArrayLeft(result, c[Conv_Char_To_Uint8_T(R.number)]);
	}
	free(this->number);
	this->number = result;
}

Number& Number::operator= (Number&& toMove) noexcept {
	if (SHOW_C_D_M_MESSAGES) {
		printf("Class instance Moved by assignment: (s)\t%p | %c%s | %hhu.\n\t\t\t\t    (d)\t%p | %c%s | %hhu.\n", &toMove, toMove.sign, toMove.number, toMove.base, this, this->sign, this->number, this->base);
	}
	//compare addresses
	if (this != &toMove) {
		free(this->number);
		this->number = toMove.number;
		this->base = toMove.base;
		this->sign = toMove.sign;
		toMove.number = nullptr;
		toMove.base = 0;
		toMove.sign = 'X';
	}
	if (SHOW_C_D_M_MESSAGES) {
		printf("\n\t\t\t\t    (s)\t%p | %c%s | %hhu.\n", &toMove, toMove.sign, toMove.number, toMove.base);
		printf("\t\t\t\t    (d)\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
	return *this;
}
//this allows chaining (a = b = c = 0)
Number& Number::operator= (Number& toCopy) {
	if (SHOW_C_D_M_MESSAGES) {
		printf("Class instance Copied by assignment: (s)\t%p | %c%s | %hhu.\n\t\t\t\t    (d)\t%p | %c%s | %hhu.\n", &toCopy, toCopy.sign, toCopy.number, toCopy.base, this, this->sign, this->number, this->base);
	}
	//compare addresses
	if (this != &toCopy) {
		free(this->number);
		this->InitNumber(toCopy.number);
		this->base = toCopy.base;
		this->sign = toCopy.sign;
	}
	if (SHOW_C_D_M_MESSAGES) {
		printf("\n\t\t\t\t    (s)\t%p | %c%s | %hhu.\n", &toCopy, toCopy.sign, toCopy.number, toCopy.base);
		printf("\t\t\t\t    (d)\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
	return *this;
}
Number& Number::operator= (int64_t toCopy) {
	free(this->number);
	this->number = Conv_Int64_T_To_Char(toCopy, this->base);
	return *this;
}
Number& Number::operator= (const char* toCopy) {
	free(this->number);
	Number temp(toCopy, this->base);
	this->InitNumber(temp.number);
	return *this;
}




//lonely guy, this destructor is
Number::~Number() {
	if (SHOW_C_D_M_MESSAGES) {
		printf("Class instance Destructed:\t\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
	free(this->number);
	this->number = nullptr;
	this->base = 0;
	this->sign = 'X';
}
//same tbh

//here to keep lil bro some company
void Number::SwitchBase(uint8_t newBase) {
	if (this->base == newBase) {
		return;
	}
	else {
		if (newBase < BASE_MIN || newBase > BASE_MAX) {
			printf("WARNING: %hhu is not a supported base, no conversion operations will occur.\n", newBase);
			return;
		}
		if (strcmp(this->number, "0")) {
			uint8_t i = 1;
			uint8_t pow = this->base;
			while (pow < newBase) {
				pow = pow * this->base;
				++i;
			}
			if (pow == newBase) {

			}
			else {
				i = 1;
				pow = newBase;
				while (pow < this->base) {
					pow = pow * newBase;
					++i;
				}
				if (pow == this->base) {

				}
				else {
					if (this->base != 10) {
						this->SwitchBaseTo10();
					}
					if (newBase != 10) {
						this->SwitchBaseFrom10(newBase);
					}
				}
			}
		}
	}
	this->base = newBase;
}
void Number::Print() {
	if (this->sign == '-') {
		printf("%c%s base %hhu\n", this->sign, this->number, this->base);
	}
	else {
		printf("%s base %hhu\n", this->number, this->base);
	}
}
uint64_t Number::GetDigitsCount() {
	return strlen(this->number);
}
uint8_t Number::GetBase() {
	return this->base;
}