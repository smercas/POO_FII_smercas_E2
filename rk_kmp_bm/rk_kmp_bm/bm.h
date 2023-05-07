#pragma once
#include <iostream>
#include <cstdint>
#include <cstdio>

constexpr uint64_t ALPHABET_LENGTH = 26;

class bm {
public:
	static int64_t* calculate_last_bad_character(FILE*, const char*);
	static int64_t* calculate_last_bad_character_lean(FILE*, const char*);
	static int64_t* calculate_second_to_last_good_suffix(FILE*, const char*);
	static int64_t* calculate_second_to_last_good_suffix_lean(FILE*, const char*);
	static void find_all_occurences(FILE*, const char*, const char*);
	static void find_all_occurences_lean(FILE*, const char*, const char*);
};
