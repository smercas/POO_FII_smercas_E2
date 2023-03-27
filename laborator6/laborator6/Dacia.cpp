#include "Dacia.h"

const char* Dacia::GetName() {
	return "Dacia";
}
double Dacia::GetFuelCapacity() {
	return 50;
}
double Dacia::GetFuelConsumption() {
	return 0.055;
}
double Dacia::GetAverageSpeed(Weather weather) {
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