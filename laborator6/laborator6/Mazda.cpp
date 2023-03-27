#include "Mazda.h"

const char* Mazda::GetName() {
	return "Mazda";
}
double Mazda::GetFuelCapacity() {
	return 50;
}
double Mazda::GetFuelConsumption() {
	return 0.067;
}
double Mazda::GetAverageSpeed(Weather weather) {
	if (weather == Weather::Rain) {
		return 160;
	}
	else if (weather == Weather::Sunny) {
		return 180;
	}
	else if (weather == Weather::Snow) {
		return 145;
	}
}