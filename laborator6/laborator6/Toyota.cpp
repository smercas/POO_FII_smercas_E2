#include "Toyota.h"

const char* Toyota::GetName() {
	return "Toyota";
}
double Toyota::GetFuelCapacity() {
	return 50;
}
double Toyota::GetFuelConsumption() {
	return 0.06;
}
double Toyota::GetAverageSpeed(Weather weather) {
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