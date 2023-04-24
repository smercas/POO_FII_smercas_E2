#include "Phrase.h"

uint64_t Phrase::Length(const char* word) {
	uint64_t result = 0;
	while (word[result] != '\0') {
		++result;
	}
	return result;
}

bool Phrase::FindChar(const char* seq, const char& c) {
	for (uint64_t i = 0; seq[i] != '\0'; ++i) {
		if (seq[i] == c) {
			return true;
		}
	}
	return false;
}

bool Phrase::IsAlNumSign(const char& c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')
		|| c == '+' || c == '-' || c == '*' || c == '/';
}

Phrase::Phrase(const char* phrase) {
	this->word_count = 0;
	for (uint64_t i = 0; phrase[i] != '\0'; ++i) {
		if (Phrase::IsAlNumSign(phrase[i])) {
			uint64_t j = i;
			while (IsAlNumSign(phrase[j]) ) {
				++j;
			}
			++this->word_count;
			i = j;
		}
	}
	this->words = new char* [this->word_count];
	this->word_count = 0;
	for (uint64_t i = 0; phrase[i] != '\0'; ++i) {
		if (Phrase::IsAlNumSign(phrase[i])) {
			uint64_t j = i;
			while (IsAlNumSign(phrase[j])) {
				++j;
			}
			this->words[this->word_count] = new char[j - i + 1];
			for (uint64_t k = i; k < j; ++k) {
				this->words[this->word_count][k - i] = phrase[k];
			}
			this->words[this->word_count][j - i] = '\0';
			++this->word_count;
			i = j;
		}
	}
}

Phrase::~Phrase() {
	for (uint64_t i = 0; i < this->word_count; ++i) {
		delete[] this->words[i];
	}
	delete[] this->words;
	this->words = nullptr;
	this->word_count = 0;
}

Phrase::operator int() {
	return this->word_count;
}

char*& Phrase::operator[](const uint64_t& index) {
	return this->words[index];
}

uint64_t Phrase::CountLetter(const char& c)
{
	uint64_t result = 0;
	for (uint64_t i = 0; i < this->word_count; ++i) {
		result = result + this->CountLetter(i, c);
	}
	return result;
}

uint64_t Phrase::CountLetter(const uint64_t& index, const char& c)
{
	uint64_t result = 0;
	for (uint64_t i = 0; this->words[index][i] != '\0'; ++i) {
		if (this->words[index][i] == c) {
			++result;
		}
	}
	return result;
}

char*& Phrase::GetLongestWord()
{
	uint64_t result = 0;
	for (uint64_t i = 0; i < this->word_count; ++i) {
		if (Phrase::Length(this->words[i]) > Phrase::Length(this->words[result])) {
			result = i;
		}
	}
	return this->words[result];
}

uint64_t Phrase::CountVowels()
{
	uint64_t result = 0;
	for (uint64_t i = 0; i < this->word_count; ++i) {
		for (uint64_t j = 0; this->words[i][j] != '\0'; ++j) {
			if (Phrase::FindChar("aeiouAEIOU", this->words[i][j])) {
				++result;
			}
		}
	}
	return result;
}
