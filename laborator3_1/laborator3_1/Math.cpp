#include <iostream>
#include <stdarg.h>
#include "Math.h"
using namespace std;

int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b, int c) {
	return a + b + c;
}
double Math::Add(double a, double b) {
	return a + b;
}
double Math::Add(double a, double b, double c) {
	return a + b + c;
}
int Math::Mul(int a, int b) {
	return a * b;
}
int Math::Mul(int a, int b, int c) {
	return a * b * c;
}
double Math::Mul(double a, double b) {
	return a * b;
}
double Math::Mul(double a, double b, double c) {
	return a * b * c;
}
/*
template<typename first, typename... second_to_last>
int Math::Add(first a, second_to_last... b) {
	return a + Add(b...);
}
/**/
//defining these methods here gives me a LNK2019 error, I blame it on templates
int Math::Add(int count, ...) {
	int sum = 0;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++) {
		sum = sum + va_arg(vl, int);
	}
	va_end(vl);
	return sum;
}
void charAddition(char& s, char a, char b, bool& co) {
	s = a + b + co - '0';
	if (s > '9') {
		s = s - 10;
		co = true;
	}
	else {
		co = false;
	}
}
char* Math::Big_Numbers_Add(const char* a, const char* b) {
	bool carryover = false;
	if (strlen(a) < strlen(b)) {
		const char* aux = a;
		a = b;
		b = aux;
	}
	char* sum = (char*)malloc(sizeof(char) * (strlen(a) + 1));
	*(sum + strlen(a)) = '\0';
	for (unsigned i = 1; i <= strlen(b); i++) {
		charAddition(*(sum + strlen(sum) - i), *(a + strlen(a) - i), *(b + strlen(b) - i), carryover);
	}
	for (unsigned i = strlen(b) + 1; i <= strlen(a); i++) {
		charAddition(*(sum + strlen(sum) - i), *(a + strlen(a) - i), '0', carryover);
	}
	if (carryover) {
		sum = (char*)realloc(sum, sizeof(char) * (strlen(sum) + 2));
		for (unsigned i = strlen(sum) + 1; i > 0; i--) {
			*(sum + i) = *(sum + i - 1);
		}
		*sum = '1';
	}
	return sum;
}
char* Math::Add(const char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		return nullptr;
	}
	char* result = (char*)malloc(sizeof(char) * (strlen(a) + strlen(b) + 1));
	for (int i = 0; i < strlen(a); i++) {
		*(result + i) = *(a + i);
	}
	for (int i = 0; i <= strlen(b); i++) {
		*(result + strlen(a) + i) = *(b + i);
	}
	return result;
}