#include "Hash.h"

bool Hash::charFind(const char* a, const char& c) {
	for (uint64_t i = 0; a[i] != '\0'; ++i) {
		if (a[i] == c) {
			return true;
		}
	}
	return false;
}
