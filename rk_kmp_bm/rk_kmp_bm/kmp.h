#pragma once
#include <iostream>
#include <cstdint>
#include <cstdio>

class kmp {
public:
	static int64_t* calculate_failure(FILE*, const char*);
	static int64_t* calculate_failure_lean(FILE*, const char*);
	static void find_all_occurences(FILE*, const char*, const char*);
	static void find_all_occurences_lean(FILE*, const char*, const char*);
};
