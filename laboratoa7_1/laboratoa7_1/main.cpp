#include <iostream>
#include <cstdint>

long double operator"" _Kelvin(long double value) {
	return value + 273.15;
}
long double operator"" _Kelvin_to_Celsius(long double value) {
	return value + 273.15;
}
long double operator"" _Celsius_to_Kelvin(long double value) {
	return value - 273.15;
}
long double operator"" _Fahrenheit(long double value) {
	return (value * 1.8) + 32;
}
long double operator"" _Fahrenheit_to_Celsius(long double value) {
	return (value * 1.8) + 32;
}
long double operator"" _Celsius_to_Fahrenheit(long double value) {
	return (value - 32) / 1.8;
}

int main() {
	printf("Kelvin: %Lf --> Celsius: %Lf\n", 300., 300._Kelvin_to_Celsius);
	printf("Fahrenheit: %Lf --> Celsius: %Lf\n", 120., 120._Fahrenheit_to_Celsius);
	return 0;
}