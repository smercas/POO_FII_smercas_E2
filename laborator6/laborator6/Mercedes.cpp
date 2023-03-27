#include "Mercedes.h"

const char* Mercedes::GetName() {
	return "Mercedes";
}
double Mercedes::GetFuelCapacity() {
	return 52;
}
double Mercedes::GetFuelConsumption() {
	return 0.049;
}
double Mercedes::GetAverageSpeed(Weather weather) {
	if (weather == Weather::Rain) {
		return 150;
	}
	else if (weather == Weather::Sunny) {
		return 170;
	}
	else if (weather == Weather::Snow) {
		return 135;
	}
}