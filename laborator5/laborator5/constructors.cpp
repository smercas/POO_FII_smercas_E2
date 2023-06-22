#include "Number.h"

Number::Number() {
	this->number = nullptr;
	this->base = 0;
	this->sign = 'X';
	if (SHOW_C_D_M_MESSAGES) {
		printf("Empty class instance Constructed:\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
}
Number::Number(char* value, uint8_t base, char sign) {
	this->number = value;
	this->base = base;
	this->sign = sign;
	if (SHOW_C_D_M_MESSAGES) {
		printf("Class instance Constructed (c*, u):\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
}
void Number::InitNumber(const char* number) {
	this->number = (char*)malloc(strlen(number) + 1);
	if (this->number == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(1);
	}
	this->number[strlen(number)] = '\0';
	for (uint64_t i = 0; i < strlen(number); ++i) {
		this->number[i] = number[i];
	}
}
Number::Number(const char* value, uint8_t base, char sign) {
	if (base < BASE_MIN || base > BASE_MAX) {
		printf("WARNING: %hhu is not a supported base, it'll be converted to base %hhu.\n", base, BASE_MAX);
		base = BASE_MAX;
	}
	this->base = base;
	if (value[0] == '-') {
		this->sign = '-';
	}
	else {
		this->sign = '+';
	}
	if (value == nullptr) {
		printf("WARNING: The address of value (%p) is, as you can see, a nullptr, class instance number will be set to \"0\".\n", value);
		this->InitNumber("0");
	}
	else if (strcmp(value, "") == 0 || strcmp(value, "-") == 0) {
		CONSTRUCTOR_BAD_VALUE_WARNING;
		this->InitNumber("0");
	}
	else if (strcmp(value, "0") == 0) {
		this->InitNumber("0");
	}
	else if (value[0] == '0' || value[0] == '-' && value[1] == '0') {
		printf("WARNING: The recieved value (%s) starts with at least a zero. The class instance value will be set to \"0\".\n", value);
		this->InitNumber("0");
	}
	else {
		uint8_t max = 0;
		uint8_t maxContestant = 0;
		uint64_t i = 0;
		if (value[0] == '-') {
			++i;
		}
		while (i < strlen(value)) {
			if (strchr(c, value[i])) {
				maxContestant = u[value[i]] + 1;
			}
			else {
				printf("WARNING: Digit \"%c\" is not valid in any base. Recieved value (%s) was written in bad faith, so the class instance value will be set to \"0\".\n", *(value + i), value + i);
				i = strlen(value);
			}
			if (maxContestant > max) {
				max = maxContestant;
			}
			++i;
		}
		if (i == strlen(value)) {
			this->InitNumber(value + (value[0] == '-'));
			if (this->base < max) {
				printf("WARNING: Base (%hhu) is too low for the recieved number (%s), so it'll be raised to %hhu.\n", this->base, value, max);
				this->base = max;
			}
		}
		else {
			this->InitNumber("0");
		}
	}
	if (SHOW_C_D_M_MESSAGES) {
		printf("Class instance Constructed (cc*, u):\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
}
char* Number::Conv_Int64_T_To_Char(const int64_t& value, uint8_t base) {
	uint64_t size = 0;
	int64_t copy = value;
	if (copy == 0) {
		size = 1;
	}
	while (copy) {
		copy = copy / base;
		++size;
	}
	char* result = (char*)malloc(size + 1);
	if (result == nullptr) {
		HEAP_ALLOCATION_FAILURE_ERROR;
		exit(2);
	}
	result[size] = '\0';
	copy = value;
	for (uint64_t i = size - 1; i >= 0 && i < size; --i) {
		result[i] = c[copy % base];
		copy = copy / base;
	}
	return result;
}
Number::Number(const int64_t& value) {
	this->number = this->Conv_Int64_T_To_Char(value);
	this->base = 10;
	if (value == 0) {
		this->sign = '+';
	}
	else {
		if (value > 0) {
			this->sign = '+';
		}
		else {
			this->sign = '-';
		}
	}
	if (SHOW_C_D_M_MESSAGES) {
		printf("Class instance Constructed (int64_t):\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
}
Number::Number(const Number& toCopy) {
	this->InitNumber(toCopy.number);
	this->base = toCopy.base;
	this->sign = toCopy.sign;
	if (SHOW_C_D_M_MESSAGES) {
		printf("Class instance Copied:\t\t\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
}
Number::Number(Number&& toMove) noexcept {
	if (SHOW_C_D_M_MESSAGES) {
		this->number = nullptr;
		this->base = 0;
		this->sign = 'X';
		printf("Class instance Moved by constructor:(s)\t%p | %c%s | %hhu.\n\t\t\t\t    (d)\t%p | %c%s | %hhu.\n", &toMove, toMove.sign, toMove.number, toMove.base, this, this->sign, this->number, this->base);
	}
	this->number = toMove.number;
	this->base = toMove.base;
	this->sign = toMove.sign;

	toMove.number = nullptr;
	toMove.base = 0;
	toMove.sign = 'X';
	if (SHOW_C_D_M_MESSAGES) {
		printf("\n\t\t\t\t    (s)\t%p | %c%s | %hhu.\n", &toMove, toMove.sign, toMove.number, toMove.base);
		printf("\t\t\t\t    (d)\t%p | %c%s | %hhu.\n", this, this->sign, this->number, this->base);
	}
}
