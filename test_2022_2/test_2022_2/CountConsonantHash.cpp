#include "CountConsonantHash.h"

const char* CountConsonantHash::GetName()
{
	return "count_consonant";
}

uint64_t CountConsonantHash::Calculate(const char* c) {
	uint64_t result = 0;
	for (uint64_t i = 0; c[i] != '\0'; ++i) {
		if (Hash::charFind("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", c[i])) {
			++result;
		}
	}
	return result;
}
