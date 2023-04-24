#include "CountVowelsHash.h"

const char* CountVowelsHash::GetName()
{
	return "count_vowels";
}

uint64_t CountVowelsHash::Calculate(const char* c) {
	uint64_t result = 0;
	for (uint64_t i = 0; c[i] != '\0'; ++i) {
		if (Hash::charFind("aeiouAEIOU", c[i])) {
			++result;
		}
	}
	return result;
}
