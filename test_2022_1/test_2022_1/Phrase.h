#pragma once
#include <cstdint>
#include <iostream>

class Phrase {
	char** words;
	uint64_t word_count;
	static uint64_t Length(const char*);
	static bool FindChar(const char*, const char&);
	static bool IsAlNumSign(const char&);
public:
	Phrase(const char*);
	~Phrase();
	operator int();
	char*& operator [] (const uint64_t&);
	uint64_t CountLetter(const char&);
	uint64_t CountLetter(const uint64_t&, const char&);
	char*& GetLongestWord();
	uint64_t CountVowels();
};

