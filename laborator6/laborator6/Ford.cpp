#include "Ford.h"

const char* Ford::GetName() {
	return "Ford";
}
double Ford::GetFuelCapacity() {
	return 72;
}
double Ford::GetFuelConsumption() {
	return 0.084;
}
double Ford::GetAverageSpeed(Weather weather) {
	if (weather == Weather::Rain) {
		return 155;
	}
	else if (weather == Weather::Sunny) {
		return 175;
	}
	else if (weather == Weather::Snow) {
		return 140;
	}
}