#pragma once
#include <iostream>
#include <cstdint>

#define CONSTRUCTOR_BAD_VALUE_WARNING printf("WARNING: The recieved value can't be assigned to number \"%s\", so the class instance number will be set to \"0\".\n", value)
#define HEAP_ALLOCATION_FAILURE_ERROR printf("ERROR: There's no room for the array in the heap.\n")
#define ADD_SUB_NULLPTR_WARNING printf("ERROR: At least one of the recieved pointers is null (%p, %p), method call will return nullptr.\n", a, b)
#define BASE_MIN 2
#define BASE_MAX 16
#define mns BASE_MAX
#define SHOW_C_D_M_MESSAGES false

class Number {
	static const char c[18];
	static const uint8_t u[256];
	char* number;
	uint8_t base;
	char sign;
	void chgSign(char&);
	static char oppSign(char);
	Number();
	explicit Number(char*, uint8_t, char = '+');
	void InitNumber(const char*);
	static char* Conv_Int64_T_To_Char(const int64_t&, uint8_t = 10);
	static void ExtendCharArrayLeft(char*&, char);
	static void CharAdd(char&, char, char, bool&, uint8_t);
	static char* CharArrayAdd(const char*, const char*, uint8_t);
	static void RemoveZeroesLeft(char*&);
	static void CharSub(char&, char, char, bool&, uint8_t);
	static std::tuple<char*, char> CharArraySub(const char*, const char*, uint8_t);
	static char* CharArrayMul(const char*, const char*, uint8_t);
	static void CharArraySub_DivHelper(char*&, const char*, uint8_t);
	static std::tuple<Number, Number> CharArrayDiv(const Number&, const Number&, uint8_t);
	static std::tuple<Number, Number> QRDiv(const Number&, const Number&, uint8_t);
	static uint8_t Conv_Char_To_Uint8_T(const char*);
	void SwitchBaseTo10();
	static void ExtendCharArrayRight(char*&, char);
	void SwitchBaseFrom10(uint8_t);
public:
	//constructors
	Number(const char*, uint8_t, char = '+'); //where base is between 2 and 16
	Number(const int64_t&); //base'll always be 10
	Number(const Number&);
	Number(Number&&) noexcept;

	//destructor
	~Number();

	//assignment operator
	Number& operator= (Number&&) noexcept;
	Number& operator= (Number&);
	Number& operator= (int64_t);
	Number& operator= (const char*); //this looks like a horrible idea


	//unary arithmetic operators
	Number abs () const;
	char& operator[] (uint64_t) const;
	Number operator+ () const;
	Number operator- () const;
	Number operator-- ();
	Number operator-- (int);

	//binary arithmetic operators
	Number operator+ (const Number&) const;
	Number operator+ (const int64_t&) const;
	friend Number operator+ (const int64_t&, const Number&);

	Number& operator+= (const Number&);
	Number& operator+= (const int64_t&);

	Number operator- (const Number&) const;
	Number operator- (const int64_t&) const;
	friend Number operator- (const int64_t&, const Number&);

	Number& operator-= (const Number&);
	Number& operator-= (const int64_t&);

	Number operator* (const Number&) const;
	Number operator* (const int64_t&) const;
	friend Number operator* (const int64_t&, const Number&);

	Number& operator*= (const Number&);
	Number& operator*= (const int64_t&);

	Number operator/ (const Number&) const;
	Number operator/ (const int64_t&) const;
	friend Number operator/ (const int64_t&, const Number&);

	Number& operator/= (const Number&);
	Number& operator/= (const int64_t&);

	Number operator% (const Number&) const;
	Number operator% (const int64_t&) const;
	friend Number operator% (const int64_t&, const Number&);

	Number& operator%= (const Number&);
	Number& operator%= (const int64_t&);

	//relational operators
	bool operator== (const Number&) const;
	bool operator== (const int64_t&) const;
	friend bool operator== (const int64_t&, const Number&);

	bool operator< (const Number&) const;
	bool operator< (const int64_t&) const;
	friend bool operator< (const int64_t&, const Number&);

	bool operator> (const Number&) const;
	bool operator> (const int64_t&) const;
	friend bool operator> (const int64_t&, const Number&);

	bool operator!= (const Number&) const;
	bool operator!= (const int64_t&) const;
	friend bool operator!= (const int64_t&, const Number&);

	bool operator>= (const Number&) const;
	bool operator>= (const int64_t&) const;
	friend bool operator>= (const int64_t&, const Number&);

	bool operator<= (const Number&) const;
	bool operator<= (const int64_t&) const;
	friend bool operator<= (const int64_t&, const Number&);


	//add operators and copy/move constructor
	void SwitchBase(uint8_t);
	void Print();
	uint64_t GetDigitsCount(); //returns the number of digits for the current number
	uint8_t GetBase(); //returns the current base
};