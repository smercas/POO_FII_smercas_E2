#include <iostream>
#include <cstdint>
#include "Node.h"
#include "List.h"
#include "Map.h"

int main()
{
	Map<int, const char*> f;
	f[10] = "lol";
	Map<int, const char*> m;	// m[4] will be the 0-th position in the bucket array if you use a hash
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	//std::cout << std::boolalpha << m.Includes(f);
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n"
			, index, key, value);
	}
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n"
			, index, key, value);
	}
	return 0;
}