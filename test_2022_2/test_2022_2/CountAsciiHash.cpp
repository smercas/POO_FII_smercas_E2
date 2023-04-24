#include "CountAsciiHash.h"

const char* CountAsciiHash::GetName() {
	return "count_ascii";
}

uint64_t CountAsciiHash::Calculate(const char* c) {
	uint64_t result = 0;
	for (uint64_t i = 0; c[i] != '\0'; ++i) {
		result = result + c[i];
	}
	return result;
}
