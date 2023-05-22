#pragma once
#include <cstdint>
#include <functional>

template<typename T, class lt = std::less<T>>
class Sort {
	static bool bubble_sort(const T& value[], uint64_t length) {
		uint64_t i, j;
		i = 0;
		while (i < length) {
			j = i;
			while (j < length) {
				if (!lt{}(value[i], value[j])) {

				}
				++j;
			}
			++i;
		}
	}
};
