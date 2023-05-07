#pragma once
#include <cstdint>
#include <cstdio>

class Marker {
public:
	static void print(FILE* file, int64_t first_bound, int64_t second_bound, uint64_t contained_within, char before_sep, char during_sep, char after_sep, char begin, char end);
};
