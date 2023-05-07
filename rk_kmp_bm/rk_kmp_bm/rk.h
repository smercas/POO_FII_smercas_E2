#pragma once
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <tuple>

class rk {
public:
	static std::tuple<uint64_t, uint64_t, uint64_t> calculate_hash(const char*, const char*);
	static uint64_t roll_hash(const char*, uint64_t, uint64_t, uint64_t&);
	static void find_all_occurences(FILE*, const char*, const char*);
	static void find_all_occurences_lean(FILE*, const char*, const char*);
};
