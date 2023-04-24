#include "EasyHash.h"

const char* EasyHash::GetName() {
	return "easy_ascii";
}

uint64_t EasyHash::Calculate(const char* c) {
	uint64_t result = 0;
	for (uint64_t i = 0; c[i] != '\0'; ++i) {
		if (Hash::charFind("aeiouAEIOU", c[i])) {
			result = result + c[i] * 10;
		}
		else if (Hash::charFind("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", c[i])) {
			result = result + c[i] * 11;
		}
		else {
			result = result + c[i] * 12;
		}
	}
	return result;
}