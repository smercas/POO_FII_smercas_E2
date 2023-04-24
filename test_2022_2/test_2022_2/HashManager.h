#pragma once
#include "Hash.h"
#include <iostream>

class HashManager {
	Hash** hashes;
	uint64_t hash_count;
	static bool EqualChars(const char*, const char*);
public:
	HashManager();
	~HashManager();
	Hash*& operator[](const char*);
	void print_hashes(const char*);
};

