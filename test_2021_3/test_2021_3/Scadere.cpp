#include "Scadere.h"

const char* Scadere::GetName() {
	return "Scadere";
}

int64_t Scadere::GetResult(const int64_t& a, const int64_t& b) {
	return a - b;
}
