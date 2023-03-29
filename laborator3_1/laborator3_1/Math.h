#pragma once
class Math {
public:
	static int Add(int, int);
	static int Add(int, int, int);
	static double Add(double, double);
	static double Add(double, double, double);
	static int Mul(int, int);
	static int Mul(int, int, int);
	static double Mul(double, double);
	static double Mul(double, double, double);
	template<typename last = int>
	static last No_Count_Add(last b) {
		return b;
	}
	template<typename first = int, typename... second_to_last>
	static first No_Count_Add(first a, second_to_last... b) {
		return a + No_Count_Add(b...);
	} // sums up a list of integers
	static int Add(int, ...);
	static char* Big_Numbers_Add(const char*, const char*);
	static char* Add(const char*, const char*);
};